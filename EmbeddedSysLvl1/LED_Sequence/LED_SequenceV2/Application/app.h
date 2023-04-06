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
#include "../ECUAL/Button_Driver/Button.h"
#include "../ECUAL/LED_Driver/led.h"
#include "../MCAL/ExtInt_Driver/extint.h"

void APP_initModules(void);
void APP_ledSequenceV_1 (void);
void APP_ledUnitTesting (void);
void button1Task (void);
void TASK_worstCase (void);
void TASK_happyCase (void);
void APP_extIntUnitTesting (void);
#endif /* APP_H_ */