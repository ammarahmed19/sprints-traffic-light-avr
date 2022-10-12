/*
 * HW_TIMER_private.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef HW_TIMER_PRIVATE_H_
#define HW_TIMER_PRIVATE_H_

#include "../../0-LIB/STD_TYPES.h"

#define HW_TIMER0 0
#define HW_TIMER1 1
#define HW_TIMER2 2

#define HW_TIMER_POLLING_MODE 0
#define HW_TIMER_INTERRUPT_MODE 1

typedef enum EN_HWTIMER_Error_t
{
	HW_TIMER_OK, HW_TIMER_ID_OUT_OF_RANGE, HW_TIMER_INTERRUPT_MODE_OUT_OF_RANGE ,HW_TIMER_INTERNAL_ERROR
}EN_HWTIMER_Error_t;



#endif /* HW_TIMER_PRIVATE_H_ */