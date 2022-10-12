/*
 * INTERRUPT_private.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_d

#define EXINT0 0
#define EXINT1 1
#define EXINT2 2

#define EXINT0_PORT 3 // PORTD
#define EXINT0_PIN 2 // PD2

#define EXINT1_PORT 3 // PORTD
#define EXINT1_PIN 3 // PD3

#define EXINT2_PORT 1 // PORTB
#define EXINT2_PIN 3 // PB3



/* ENABLE GLOBAL INTERRUPT */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* DISABLE GLOBAL INTERRUPT */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* Interrupt Vectors */
/* Interrupt 0 */
#define EXINT_0_vect __vector_1
/* Interrupt 1 */
#define EXINT_1_vect __vector_2
/* Interrupt 2 */
#define EXINT_2_vect __vector_3

/* ISR definition */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


typedef enum EN_EXINT_Error_t
{
	EXINT_OK, EXINT_ID_OUT_OF_RANGE
}EN_EXINT_Error_t;




#endif /* INTERRUPT_PRIVATE_H_ */