/*
 * Button.h
 *
 * Created: 4/3/2023 5:53:31 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_Driver/dio.h"

#define BUTTON_0_PORT	PORT_D
#define BUTTON_0_Pin	0
#define BUTTON_1_PORT	PORT_D
#define BUTTON_1_Pin	2

typedef enum buttonErrors{
	BUTTON_OK,
	WRONG_BUTTON_PORT,
	WRONG_BUTTON_PIN
}EN_buttonError_t;

EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonState);


#endif /* BUTTON_H_ */