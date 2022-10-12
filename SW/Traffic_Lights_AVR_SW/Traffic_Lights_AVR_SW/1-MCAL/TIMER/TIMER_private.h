/*
 * TIMER_types.h
 *
 * Created: 
 *  Author: ammar
 */ 


#ifndef TIMER_TYPES_H_
#define TIMER_TYPES_H_

#include "../../0-LIB/STD_TYPES.h"

// TIMER ID
#define TIMER_TIMER0 0
#define TIMER_TIMER1 1
#define TIMER_TIMER2 2


// TIMER MODE
#define TIMER_TIMER_MODE 0
#define TIMER_COUNTER_MODE 1

// NORMAL OR CTC MODE
#define TIMER_NORMAL_MODE 0
#define TIMER_CTC_MODE 1
#define TIMER_FAST_PWM_MODE 2
#define TIMER_PHASE_CORRECT_PWM_MODE 3

// PRESCALAR
#define TIMER_NO_CLOCK_TIMER     					0
#define TIMER_F_CPU_CLOCK_TIMER   					1
#define TIMER_F_CPU_CLOCK_8_TIMER 					2
#define TIMER_F_CPU_CLOCK_64_TIMER					3
#define TIMER_F_CPU_CLOCK_256_TIMER					4
#define TIMER_F_CPU_CLOCK_1024_TIMER				5
#define TIMER_F_EXTERNAL_CLOCK_FALLING_TIMER		6
#define TIMER_F_EXTERNAL_CLOCK_RISING_TIMER			7

// OVERFLOW MODE
#define TIMER_POLLING      0
#define TIMER_INTERRUPT    1

// PWM Modes
#define TIMER_PWM_NORMAL 0
#define TIMER_NON_INVERTED 1
#define TIMER_INVERTED 1

#define TIMER_OVERFLOW 255
#define TIMER1_OVERFLOW 65536

#define TIMER_MAX_TICK 255
#define TIMER1_MAX_TICK 65536

// INTERRUPT VECTORS
#define TIMER_TIMER2_COMP_vect __vector_4
#define TIMER_TIMER2_OVF_vect __vector_5
#define TIMER_TIMER1_CAPT_vect __vector_6
#define TIMER_TIMER1_COMPA_vect __vector_7
#define TIMER_TIMER1_COMPB_vect __vector_8
#define TIMER_TIMER1_OVF_vect __vector_9
#define TIMER_TIMER0_COMP_vect __vector_10
#define TIMER_TIMER0_OVF_vect __vector_11

typedef struct TIMER_obj
{
	u8 timerId;
	u8 Mode;			/* timer or counter */
	u8 Ticks_Mode;    /* normal Mode or CTC Mode */
	u8 Timer_Psc;     /*Timer Prescaler Based on DataSheet No prescaler or /8 or /64 or .....*/
	u8 Interrupt_Mode; /*Timer Overflow Mode Interrupt or polling */
	u8 PWM_Mode;		/* Inverted or non inverted mode */
}TIMER_obj;

typedef enum EN_TIMER_Error_t
{
	TIMER_OK, TIMER_ID_OUT_OF_RANGE, TIMER_MODE_OUT_OF_RANGE, TIMER_TICKS_MODE_OUT_OF_RANGE, TIMER_PSC_OUT_OF_RANGE, TIMER_INTERRUPT_MODE_OUT_OF_RANGE, TIMER_PWM_MODE_OUT_OF_RANGE, TIMER_INTERNAL_ERROR
}EN_TIMER_Error_t;

#endif /* TIMER_TYPES_H_ */