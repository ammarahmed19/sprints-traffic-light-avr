/*
* DIO.c
*
* Created:
*  Author: ammar
*/

#include "DIO.h"


// GPIO PINS
extern EN_DIO_Error_t DIO_SetPinValue(u8 PortId , u8 PinId, u8 PinVal) {
	
	/* ERROR CHECKING */
	DIO_PORT_ERROR_CHECK(PortId);
	DIO_PIN_ERROR_CHECK(PinId);
	DIO_VALUE_ERROR_CHECK(PinVal);
	/*******************/
	
	/* IMPLEMENTATION */
	
	if (PinVal == HIGH)
	{
		switch (PortId)
		{
			case PORTA: SET_BIT(DIO_REG_PORTA,PinId); break;
			case PORTB: SET_BIT(DIO_REG_PORTB,PinId); break;
			case PORTC: SET_BIT(DIO_REG_PORTC,PinId); break;
			case PORTD: SET_BIT(DIO_REG_PORTD,PinId); break;
		}
		
	}
	else if (PinVal == LOW) {
		switch (PortId)
		{
			case PORTA: CLR_BIT(DIO_REG_PORTA,PinId); break;
			case PORTB: CLR_BIT(DIO_REG_PORTB,PinId); break;
			case PORTC: CLR_BIT(DIO_REG_PORTC,PinId); break;
			case PORTD: CLR_BIT(DIO_REG_PORTD,PinId); break;
		}
	}
	return DIO_OK;
	
	/****************/
}

extern EN_DIO_Error_t DIO_GetPinValue(u8 PortId, u8 PinId, u8* PinVal) {
	
	/* ERROR CHECKING */
	DIO_PORT_ERROR_CHECK(PortId);
	DIO_PIN_ERROR_CHECK(PinId);
	/*******************/
	
	/* IMPLEMENTATION */
	
	switch (PortId)
	{
		case PORTA: *PinVal = GET_BIT(DIO_REG_PINA,PinId); break;
		case PORTB: *PinVal = GET_BIT(DIO_REG_PINB,PinId); break;
		case PORTC: *PinVal = GET_BIT(DIO_REG_PINC,PinId); break;
		case PORTD: *PinVal = GET_BIT(DIO_REG_PIND,PinId); break;
	}
	
	return DIO_OK;
	
	/****************/
	
}

extern EN_DIO_Error_t DIO_SetPinDirection(u8 PortId, u8 PinId, u8 PinDir) {
	/* ERROR CHECKING */
	DIO_PORT_ERROR_CHECK(PortId);
	DIO_PIN_ERROR_CHECK(PinId);
	DIO_DIR_ERROR_CHECK(PinDir);
	/*******************/
	
	/* IMPLEMENTATION */
	
	if (PinDir == HIGH)
	{
		switch (PortId)
		{
			case PORTA: SET_BIT(DIO_REG_DDRA,PinId); break;
			case PORTB: SET_BIT(DIO_REG_DDRB,PinId); break;
			case PORTC: SET_BIT(DIO_REG_DDRC,PinId); break;
			case PORTD: SET_BIT(DIO_REG_DDRD,PinId); break;
		}
		
	}
	else if (PinDir == LOW) {
		switch (PortId)
		{
			case PORTA: CLR_BIT(DIO_REG_DDRA,PinId); break;
			case PORTB: CLR_BIT(DIO_REG_DDRB,PinId); break;
			case PORTC: CLR_BIT(DIO_REG_DDRC,PinId); break;
			case PORTD: CLR_BIT(DIO_REG_DDRD,PinId); break;
		}
	}
	return DIO_OK;
	
	/****************/
}

// GPIO PORTS
extern EN_DIO_Error_t DIO_SetPortDirection(u8 PortId, u8 PortDir) {
	/* ERROR CHECKING */
	DIO_PORT_ERROR_CHECK(PortId);
	DIO_DIR_ERROR_CHECK(PortDir);
	/*******************/
	
	/* IMPLEMENTATION */
	
	switch (PortId)
	{
		case PORTA: DIO_REG_DDRA = PortDir; break;
		case PORTB: DIO_REG_DDRB = PortDir; break;
		case PORTC: DIO_REG_DDRC = PortDir; break;
		case PORTD: DIO_REG_DDRD = PortDir; break;
	}
	
	return DIO_OK;
	
	/****************/
}

extern EN_DIO_Error_t DIO_SetPortValue(u8 PortId, u8 PortVal) {
	/* ERROR CHECKING */
	DIO_PORT_ERROR_CHECK(PortId);
	DIO_VALUE_ERROR_CHECK(PortVal);
	/*******************/
	
	/* IMPLEMENTATION */
	
	switch (PortId)
	{
		case PORTA: DIO_REG_PORTA = PortVal; break;
		case PORTB: DIO_REG_PORTB = PortVal; break;
		case PORTC: DIO_REG_PORTB = PortVal; break;
		case PORTD: DIO_REG_PORTD = PortVal; break;
	}
	
	return DIO_OK;
	
	/****************/
}