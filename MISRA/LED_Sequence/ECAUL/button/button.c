/*
 * button.c
 *
 * Created: 4/3/2023 5:52:59 PM
 *  Author: Ahmed Hesham
 */ 
#include "button.h"


EN_buttonError_t BUTTON_init(uint8_t_ buttonPort, uint8_t_ buttonPin)
{
	EN_buttonError_t error = BUTTON_OK;
	if (dio_init(buttonPort, buttonPin, DIO_INPUT) != DIO_OK)
	{
		error = BUTTON_NOK;
	}
	else
	{
		/*BUTTON_OK*/
	}
	
	
	return error;
}

EN_buttonError_t BUTTON_read(uint8_t_ buttonPort, uint8_t_ buttonPin, uint8_t_ *buttonState)
{
	EN_buttonError_t error = BUTTON_OK;
	
	if (dio_read(buttonPort, buttonPin, buttonState) != DIO_OK)
	{
		error = BUTTON_NOK;
	}
	else
	{
		/*BUTTON_OK*/
	}
	
	return error;
}