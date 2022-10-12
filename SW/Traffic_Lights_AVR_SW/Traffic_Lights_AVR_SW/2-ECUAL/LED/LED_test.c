/*
 * LED_test.c
 *
 * Created: 
 *  Author: ammar
 */ 

#include "LED_test.h"

EN_LED_Error_t LED_test() {
	u8 LocError;
	LED_obj LocLED = {
		.port = PORTA
		.pin = PIN0
		.mode = HIGH;
	}
	LocError = LED_init(LocLED);
	ERROR_CHECK_RETURN(LocError);
	
	LocError = LED_write(LocLED);
	ERROR_CHECK_RETURN(LocError);
	
	return LED_OK;
}