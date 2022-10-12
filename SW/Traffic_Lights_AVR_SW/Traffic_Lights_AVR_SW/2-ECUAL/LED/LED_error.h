/*
 * LED_error.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef LED_ERROR_H_
#define LED_ERROR_H_


#include "../../1-MCAL/DIO/DIO.h"
#include "../../1-MCAL/INTERRUPT/INTERRUPT.h"
#include "LED_private.h"

#define LED_PIN_ERROR_CHECK(PIN) if (PIN < PIN0 || PIN > PIN7) return LED_PIN_OUT_OF_RANGE
#define LED_PORT_ERROR_CHECK(PORT) if (PORT < PORTA || PORT > PORTD) return LED_PORT_OUT_OF_RANGE
#define LED_MODE_ERROR_CHECK(VAL) if (VAL < LED_OFF || VAL > LED_ON) return LED_INVALID_MODE


#endif /* LED_ERROR_H_ */