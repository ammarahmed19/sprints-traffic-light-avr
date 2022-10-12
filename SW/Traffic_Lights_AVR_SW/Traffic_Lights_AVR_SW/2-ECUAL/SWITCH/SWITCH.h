/*
 * switch.h
 *
 * Created: 9/18/2022 3:39:45 PM
 *  Author: ammar
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../1-MCAL/DIO/DIO.h"
#include "../../1-MCAL/INTERRUPT/INTERRUPT.h"
#include "SWITCH_private.h"
#include "SWITCH_error.h"

extern EN_SWITCH_Error_t SWITCH_init(SWITCH_obj switchobj);
extern EN_SWITCH_Error_t SWITCH_read(SWITCH_obj *switchobj);


#endif /* SWITCH_H_ */