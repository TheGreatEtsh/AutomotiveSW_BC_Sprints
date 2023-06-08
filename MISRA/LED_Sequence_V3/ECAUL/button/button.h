/*
 * Button.h
 *
 * Created: 4/3/2023 5:53:31 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "dio_interface.h"

#define BUTTON_0_PORT	DIO_PORT_C
#define BUTTON_0_Pin	DIO_P4

typedef enum buttonErrors{
	BUTTON_OK = 0,
	BUTTON_NOK
}EN_buttonError_t;

EN_buttonError_t BUTTON_init(uint8_t_ buttonPort, uint8_t_ buttonPin);

EN_buttonError_t BUTTON_read(uint8_t_ buttonPort, uint8_t_ buttonPin, uint8_t_ *buttonState);


#endif /* BUTTON_H_ */