/*
 * HW_TIMER_error.h
 *
 * Created: 
 *  Author: ammar
 */ 


#ifndef HW_TIMER_ERROR_H_
#define HW_TIMER_ERROR_H_

#include "HW_TIMER_private.h"

#define HW_TIMER_ID_ERROR_CHECK(id) if (id > HW_TIMER2 || id < HW_TIMER0) return HW_TIMER_ID_OUT_OF_RANGE
#define HW_TIMER_INTERRUPT_MODE_ERROR_CHECK(mode) if (mode > HW_TIMER_INTERRUPT_MODE || mode < HW_TIMER_POLLING_MODE) return HW_TIMER_INTERRUPT_MODE_OUT_OF_RANGE
#define HW_TIMER_INTERNAL_ERROR_CHECK(status) if (status != 0) return HW_TIMER_INTERNAL_ERROR


#endif /* HW_TIMER_ERROR_H_ */