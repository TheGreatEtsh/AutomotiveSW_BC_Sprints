/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU	8000000UL

#include <util/delay.h>
#include "button.h"
#include "led_interface.h"

void APP_initModules(void);
void APP_ledSequenceV_1 (void);
void APP_ledUnitTesting (void);

#endif /* APP_H_ */