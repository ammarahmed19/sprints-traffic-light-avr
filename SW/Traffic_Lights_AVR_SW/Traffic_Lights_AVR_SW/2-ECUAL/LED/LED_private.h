/*
 * LED_private.h
 *
 * Created: 9/18/2022 3:21:41 PM
 *  Author: ammar
 */ 


#ifndef LED_PRIVATE_H_
#define LED_PRIVATE_H_

#define LED_ON 1
#define LED_OFF 0

typedef struct LED_obj {
	u8 port;
	u8 pin;
	u8 mode; // ON OFF
} LED_obj;

typedef enum EN_LED_Error_t
{
	LED_OK, LED_PIN_OUT_OF_RANGE, LED_PORT_OUT_OF_RANGE, LED_INVALID_MODE
}EN_LED_Error_t;



#endif /* LED_PRIVATE_H_ */