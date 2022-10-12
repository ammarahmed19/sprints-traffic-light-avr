/*
* TrafficLightControl.c
*
* Created:
*  Author: ammar
*/

#include "app.h"

ISR(EXINT_0_vect) {
	if (pedSwPressed == 0) {
		appMode = PED_MODE;
		pedSwPressed = 1;
		HW_Timer_reset(SYS_TIMER_ID);
		pedMode();
	}
}

void activateCarLight(u8 light) {
	switch (light) {
		case TRAFFIC_LIGHT_CAR_RED:
		
		carRedLed.mode = LED_ON;
		carYellowLed.mode = LED_OFF;
		carGreenLed.mode = LED_OFF;
		
		LED_write(carRedLed);
		LED_write(carYellowLed);
		LED_write(carGreenLed);
		
		activeCarLight = TRAFFIC_LIGHT_CAR_RED;
		
		break;
		
		case TRAFFIC_LIGHT_CAR_YELLOW:
		
		carRedLed.mode = LED_OFF;
		carYellowLed.mode = LED_ON;
		carGreenLed.mode = LED_OFF;
		
		LED_write(carRedLed);
		LED_write(carYellowLed);
		LED_write(carGreenLed);
		
		activeCarLight = TRAFFIC_LIGHT_CAR_YELLOW;
		
		break;
		
		case TRAFFIC_LIGHT_CAR_GREEN:
		
		carRedLed.mode = LED_OFF;
		carYellowLed.mode = LED_OFF;
		carGreenLed.mode = LED_ON;
		
		LED_write(carRedLed);
		LED_write(carYellowLed);
		LED_write(carGreenLed);
		
		activeCarLight = TRAFFIC_LIGHT_CAR_GREEN;
		
		
		break;
		
		default: raiseError();
	}
}

void activatePedLight(u8 light) {
	u8 LocErrorStatus;
	
	switch (light) {
		case TRAFFIC_LIGHT_PED_RED:
		
		pedRedLed.mode = LED_ON;
		pedYellowLed.mode = LED_OFF;
		pedGreenLed.mode = LED_OFF;
		
		LocErrorStatus = LED_write(pedRedLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedYellowLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedGreenLed);
		ERROR_CHECK(LocErrorStatus);
		
		activePedLight = TRAFFIC_LIGHT_PED_RED;
		
		break;
		
		case TRAFFIC_LIGHT_PED_YELLOW:
		
		pedRedLed.mode = LED_OFF;
		pedYellowLed.mode = LED_ON;
		pedGreenLed.mode = LED_OFF;
		
		LocErrorStatus = LED_write(pedRedLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedYellowLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedGreenLed);
		ERROR_CHECK(LocErrorStatus);
		
		activePedLight = TRAFFIC_LIGHT_PED_YELLOW;
		
		break;
		
		case TRAFFIC_LIGHT_PED_GREEN:
		
		pedRedLed.mode = LED_OFF;
		pedYellowLed.mode = LED_OFF;
		pedGreenLed.mode = LED_ON;
		
		LocErrorStatus = LED_write(pedRedLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedYellowLed);
		ERROR_CHECK(LocErrorStatus);
		
		LocErrorStatus = LED_write(pedGreenLed);
		ERROR_CHECK(LocErrorStatus);
		
		activePedLight = TRAFFIC_LIGHT_PED_GREEN;
		
		
		break;
		
		default: raiseError();
	}
}

void blinkLed(LED_obj* ledobj, u8 secs) {
	// Initially turn the led on for a second
	ledobj->mode = LED_ON;
	LED_write(*ledobj);
	HW_Timer_wait(SYS_TIMER_ID, ONE_SECOND);
	
	// Flash for N-1 seconds
	for (int i = 0; i < secs-1; i++) {
		ledobj->mode = !(ledobj->mode);
		LED_write(*ledobj);
		HW_Timer_wait(SYS_TIMER_ID, ONE_SECOND);
	}
}

void blink2Leds(LED_obj* led1, LED_obj* led2, u8 secs) {
	// Initially turn the led on for a second
	led1->mode = LED_ON;
	LED_write(*led1);
	led2->mode = LED_ON;
	LED_write(*led2);
	HW_Timer_wait(SYS_TIMER_ID, ONE_SECOND);
	
	// Flash for N-1 seconds
	for (int i = 0; i < secs-1; i++) {
		led1->mode = !(led1->mode);
		LED_write(*led1);
		led2->mode = !(led2->mode);
		LED_write(*led2);
		HW_Timer_wait(SYS_TIMER_ID, ONE_SECOND);
	}
}

