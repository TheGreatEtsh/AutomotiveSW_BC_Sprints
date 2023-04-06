/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU	16000000UL

//#include <util/delay.h>
#include "../MCAL/Timer_Driver/timer.h"
#include "../MCAL/ExtInt_Driver/extint.h"
#include "../ECUAL/Button_Driver/Button.h"
#include "../ECUAL/LED_Driver/led.h"


void APP_initModules(void);

void APP_ledSequenceV_3 (void);

void APP_ledUnitTesting (void);
void button0Task (uint8_t* counter, uint8_t state);
void button1Task(void);
void sysTickTask(void);

void APP_timersUnitTesting (void);

void TASK_happyCase(void);
void TASK_worstCase(void);

#endif /* APP_H_ */