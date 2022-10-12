/*
* TIMER.c
*
* Created:
*  Author: ammar
*/

#include "TIMER.h"

extern EN_TIMER_Error_t TIMER_init(TIMER_obj timerobj) {
	switch(timerobj.timerId) {
		case TIMER_TIMER0: {
			switch(timerobj.Ticks_Mode)
			{
				case TIMER_NORMAL_MODE:
				{
					CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM00);
					CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM01);
					if(timerobj.Interrupt_Mode == TIMER_INTERRUPT)
					{
						SET_BIT(TIMER_REG_TIMSK, TIMER_REG_TOIE0);
					}
					break;
				}
				case TIMER_CTC_MODE:
				{
					CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM00);
					SET_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM01);
					if(timerobj.Interrupt_Mode == TIMER_INTERRUPT)
					{
						SET_BIT(TIMER_REG_TIMSK, TIMER_REG_OCIE0);
					}
					break;
				}
				case TIMER_FAST_PWM_MODE:
				{
					SET_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM00);
					SET_BIT(TIMER_REG_TCCR0,TIMER_REG_WGM01);
					if(timerobj.PWM_Mode == TIMER_PWM_NORMAL)
					{
						CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_COM00);
						CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_COM01);
						break;
					}
					else if(timerobj.PWM_Mode == TIMER_NON_INVERTED)
					{
						CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_COM00);
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM01);
						break;
					}
					else if(timerobj.PWM_Mode == TIMER_INVERTED)
					{
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM01);
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM00);
						break;
					}
					else
					{
						return TIMER_PWM_MODE_OUT_OF_RANGE;
					}
					break;
				}
				case TIMER_PHASE_CORRECT_PWM_MODE:
				{
					SET_BIT(TIMER_REG_TCCR0, TIMER_REG_WGM00);
					CLR_BIT(TIMER_REG_TCCR0, TIMER_REG_WGM01);
					
					if (timerobj.PWM_Mode == TIMER_PWM_NORMAL)
					{
						CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_COM00);
						CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_COM01);
						break;
					}
					else if (timerobj.PWM_Mode == TIMER_NON_INVERTED)
					{
						CLR_BIT(TIMER_REG_TCCR0, TIMER_REG_COM00);
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM01);
						break;
					}
					else if (timerobj.PWM_Mode == TIMER_INVERTED)
					{
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM01);
						SET_BIT(TIMER_REG_TCCR0, TIMER_REG_COM00);
						break;
					}
					else
					{
						return TIMER_PWM_MODE_OUT_OF_RANGE;
					}
					
					break;
				}
				default: return TIMER_MODE_OUT_OF_RANGE;
			}
			break;
		}
		
		case TIMER_TIMER1:
		break;
		
		case TIMER_TIMER2: {
			switch(timerobj.Ticks_Mode)
			{
				case TIMER_NORMAL_MODE:
				{
					CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM20);
					CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM21);
					if(timerobj.Interrupt_Mode == TIMER_INTERRUPT)
					{
						SET_BIT(TIMER_REG_TIMSK, TIMER_REG_TOIE2);
					}
					break;
				}
				case TIMER_CTC_MODE:
				{
					CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM20);
					SET_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM21);
					if(timerobj.Interrupt_Mode == TIMER_INTERRUPT)
					{
						SET_BIT(TIMER_REG_TIMSK, TIMER_REG_OCIE2);
					}
					break;
				}
				case TIMER_FAST_PWM_MODE:
				{
					SET_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM20);
					SET_BIT(TIMER_REG_TCCR2,TIMER_REG_WGM21);
					if(timerobj.PWM_Mode == TIMER_PWM_NORMAL)
					{
						CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_COM20);
						CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_COM21);
						break;
					}
					else if(timerobj.PWM_Mode == TIMER_NON_INVERTED)
					{
						CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_COM20);
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM21);
						break;
					}
					else if(timerobj.PWM_Mode == TIMER_INVERTED)
					{
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM21);
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM20);
						break;
					}
					else
					{
						return TIMER_PWM_MODE_OUT_OF_RANGE;
					}
					break;
				}
				case TIMER_PHASE_CORRECT_PWM_MODE:
				{
					SET_BIT(TIMER_REG_TCCR2, TIMER_REG_WGM20);
					CLR_BIT(TIMER_REG_TCCR2, TIMER_REG_WGM21);
					
					if (timerobj.PWM_Mode == TIMER_PWM_NORMAL)
					{
						CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_COM20);
						CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_COM21);
						break;
					}
					else if (timerobj.PWM_Mode == TIMER_NON_INVERTED)
					{
						CLR_BIT(TIMER_REG_TCCR2, TIMER_REG_COM20);
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM21);
						break;
					}
					else if (timerobj.PWM_Mode == TIMER_INVERTED)
					{
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM21);
						SET_BIT(TIMER_REG_TCCR2, TIMER_REG_COM20);
						break;
					}
					else
					{
						return TIMER_PWM_MODE_OUT_OF_RANGE;
					}
					
					break;
				}
				default: return TIMER_MODE_OUT_OF_RANGE;
			}
			break;
		}
		
		default: return TIMER_ID_OUT_OF_RANGE;
	}

	return TIMER_OK;
}

