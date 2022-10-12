/*
 * TrafficLightControl.h
 *
 * Created:
 *  Author: ammar
 */ 


#ifndef TRAFFICLIGHTCONTROLAPP_H_
#define TRAFFICLIGHTCONTROLAPP_H_

#include "../2-ECUAL/LED/LED.h"
#include "../2-ECUAL/SWITCH/SWITCH.h"
#include "../2-ECUAL/HW_TIMER/HW_TIMER.h"

// ERROR INDICATOR LED
#define ERR_LED_PORT PORTD;
#define ERR_LED_PIN PIN7;

// CAR LEDS
#define CAR_LED_RED_PORT PORTA
#define CAR_LED_RED_PIN PIN0

#define CAR_LED_YELLOW_PORT PORTA
#define CAR_LED_YELLOW_PIN PIN1

#define CAR_LED_GREEN_PORT PORTA
#define CAR_LED_GREEN_PIN PIN2

// PED LEDS
#define PED_LED_RED_PORT PORTB
#define PED_LED_RED_PIN PIN0

#define PED_LED_YELLOW_PORT PORTB
#define PED_LED_YELLOW_PIN PIN1

#define PED_LED_GREEN_PORT PORTB
#define PED_LED_GREEN_PIN PIN2


// PED SWITCH
#define PED_SW_PORT PORTD
#define PED_SW_PIN PIN2


// SYS TIMER
#define SYS_TIMER_ID HW_TIMER0
#define SYS_TIMER_INTERRUPT_MODE HW_TIMER_POLLING_MODE 

// APP MODES
#define CAR_MODE 0
#define PED_MODE 1

// TRAFFIC LIGHTS
#define TRAFFIC_LIGHT_CAR_RED 0 
#define TRAFFIC_LIGHT_CAR_YELLOW 1
#define TRAFFIC_LIGHT_CAR_GREEN 2

#define TRAFFIC_LIGHT_PED_RED 3
#define TRAFFIC_LIGHT_PED_YELLOW 4
#define TRAFFIC_LIGHT_PED_GREEN 5

// TIME
#define TRAFFIC_LIGHT_SWITCH_TIME_SECS 5
#define ONE_SECOND 1


LED_obj errLed;

LED_obj carRedLed;
LED_obj carYellowLed;
LED_obj carGreenLed;

LED_obj pedRedLed;
LED_obj pedYellowLed;
LED_obj pedGreenLed;

SWITCH_obj pedSw; // pedestrian button
u8 pedSwPressed;

u8 appMode;

u8 activeCarLight;
u8 activePedLight;


#define ERROR_CHECK(val) if (val != OK) raiseError()

void activateCarLight(u8 light);
void activatePedLight(u8 light);

void blinkLed(LED_obj* ledobj, u8 secs);
void blink2Leds(LED_obj* led1, LED_obj* led2, u8 secs);

void appSetup();
void normalMode();
void pedMode();
void app();
void raiseError();

void APP_start();


#endif /* TRAFFICLIGHTCONTROL_H_ */