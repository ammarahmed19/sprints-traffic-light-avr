/*
 * switch_private.h
 *
 * Created: 9/18/2022 3:40:05 PM
 *  Author: ammar
 */ 


#ifndef SWITCH_PRIVATE_H_
#define SWITCH_PRIVATE_H_


#define SWITCH_EXINT_MODE 0
#define SWITCH_PULLING_MODE 1

#define SWITCH_PULLUP 1
#define SWITCH_PULLDOWN 0

#define SWITCH_NULL 0

typedef struct SWITCH_obj {
	u8 port;
	u8 pin;
	u8 pullup;
	u8 interrupt_mode;
	u8 val;
} SWITCH_obj;

typedef enum EN_SWITCH_Error_t
{
	SWITCH_OK, SWITCH_PORT_OUT_OF_RANGE, SWITCH_PIN_OUT_OF_RANGE, SWITCH_INVALID_INTERRUPT_MODE, SWITCH_NOT_AN_INTERRUPT_PIN, SWITCH_INVALID_PULLUP_MODE, SWITCH_INTERNAL_ERROR
}EN_SWITCH_Error_t;


#endif /* SWITCH_PRIVATE_H_ */