extern EN_TIMER_Error_t TIMER_start(TIMER_obj timerobj, u8 tick) {
	switch(timerobj.timerId) {
		
		/* TIMER 0 */
		
		case TIMER_TIMER0:
		// SET TICKS
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			TIMER_REG_TCNT0 = TIMER_OVERFLOW - tick;
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			TIMER_REG_TCNT0 = 0;
			TIMER_REG_OCR0 = tick;
		}
		else if(timerobj.Ticks_Mode == TIMER_PHASE_CORRECT_PWM_MODE)
		{
			TIMER_REG_OCR0 = tick;
		}
		else if (timerobj.Ticks_Mode == TIMER_FAST_PWM_MODE)
		{
			TIMER_REG_OCR0 = tick;
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		
		switch(timerobj.Timer_Psc)
		{
			case TIMER_NO_CLOCK_TIMER:
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_CPU_CLOCK_TIMER:
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_CPU_CLOCK_8_TIMER:
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			break;
			case TIMER_F_CPU_CLOCK_64_TIMER:
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_CPU_CLOCK_256_TIMER:
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_CPU_CLOCK_1024_TIMER:
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_EXTERNAL_CLOCK_FALLING_TIMER:
			CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			case TIMER_F_EXTERNAL_CLOCK_RISING_TIMER:
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
			SET_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
			break;
			default: return TIMER_PSC_OUT_OF_RANGE;
		}
		break;
		
		
		/* TIMER 1 */
		
		case TIMER_TIMER1:
		break;
		
		
		/* TIMER 2 */
		
		case TIMER_TIMER2:
		// SET TICKS
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			TIMER_REG_TCNT2 = TIMER_OVERFLOW - tick;
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			TIMER_REG_TCNT2 = 0;
			TIMER_REG_OCR2 = tick;
		}
		else if(timerobj.Ticks_Mode == TIMER_PHASE_CORRECT_PWM_MODE)
		{
			TIMER_REG_OCR2 = tick;
		}
		else if (timerobj.Ticks_Mode == TIMER_FAST_PWM_MODE)
		{
			TIMER_REG_OCR2 = tick;
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		
		switch(timerobj.Timer_Psc)
		{
			case TIMER_NO_CLOCK_TIMER:
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_CPU_CLOCK_TIMER:
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_CPU_CLOCK_8_TIMER:
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_CPU_CLOCK_64_TIMER:
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_CPU_CLOCK_256_TIMER:
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_CPU_CLOCK_1024_TIMER:
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_EXTERNAL_CLOCK_FALLING_TIMER:
			CLR_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			case TIMER_F_EXTERNAL_CLOCK_RISING_TIMER:
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS20);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS21);
			SET_BIT(TIMER_REG_TCCR2,TIMER_REG_CS22);
			break;
			default: return TIMER_PSC_OUT_OF_RANGE;
		}
		break;
		
		
		/* TIMER ID OUT OF RANGE */
		
		default: return TIMER_ID_OUT_OF_RANGE;
	}

	
	return TIMER_OK;
}

extern EN_TIMER_Error_t TIMER_stop(TIMER_obj timerobj) {
	switch(timerobj.timerId) {
		// TIMER 0
		case TIMER_TIMER0:
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS00);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS01);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS02);
		break;
		
		// TIMER 1
		case TIMER_TIMER1:
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS10);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS11);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS12);
		break;
		
		// TIMER 2
		case TIMER_TIMER2:
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS20);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS21);
		CLR_BIT(TIMER_REG_TCCR0,TIMER_REG_CS22);
		break;
		
		// TIMER ID OUT OF RANGE
		default: return TIMER_ID_OUT_OF_RANGE;
	}
	
	return TIMER_OK;
}

