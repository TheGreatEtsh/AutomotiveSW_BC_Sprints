/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU	16000000UL

#include <util/delay.h>
#include "../ECUAL/Button_Driver/Button.h"
#include "../ECUAL/LED_Driver/led.h"

void APP_initModules(void);
void APP_ledSequenceV_1 (void);
void APP_ledUnitTesting (void);

#endif /* APP_H_ */