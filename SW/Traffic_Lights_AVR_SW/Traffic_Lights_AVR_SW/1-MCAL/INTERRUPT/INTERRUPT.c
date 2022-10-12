/*
* INTERRUPT.c
*
* Created:
*  Author: ammar
*/

#include "INTERRUPT.h"

extern void EXINT_EnableGlobalInterrupts() {
	sei();
}

extern void EXINT_DisableGlobalInterrupts() {
	cli();
}

EN_EXINT_Error_t EXINT_InitInterrupt(u8 EXINT_ID) {
	EXINT_ID_ERROR_CHECK(EXINT_ID);
	switch (EXINT_ID) {
		case EXINT0:
		/*Set falling edge*/
		SET_BIT(EXINT_REG_MCUCR,EXINT_REG_MCUCR_ISC01);
		CLR_BIT(EXINT_REG_MCUCR,EXINT_REG_MCUCR_ISC00);

		/*Enable Interrupt for EXINT0*/
		SET_BIT(EXINT_REG_GICR,EXINT_REG_GICR_INT0);
		break;
		case EXINT1:
		/*Set fallin edge*/
		SET_BIT(EXINT_REG_MCUCR,EXINT_REG_MCUCR_ISC01);
		CLR_BIT(EXINT_REG_MCUCR,EXINT_REG_MCUCR_ISC00);

		/*Enable Interrupt for EXINT1*/
		SET_BIT(EXINT_REG_GICR,EXINT_REG_GICR_INT1);
		break;
		
		case EXINT2:
		/*Set falling edge*/
		SET_BIT(EXINT_REG_MCUCSR,EXINT_REG_MCUCSR_INT2);

		/*Enable Interrupt for EXINT2*/
		CLR_BIT(EXINT_REG_GICR,EXINT_REG_GICR_INT2);
		break;
	}
	return EXINT_OK;
}