extern EN_TIMER_Error_t TIMER_Get_FlagStatus(TIMER_obj timerobj, u8 *Flag) {
	switch (timerobj.timerId) {
		
		// TIMER 0
		case TIMER_TIMER0:
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			*Flag = GET_BIT(TIMER_REG_TIFR,TIMER_REG_TOV0);
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			*Flag = GET_BIT(TIMER_REG_TIFR,TIMER_REG_OCF0);
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		break;
		
		// TIMER 1
		case TIMER_TIMER1:
		break;
		
		// TIMER 2
		case TIMER_TIMER2:
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			*Flag = GET_BIT(TIMER_REG_TIFR,TIMER_REG_TOV2);
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			*Flag = GET_BIT(TIMER_REG_TIFR,TIMER_REG_OCF2);
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		break;
		
		// TIMER ID OUT OF RANGE
		default: return TIMER_ID_OUT_OF_RANGE;
	}
	
	return TIMER_OK;
}

extern EN_TIMER_Error_t TIMER_Flag_Reset(TIMER_obj timerobj) {
	switch (timerobj.timerId) {
		// TIMER 0
		case TIMER_TIMER0:
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			SET_BIT(TIMER_REG_TIFR, TIMER_REG_TOV0);
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			SET_BIT(TIMER_REG_TIFR, TIMER_REG_OCF0);
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		break;
		
		
		// TIMER 1
		case TIMER_TIMER1:
		break;
		
		
		// TIMER 2
		case TIMER_TIMER2:
		if (timerobj.Ticks_Mode == TIMER_NORMAL_MODE)
		{
			SET_BIT(TIMER_REG_TIFR, TIMER_REG_TOV2);
		}
		else if (timerobj.Ticks_Mode == TIMER_CTC_MODE)
		{
			SET_BIT(TIMER_REG_TIFR, TIMER_REG_OCF2);
		}
		else
		{
			return TIMER_TICKS_MODE_OUT_OF_RANGE;
		}
		break;
		
		
		// TIMER ID OUT OF RANGE
		
		default: return TIMER_ID_OUT_OF_RANGE;
	}
	
	return TIMER_OK;
}
extern EN_TIMER_Error_t TIMER_Reset(TIMER_obj timerobj) {
	
	switch (timerobj.timerId) {
		
		// TIMER 0
		case TIMER_TIMER0:
		TIMER_REG_TCNT0 = 0;
		break;
		
		// TIMER 1
		case TIMER_TIMER1:
		break;
		
		// TIMER 2
		case TIMER_TIMER2:
		TIMER_REG_TCNT2 = 0;
		break;
		
		// TIMER ID OUT OF RANGE
		default: return TIMER_ID_OUT_OF_RANGE;
	}
	
	return TIMER_OK;
	
}

extern EN_TIMER_Error_t TIMER_Get_Ticktime(TIMER_obj timerobj, u8 *ticktime) {
	switch (timerobj.timerId) {
		
		// TIMER 0
		case TIMER_TIMER0:
		*ticktime = TIMER_REG_TCNT0;
		break;
		
		// TIMER 1
		case TIMER_TIMER1:
		*ticktime = TIMER_REG_TCNT1;
		break;
		
		// TIMER 2
		case TIMER_TIMER2:
		*ticktime = TIMER_REG_TCNT2;
		break;
		
		// TIMER ID OUT OF RANGE
		default: return TIMER_ID_OUT_OF_RANGE;
	}
	
	return TIMER_OK;
}

extern EN_TIMER_Error_t TIMER_SecDelay(TIMER_obj timerobj) {
	u8 LocErrorStatus;
	
	for(u8 i = 0; i < 32; i++)
	{
		LocErrorStatus = TIMER_start(timerobj,TIMER_MAX_TICK);
		TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);

		u8 FLAG = 0;
		while(FLAG == 0)
		{
			LocErrorStatus = TIMER_Get_FlagStatus(timerobj,&FLAG);
			TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
		}
		
		LocErrorStatus = TIMER_Reset(timerobj);
		TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = TIMER_Flag_Reset(timerobj);
		TIMER_INTERNAL_ERROR_CHECK(LocErrorStatus);
	}
	return TIMER_OK;
}