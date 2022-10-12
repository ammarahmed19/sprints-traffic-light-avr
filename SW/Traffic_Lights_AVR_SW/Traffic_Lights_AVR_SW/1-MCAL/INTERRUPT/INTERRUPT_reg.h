/*
* INTERRUPT_reg.h
*
* Created:
*  Author: ammar
*/


#ifndef INTERRUPT_REG_H_
#define INTERRUPT_REG_H_


#define EXINT_REG_GICR	 		*((volatile u8*)0x5B)
#define EXINT_REG_GICR_INT1		7
#define EXINT_REG_GICR_INT0		6
#define EXINT_REG_GICR_INT2		5

#define EXINT_REG_GIFR		 	*((volatile u8*)0x5A)

#define EXINT_REG_MCUCR		 	*((volatile u8*)0x55)
#define EXINT_REG_MCUCR_ISC11		3
#define EXINT_REG_MCUCR_ISC10		2
#define EXINT_REG_MCUCR_ISC01		1
#define EXINT_REG_MCUCR_ISC00		0

#define EXINT_REG_MCUCSR	 		*((volatile u8*)0x54)
#define EXINT_REG_MCUCSR_INT2		6

#define EXINT_REG_SREG		*((volatile u8*)0x5F)
#define EXINT_REG_SREG_I		7



#endif /* INTERRUPT_REG_H_ */