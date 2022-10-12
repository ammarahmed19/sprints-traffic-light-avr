/*
 * HW_TIMER.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef HW_TIMER_H_
#define HW_TIMER_H_

#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/STD_TYPES.h"

#include "../../1-MCAL/INTERRUPT/INTERRUPT.h"
#include "../../1-MCAL/TIMER/TIMER.h"

#include "HW_TIMER_private.h"
#include "HW_TIMER_error.h"

EN_HWTIMER_Error_t HW_Timer_init(u8 TimerId, u8 interrupt);
EN_HWTIMER_Error_t HW_Timer_start(u8 TimerId);
EN_HWTIMER_Error_t HW_Timer_reset(u8 TimerId);
EN_HWTIMER_Error_t HW_Timer_wait(u8 TimerId, u8 secs);



#endif /* HW_TIMER_H_ */