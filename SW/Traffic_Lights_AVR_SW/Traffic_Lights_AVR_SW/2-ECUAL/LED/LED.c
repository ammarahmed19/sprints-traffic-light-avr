/*
* LED.c
*
* Created:
*  Author: ammar
*/

#include "LED.h"

extern EN_LED_Error_t LED_init(LED_obj ledobj) {
	LED_PIN_ERROR_CHECK(ledobj.pin);
	LED_PORT_ERROR_CHECK(ledobj.port);
	
	DIO_SetPinDirection(ledobj.port, ledobj.pin, OUTPUT);
	DIO_SetPinValue(ledobj.port, ledobj.pin, LOW);
	return LED_OK;
}

extern EN_LED_Error_t LED_write(LED_obj ledobj) {
	LED_PIN_ERROR_CHECK(ledobj.pin);
	LED_PORT_ERROR_CHECK(ledobj.port);
	LED_MODE_ERROR_CHECK(ledobj.mode);
	
	DIO_SetPinValue(ledobj.port, ledobj.pin, ledobj.mode);
	return LED_OK;
}