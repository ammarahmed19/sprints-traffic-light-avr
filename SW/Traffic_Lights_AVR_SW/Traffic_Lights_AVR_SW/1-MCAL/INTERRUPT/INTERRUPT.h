/*
 * INTERRUPT.h
 *
 * Created: 
 *  Author: ammar
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// LIBRARY INCLUDE
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/STD_TYPES.h"

// HELPERS INCLUDE
#include "INTERRUPT_private.h"
#include "INTERRUPT_error.h"

// REGISTERS INCLUDE
#include "INTERRUPT_reg.h"

extern void EXINT_EnableGlobalInterrupts();
extern void EXINT_DisableGlobalInterrupts();
extern EN_EXINT_Error_t EXINT_InitInterrupt(u8 EXINT_ID);

#endif /* INTERRUPT_H_ */