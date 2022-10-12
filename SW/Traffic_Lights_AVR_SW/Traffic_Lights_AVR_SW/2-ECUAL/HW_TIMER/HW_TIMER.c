/*
* HW_TIMER.c
*
* Created:
*  Author: ammar
*/

#include "HW_TIMER.h"

EN_HWTIMER_Error_t HW_Timer_init(u8 TimerId, u8 interrupt) {
	u8 LocErrorStatus;
	TIMER_obj LocTimerObj;
	
	// ERROR CHECKING
	HW_TIMER_ID_ERROR_CHECK(TimerId);
	HW_TIMER_INTERRUPT_MODE_ERROR_CHECK(interrupt);
	
	// ENABLE GLOBAL INTERRUPTS
	if (interrupt == HW_TIMER_INTERRUPT_MODE) sei();
	
	// INITIALIZE TIMER
	LocTimerObj.timerId = TimerId;
	LocTimerObj.Ticks_Mode = TIMER_TIMER_MODE;
	LocTimerObj.Mode = TIMER_NORMAL_MODE;
	LocTimerObj.Interrupt_Mode = interrupt;
	LocTimerObj.Timer_Psc = TIMER_F_CPU_CLOCK_1024_TIMER;
	
	LocErrorStatus = TIMER_init(LocTimerObj);
	HW_TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
	
	return HW_TIMER_OK;
}

EN_HWTIMER_Error_t HW_Timer_start(u8 TimerId) {
	u8 LocErrorStatus;
	
	TIMER_obj LocTimerObj;
	// INITIALIZE TIMER
	LocTimerObj.timerId = TimerId;
	LocTimerObj.Ticks_Mode = TIMER_TIMER_MODE;
	LocTimerObj.Mode = TIMER_NORMAL_MODE;
	LocTimerObj.Timer_Psc = TIMER_F_CPU_CLOCK_1024_TIMER;
	
	LocErrorStatus = TIMER_start(LocTimerObj, TIMER_OVERFLOW);
	HW_TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
	
	return HW_TIMER_OK;
}

EN_HWTIMER_Error_t HW_Timer_reset(u8 TimerId) {
	u8 LocErrorStatus;
	
	TIMER_obj LocTimerObj;
	// INITIALIZE TIMER
	LocTimerObj.timerId = TimerId;
	
	LocErrorStatus = TIMER_Reset(LocTimerObj);
	HW_TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
	
	return HW_TIMER_OK;
}

EN_HWTIMER_Error_t HW_Timer_wait(u8 TimerId, u8 secs) {
	u8 LocErrorStatus;
	
	// INITIALIZE TIMER
	TIMER_obj LocTimerObj;
	LocTimerObj.timerId = TimerId;
	LocTimerObj.Ticks_Mode = TIMER_TIMER_MODE;
	LocTimerObj.Mode = TIMER_NORMAL_MODE;
	LocTimerObj.Timer_Psc = TIMER_F_CPU_CLOCK_1024_TIMER;
	
	for (int i = 0; i < secs; i++) {
		LocErrorStatus = TIMER_SecDelay(LocTimerObj);
		HW_TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
	}
	
	return HW_TIMER_OK;
}