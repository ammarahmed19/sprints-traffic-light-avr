/*
 * INTERRUPT_error.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef INTERRUPT_TYPES_H_
#define INTERRUPT_TYPES_H_


#define EXINT_ID_ERROR_CHECK(EXINT_ID) if (EXINT_ID > EXINT2 || EXINT_ID < EXINT0) return EXINT_ID_OUT_OF_RANGE


#endif /* INTERRUPT_TYPES_H_ */