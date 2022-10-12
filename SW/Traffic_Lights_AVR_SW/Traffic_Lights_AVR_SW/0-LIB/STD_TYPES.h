/*
 * STD_TYPES.h
 *
 * Created: 
 *  Author: ammar
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define OK 0
#define NOK 1

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;

#define ERROR_CHECK_RETURN(ERR) if (ERR != OK) return ERR 


#endif /* STD_TYPES_H_ */