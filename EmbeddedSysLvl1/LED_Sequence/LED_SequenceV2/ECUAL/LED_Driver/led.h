/*
 * led.h
 *
 * Created: 4/3/2023 5:33:17 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/dio.h"

#define LED_0_PORT		PORT_A
#define LED_1_PORT		PORT_A
#define LED_2_PORT		PORT_A
#define LED_3_PORT		PORT_A
#define LED_0_PIN		0
#define LED_1_PIN		1
#define LED_2_PIN		2
#define LED_3_PIN		3

typedef enum ledErrors{
	LED_OK,
	WRONG_LED_PORT,
	WRONG_LED_PIN
	}EN_ledError_t;



EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin);

EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin);

EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin);

EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin);


#endif /* LED_H_ */