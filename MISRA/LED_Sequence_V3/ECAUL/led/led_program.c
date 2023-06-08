/*
 * led.c
 *
 * Created: 4/3/2023 5:33:07 PM
 *  Author: Ahmed Hesham
 */ 

#include "led_interface.h"
#include "led_cfg.h"
#include "dio_interface.h"


extern str_LED_config_t cst_str_LED_config[LED_NUMBER_OF_LEDS];


enu_LED_status_t LED_init(void)
{
	enu_LED_status_t en_a_error = LED_OK;
	
	for(uint8_t_ counter = 0;TRUE == (counter < LED_NUMBER_OF_LEDS); counter++)	
	{
		
		if (TRUE == (cst_str_LED_config[counter].uint8_ledPort > DIO_PORT_D))
		{
			
			en_a_error = LED_WRONG_LED_PORT;
		}
		else if (TRUE == (cst_str_LED_config[counter].uint8_ledPin > 7))
		{
			en_a_error = LED_WRONG_LED_PIN;
		}
		else
		{
			dio_init(cst_str_LED_config[counter].uint8_ledPort, 
						cst_str_LED_config[counter].uint8_ledPin, 
						DIO_OUTPUT);
			en_a_error = LED_OK;
		}
		
	}
	return en_a_error;
}

enu_LED_status_t LED_on(uint8_t_ uint8_ledID)
{
	enu_LED_status_t en_a_error = LED_OK;
	
	uint8_t_ counter = 0;
	for (;TRUE == (counter < LED_NUMBER_OF_LEDS); counter++)
	{
		if (TRUE == (uint8_ledID == cst_str_LED_config[counter].uint8_ledID))
		{
			break;
		}
	}
	
	if (TRUE == (cst_str_LED_config[counter].uint8_ledPort > DIO_PORT_D))
	{
		en_a_error = LED_WRONG_LED_PORT;
	}
	else if (TRUE == (cst_str_LED_config[counter].uint8_ledPin > 7))
	{
		en_a_error = LED_WRONG_LED_PIN;
	}
	else
	{
		dio_write(cst_str_LED_config[counter].uint8_ledPort,
					cst_str_LED_config[counter].uint8_ledPin, 
					DIO_HIGH);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}

enu_LED_status_t LED_off(uint8_t_ uint8_ledID)
{
	enu_LED_status_t en_a_error = LED_OK;
	
	uint8_t_ counter = 0;
	for (;TRUE == (counter < LED_NUMBER_OF_LEDS); counter++)
	{
		if (uint8_ledID == cst_str_LED_config[counter].uint8_ledID)
		{
			break;
		}
	}
	
	if (TRUE == (cst_str_LED_config[counter].uint8_ledPort > DIO_PORT_D))
	{
		en_a_error = LED_WRONG_LED_PORT;
	}
	else if (TRUE == (cst_str_LED_config[counter].uint8_ledPin > 7))
	{
		en_a_error = LED_WRONG_LED_PIN;
	}
	else
	{
		dio_write(cst_str_LED_config[counter].uint8_ledPort,
					cst_str_LED_config[counter].uint8_ledPin,
					DIO_LOW);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}
enu_LED_status_t LED_toggle(uint8_t_ uint8_ledID)
{
	enu_LED_status_t en_a_error = LED_OK;
	
	uint8_t_ counter = 0;
	for (;TRUE == (counter < LED_NUMBER_OF_LEDS); counter++)
	{
		if (TRUE == (uint8_ledID == cst_str_LED_config[counter].uint8_ledID))
		{
			break;
		}
	}
	
	if (TRUE == (cst_str_LED_config[counter].uint8_ledPort > DIO_PORT_D))
	{
		en_a_error = LED_WRONG_LED_PORT;
	}
	else if (TRUE == (cst_str_LED_config[counter].uint8_ledPin > 7))
	{
		en_a_error = LED_WRONG_LED_PIN;
	}
	else
	{
		dio_toggle(cst_str_LED_config[counter].uint8_ledPort, cst_str_LED_config[counter].uint8_ledPin);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}
