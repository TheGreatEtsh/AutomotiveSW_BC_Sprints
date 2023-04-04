/*
 * button.c
 *
 * Created: 4/3/2023 5:52:59 PM
 *  Author: Ahmed Hesham
 */ 
#include "button.h"


EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	EN_buttonError_t error = BUTTON_OK;
	if (buttonPort > PORT_D)
	{
		error = WRONG_BUTTON_PORT;
	}
	else if (buttonPin > 7)
	{
		error = WRONG_BUTTON_PIN;
	}
	else
	{		
		DIO_init(buttonPort, buttonPin, INPUT);
		error = BUTTON_OK;
	}
	
	return error;
}

EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonState)
{
	EN_buttonError_t error = BUTTON_OK;
	if (buttonPort > PORT_D)
	{
		error = WRONG_BUTTON_PORT;
	}
	else if (buttonPin > 7)
	{
		error = WRONG_BUTTON_PIN;
	}
	else
	{
		DIO_read(buttonPort, buttonPin, buttonState);
		error = BUTTON_OK;
	}
	
	return error;
}