void appSetup() {
	u8 LocErrorStatus;
	
	// initialize
	pedSwPressed = 0;
	
	// Initialize mode, counter, and lights
	appMode = CAR_MODE;
	activeCarLight = TRAFFIC_LIGHT_CAR_GREEN;
	activePedLight = TRAFFIC_LIGHT_PED_RED;
	
	// INITIALIZE ERROR INDICATOR
	errLed.port = ERR_LED_PORT;
	errLed.pin = ERR_LED_PIN;
	
	LocErrorStatus = LED_init(errLed);
	
	// CAR RED LED
	carRedLed.port = CAR_LED_RED_PORT;
	carRedLed.pin = CAR_LED_RED_PIN;
	
	LocErrorStatus = LED_init(carRedLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	// CAR YELLOW LED
	carYellowLed.port = CAR_LED_YELLOW_PORT;
	carYellowLed.pin = CAR_LED_YELLOW_PIN;
	
	LocErrorStatus = LED_init(carYellowLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	
	// CAR GREEN LED
	carGreenLed.port = CAR_LED_GREEN_PORT;
	carGreenLed.pin = CAR_LED_GREEN_PIN;
	
	LocErrorStatus = LED_init(carGreenLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	// PED RED LED
	pedRedLed.port = PED_LED_RED_PORT;
	pedRedLed.pin = PED_LED_RED_PIN;
	
	LocErrorStatus = LED_init(pedRedLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	// PED YELLOW LED
	pedYellowLed.port = PED_LED_YELLOW_PORT;
	pedYellowLed.pin = PED_LED_YELLOW_PIN;
	
	LocErrorStatus = LED_init(pedYellowLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	// PED GREEN LED
	pedGreenLed.port = PED_LED_GREEN_PORT;
	pedGreenLed.pin = PED_LED_GREEN_PIN;
	
	LocErrorStatus = LED_init(pedGreenLed); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	// PED SWITCH
	pedSw.port = PED_SW_PORT;
	pedSw.pin = PED_SW_PIN;
	pedSw.interrupt_mode = SWITCH_EXINT_MODE;
	pedSw.pullup = SWITCH_PULLUP;
	
	LocErrorStatus = SWITCH_init(pedSw); // Initialize
	ERROR_CHECK(LocErrorStatus);
	
	
	// HW TIMER
	LocErrorStatus = HW_Timer_init(SYS_TIMER_ID, SYS_TIMER_INTERRUPT_MODE); // INITIALIZE TIMER
	ERROR_CHECK(LocErrorStatus);
	
	LocErrorStatus = HW_Timer_start(SYS_TIMER_ID); // START TIMER
	ERROR_CHECK(LocErrorStatus);
	
	
	// INITIAL LIGHT
	activateCarLight(TRAFFIC_LIGHT_CAR_GREEN);
	//activatePedLight(TRAFFIC_LIGHT_PED_RED);
}

void normalMode() {
	switch (activeCarLight) {
		case TRAFFIC_LIGHT_CAR_GREEN:
		HW_Timer_wait(SYS_TIMER_ID, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
		activateCarLight(TRAFFIC_LIGHT_CAR_YELLOW);
		break;
		case TRAFFIC_LIGHT_CAR_YELLOW:
		blinkLed(&carYellowLed, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
		activateCarLight(TRAFFIC_LIGHT_CAR_RED);
		break;
		case TRAFFIC_LIGHT_CAR_RED:
		HW_Timer_wait(SYS_TIMER_ID, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
		activateCarLight(TRAFFIC_LIGHT_CAR_GREEN);
		break;
		default: raiseError();

	}
}

void pedMode() {
	if (activeCarLight == TRAFFIC_LIGHT_CAR_RED) {
		activateCarLight(TRAFFIC_LIGHT_CAR_RED);
		activatePedLight(TRAFFIC_LIGHT_PED_GREEN);
		
		HW_Timer_wait(SYS_TIMER_ID, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
	}
	else if (activeCarLight == TRAFFIC_LIGHT_CAR_GREEN || activeCarLight == TRAFFIC_LIGHT_CAR_YELLOW) {
		activateCarLight(TRAFFIC_LIGHT_CAR_YELLOW);
		activatePedLight(TRAFFIC_LIGHT_PED_YELLOW);
		
		blink2Leds(&carYellowLed, &pedYellowLed, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
		
		activateCarLight(TRAFFIC_LIGHT_CAR_RED);
		activatePedLight(TRAFFIC_LIGHT_PED_GREEN);
		
		HW_Timer_wait(SYS_TIMER_ID, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
	}
	else {
		raiseError();
	}
	activateCarLight(TRAFFIC_LIGHT_CAR_YELLOW);
	activatePedLight(TRAFFIC_LIGHT_PED_GREEN);
	
	blink2Leds(&carYellowLed, &pedYellowLed, TRAFFIC_LIGHT_SWITCH_TIME_SECS);
	
	activateCarLight(TRAFFIC_LIGHT_CAR_GREEN);
	activatePedLight(TRAFFIC_LIGHT_PED_RED);
	
	appMode = CAR_MODE;
	pedSwPressed = 0;
}

void app() {
	if (appMode == CAR_MODE) {
		normalMode();
	}
	else if (appMode == PED_MODE) {
		pedMode();
	}
}

void raiseError() {
	errLed.mode = LED_ON;
	LED_write(errLed);
}

void APP_start() {
	appSetup();
	
	while(1)
	{
		app();
	}
}
