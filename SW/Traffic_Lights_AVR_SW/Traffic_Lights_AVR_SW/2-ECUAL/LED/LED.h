/*
 * LED.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../1-MCAL/DIO/DIO.h"
#include "LED_private.h"
#include "LED_error.h"


extern EN_LED_Error_t LED_init(LED_obj ledobj);	
extern EN_LED_Error_t LED_write(LED_obj ledobj);

#endif /* LED_H_ */