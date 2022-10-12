/*
* SWITCH.c
*
* Created:
*  Author: ammar
*/

#include "SWITCH.h"

extern EN_SWITCH_Error_t SWITCH_init(SWITCH_obj switchobj) {
	u8 LocErrorStatus = 0;
	/* ERROR CHECKING */
	SWITCH_PORT_ERROR_CHECK(switchobj.port);
	SWITCH_PIN_ERROR_CHECK(switchobj.pin);
	SWITCH_PULLUP_ERROR_CHECK(switchobj.pullup);
	SWITCH_INTERRUPT_MODE_ERROR_CHECK(switchobj.interrupt_mode);
	if (switchobj.interrupt_mode == SWITCH_EXINT_MODE) SWITCH_INTERRUPT_PIN_ERROR_CHECK(switchobj.port, switchobj.pin);
	///////////////////
	
	LocErrorStatus = DIO_SetPinDirection(switchobj.port, switchobj.pin, INPUT);
	if (LocErrorStatus != DIO_OK) return SWITCH_INTERNAL_ERROR;
	
	LocErrorStatus = DIO_SetPinValue(switchobj.port, switchobj.pin, switchobj.pullup);
	if (LocErrorStatus != DIO_OK) return SWITCH_INTERNAL_ERROR;
	
	if (switchobj.interrupt_mode == SWITCH_EXINT_MODE) {
		// ENABLE GLOBAL INTERRUPTS
		EXINT_EnableGlobalInterrupts();
		
		if (switchobj.port == EXINT0_PORT && switchobj.pin == EXINT0_PIN) {
			LocErrorStatus = EXINT_InitInterrupt(EXINT0);
			if (LocErrorStatus != EXINT_OK) return SWITCH_INTERNAL_ERROR;
		}
		else if (switchobj.port == EXINT1_PORT && switchobj.pin == EXINT1_PIN) {
			LocErrorStatus = EXINT_InitInterrupt(EXINT1);
			if (LocErrorStatus != EXINT_OK) return SWITCH_INTERNAL_ERROR;
		}
		else if (switchobj.port == EXINT2_PORT && switchobj.pin == EXINT2_PIN) {
			LocErrorStatus = EXINT_InitInterrupt(EXINT2);
			if (LocErrorStatus != EXINT_OK) return SWITCH_INTERNAL_ERROR;
		}
		else {
			return SWITCH_INTERNAL_ERROR;
		}
	}
	
	return SWITCH_OK;
	
}
extern EN_SWITCH_Error_t SWITCH_read(SWITCH_obj* switchobj) {
	u8 LocErrorStatus = 0;
	
	/* ERROR CHECKING */
	SWITCH_PORT_ERROR_CHECK((*switchobj).port);
	SWITCH_PIN_ERROR_CHECK((*switchobj).pin);
	SWITCH_PULLUP_ERROR_CHECK((*switchobj).pullup);
	SWITCH_INTERRUPT_MODE_ERROR_CHECK((*switchobj).interrupt_mode);
	if ((*switchobj).interrupt_mode == SWITCH_EXINT_MODE) SWITCH_INTERRUPT_PIN_ERROR_CHECK((*switchobj).port, (*switchobj).pin);
	///////////////////
	
	u8 val;
	
	LocErrorStatus = DIO_GetPinValue((*switchobj).port, (*switchobj).pin, &val);
	if (LocErrorStatus != DIO_OK) return SWITCH_INTERNAL_ERROR;
	
	switchobj->val = val;
	
	return SWITCH_OK;
}
