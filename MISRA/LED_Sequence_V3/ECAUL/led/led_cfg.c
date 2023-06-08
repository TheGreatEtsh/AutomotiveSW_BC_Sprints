/*
 * led_cfg.c
 *
 * Created: 5/25/2023 2:47:02 AM
 *  Author: Ahmed Hesham
 */ 

#include "led_cfg.h"
#include "led_interface.h"

const str_LED_config_t cst_str_LED_config [LED_NUMBER_OF_LEDS] =
{
	{LED_0,	DIO_PORT_B,	DIO_P4},
	{LED_1, DIO_PORT_B,	DIO_P5},
	{LED_2,	DIO_PORT_B,	DIO_P6},
	{LED_3,	DIO_PORT_B,	DIO_P7},
	};