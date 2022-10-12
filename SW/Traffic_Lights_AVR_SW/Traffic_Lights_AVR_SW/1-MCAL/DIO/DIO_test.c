/*
 * DIO_test.c
 *
 * Created:
 *  Author: ammar
 */ 

#include "DIO_test.h"

EN_DIO_Error_t DIO_test() {
	EN_DIO_Error_t LocError;
	 
	 LocError = DIO_SetPortDirection(PORTA, INPUT);
	 ERROR_CHECK_RETURN(LocError);
	 
	 LocError = DIO_SetPinDirection(PORTA, PIN0, OUTPUT);
	 ERROR_CHECK_RETURN(LocError);
	 
	 LocError = DIO_SetPortValue(PORTA, OUTPUT);
	 
	 LocError = DIO_SetPinValue(PORTA, PIN0, HIGH);
	 ERROR_CHECK_RETURN(LocError);
	 
	 return DIO_OK;
}