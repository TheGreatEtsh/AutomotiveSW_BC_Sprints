/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU	8000000UL

#define	BLINK_1			0
#define	BLINK_2			1
#define	BLINK_3			2
#define	BLINK_4			3
#define BLINK_5			4
#define TURN_ON			0
#define TURN_OFF		1


#include "button.h"
#include "led_interface.h"
#include "timer_interface.h"
#include "extint.h"

void APP_initModules(void);
void APP_ledSequenceV_3 (void);

#endif /* APP_H_ */