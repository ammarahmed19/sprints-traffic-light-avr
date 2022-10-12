/*
 * DIO_private.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

// PORT
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

// PIN
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

// DIRECTIONS
#define INPUT  0
#define OUTPUT 1
#define PULLUP 1

// VALUES
#define HIGH   1
#define LOW    0


typedef enum EN_DIO_Error_t
{
	DIO_OK, DIO_PIN_OUT_OF_RANGE, DIO_PORT_OUT_OF_RANGE, DIO_INVALID_VALUE, DIO_INVALID_DIRECTION
}EN_DIO_Error_t;


#endif /* DIO_TYPES_H_ */