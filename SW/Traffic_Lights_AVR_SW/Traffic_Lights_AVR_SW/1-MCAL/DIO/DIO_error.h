/*
 * DIO_error.h
 *
 * Created: 
 *  Author: ammar
 */ 


#ifndef DIO_HELPER_H_
#define DIO_HELPER_H_

#include "DIO_private.h"

#define DIO_PIN_ERROR_CHECK(PIN) if (PIN < PIN0 || PIN > PIN7) return DIO_PIN_OUT_OF_RANGE
#define DIO_PORT_ERROR_CHECK(PORT) if (PORT < PORTA || PORT > PORTD) return DIO_PORT_OUT_OF_RANGE
#define DIO_VALUE_ERROR_CHECK(VAL) if (VAL < LOW || VAL > HIGH) return DIO_INVALID_VALUE
#define DIO_DIR_ERROR_CHECK(DIR) if (DIR < LOW || DIR > HIGH) return DIO_INVALID_DIRECTION


#endif /* DIO_HELPER_H_ */