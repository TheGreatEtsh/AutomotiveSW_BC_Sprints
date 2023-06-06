/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU	8000000UL

#include "button.h"
#include "led_interface.h"
#include "timer_interface.h"
#include "extint.h"

void APP_initModules(void);
void APP_ledSequenceV_3 (void);
void APP_ledUnitTesting (void);
void button0Task (uint8_t_* counter, uint8_t_ state);
void button1Task(void);
void sysTickTask(void);

#endif /* APP_H_ */