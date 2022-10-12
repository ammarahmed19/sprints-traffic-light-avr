/*
* TIMER.h
*
* Created: 9/18/2022 11:42:07 AM
*  Author: ammar
*/


#ifndef TIMER_H_
#define TIMER_H_

#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"

// registers
#include "TIMER_reg.h"

// helpers
#include "TIMER_private.h"
#include "TIMER_error.h"

/*PRESCALER TO START*/
/*
CS02	CS01	CS00	Description
0		0		0		No clock source (Timer/Counter stopped).
0		0		1		clkI/O/(No prescaling)
0		1		0		clkI/O/8 (From prescaler)
0		1		1		clkI/O/64 (From prescaler)
1		0		0		clkI/O/256 (From prescaler)
1		0		1		clkI/O/1024 (From prescaler)
1		1		0		External clock source on T0 pin. Clock on falling edge.
1		1		1		External clock source on T0 pin. Clock on rising edge
*/

extern EN_TIMER_Error_t TIMER_init(TIMER_obj timerobj);
extern EN_TIMER_Error_t TIMER_start(TIMER_obj timerobj, u8 tick);
extern EN_TIMER_Error_t TIMER_stop(TIMER_obj timerobj);
extern EN_TIMER_Error_t TIMER_Get_FlagStatus(TIMER_obj timerobj, u8 *Flag);
extern EN_TIMER_Error_t TIMER_Flag_Reset(TIMER_obj timerobj);
extern EN_TIMER_Error_t TIMER_Reset(TIMER_obj timerobj);
extern EN_TIMER_Error_t TIMER_Get_Ticktime(TIMER_obj timerobj, u8 *ticktime);
extern EN_TIMER_Error_t TIMER_SecDelay(TIMER_obj timerobj);



#endif /* TIMER_H_ */