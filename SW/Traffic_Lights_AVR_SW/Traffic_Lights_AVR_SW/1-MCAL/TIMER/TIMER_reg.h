/*
 * TIMER_reg.h
 *
 * Created: 9/18/2022 11:42:36 AM
 *  Author: ammar
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#include "../../0-LIB/STD_TYPES.h"

// TIMER 0

#define TIMER_REG_TCNT0   (*(volatile u8*) 0x52)
#define TIMER_REG_TCCR0   (*(volatile u8*) 0x53)
#define TIMER_REG_OCR0	(*(volatile u8*) 0x5C)
#define TIMER_REG_FOC0    7
#define TIMER_REG_WGM00   6
#define TIMER_REG_COM01   5
#define TIMER_REG_COM00   4
#define TIMER_REG_WGM01   3
#define TIMER_REG_CS02    2
#define TIMER_REG_CS01    1
#define TIMER_REG_CS00    0


// GENERAL TIMER REGS
#define TIMER_REG_TIMSK   (*(volatile u8*) 0x59)
#define TIMER_REG_OCIE2   7
#define TIMER_REG_TICIE1  5
#define TIMER_REG_OCIE1A  4
#define TIMER_REG_OCIE1B  3
#define TIMER_REG_TOIE1   2
#define TIMER_REG_OCIE0   1
#define TIMER_REG_TOIE0   0
#define TIMER_REG_TOIE2   6
#define TIMER_REG_OCIE2   7
#define TIMER_REG_TOIE0 0


#define TIMER_REG_TIFR   (*(volatile u8*) 0x58)
#define TIMER_REG_OCF2   7
#define TIMER_REG_TOV2   6
#define TIMER_REG_ICF1   5
#define TIMER_REG_OCF1A  4
#define TIMER_REG_OCF1B  3
#define TIMER_REG_TOV1   2
#define TIMER_REG_OCF0   1
#define TIMER_REG_TOV0   0
#define TIMER_REG_TOV2   6
#define TIMER_REG_OCF2   7

#define TIMER_REG_OCR0   (*(volatile u8*) 0x5C)


#define TIMER_REG_SREG_I  7



// TIMER 1

#define TIMER_REG_TCCR1A  (*(volatile u8*) 0x4F)
#define TIMER_REG_COM1A1  7
#define TIMER_REG_COM1A0  6
#define TIMER_REG_COM1B1  5
#define TIMER_REG_COM1B0  4
#define TIMER_REG_FOC1A   3
#define TIMER_REG_FOC1B   2
#define TIMER_REG_WGM11   1
#define TIMER_REG_WGM10   0

#define TTIMER_REG_CCR1B  (*(volatile u8*) 0x4E)
#define TIMER_REG_ICNC1   7
#define TIMER_REG_ICES1   6
#define TIMER_REG_WGM13   4
#define TIMER_REG_WGM12   3
#define TIMER_REG_CS12    2
#define TIMER_REG_CS11    1
#define TIMER_REG_CS10    0

#define TIMER_REG_ICR1L    (*(volatile u8_t*) 0x46)
#define TIMER_REG_ICR1H    (*(volatile u8*) 0x47)
#define TIMER_REG_ICR1     (*(volatile u8*) 0x46)
#define TIMER_REG_OCR1AH   (*(volatile u8*) 0x4B)
#define TIMER_REG_OCR1AL   (*(volatile u8*) 0x4A)
#define TIMER_REG_OCR1A    (*(volatile u8*) 0x4A)
#define TIMER_REG_OCR1BH   (*(volatile u8*) 0x49)
#define TIMER_REG_OCR1BL   (*(volatile u8*) 0x48)
#define TIMER_REG_OCR1B    (*(volatile u8*) 0x48)

#define TIMER_REG_TCNT1    (*(volatile u8*) 0x4C)
#define TIMER_REG_TCNT1L    (*(volatile u8*) 0x4C)
#define TIMER_REG_TCNT1H    (*(volatile u8*) 0x4D)


// TIMER 2
#define TIMER_REG_TCNT2   (*(volatile u8*) 0x44)
#define TIMER_REG_TCCR2   (*(volatile u8*) 0x45)
#define TIMER_REG_OCR2	(*(volatile u8*) 0x43)
#define TIMER_REG_FOC2    7
#define TIMER_REG_WGM20   6
#define TIMER_REG_COM21   5
#define TIMER_REG_COM20   4
#define TIMER_REG_WGM21   3
#define TIMER_REG_CS22    2
#define TIMER_REG_CS21    1
#define TIMER_REG_CS20    0



#endif /* TIMER_REG_H_ */