/*
 * DIO.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef DIO_H_
#define DIO_H_

// LIBRARY INCLUDE
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/STD_TYPES.h"

// REGISTER INCLUDE
#include "DIO_reg.h"

// TYPES + HELPERS INCLUDE
#include "DIO_error.h"
#include "DIO_private.h"

// GPIO PINS
extern EN_DIO_Error_t DIO_SetPinValue(u8 PortId , u8 PinId, u8 PinVal);

extern EN_DIO_Error_t DIO_GetPinValue(u8 PortId, u8 PinId, u8* PinVal);

extern EN_DIO_Error_t DIO_SetPinDirection(u8 PortId, u8 PinId, u8 PinDir);

// GPIO PORTS
extern EN_DIO_Error_t DIO_SetPortDirection(u8 PortId, u8 PortDir);

extern EN_DIO_Error_t DIO_SetPortValue(u8 PortId, u8 PortVal);

#endif /* DIO_H_ */