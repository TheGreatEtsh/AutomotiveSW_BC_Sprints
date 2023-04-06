/*
 * app.c
 *
 * Created: 4/3/2023 7:32:47 PM
 *  Author: Ahmed Hesham
 */ 

#include "app.h"



void APP_initModules(void)
{
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_Pin);
	LED_init(LED_0_PORT, LED_0_PIN);
	LED_init(LED_1_PORT, LED_1_PIN);
	LED_init(LED_2_PORT, LED_2_PIN);
	LED_init(LED_3_PORT, LED_3_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	EXTINT_Init(INT_0);
	EXTINT_setCallBackInt(INT_0, button1Task);
}

void APP_extIntUnitTesting (void)
{
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_Pin);
	LED_init(LED_0_PORT, LED_0_PIN);
	LED_init(LED_1_PORT, LED_1_PIN);
	uint8_t error = 0;
	error = EXTINT_Init(10);
	EXTINT_setCallBackInt(INT_0, TASK_happyCase);
	while (1)
	{
			
		if (error)
		{
			TASK_worstCase();
		}
			
	}
}

void TASK_happyCase (void)
{
	LED_on(LED_0_PORT, LED_0_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
}

void TASK_worstCase (void)
{
	LED_on(LED_1_PORT, LED_1_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
}


void APP_ledSequenceV_1 (void)
{
	while (1)
	{
	}
}


void button1Task ()
{
	
	volatile static uint8_t  counter = 0;
	counter++;
	switch(counter)
	{
		case 1:
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		break;
			
		case 2:
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		break;
			
		case 3:
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		break;
			
		case 4:
		LED_on(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		break;
			
		case 5:
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_on(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		break;
			
		case 6:
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_on(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		break;
			
		case 7:
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_on(LED_3_PORT, LED_3_PIN);
		break;
			
		case 8:
		LED_off(LED_0_PORT, LED_0_PIN);
		LED_off(LED_1_PORT, LED_1_PIN);
		LED_off(LED_2_PORT, LED_2_PIN);
		LED_off(LED_3_PORT, LED_3_PIN);
		counter = 0;	break;
			
		default:
		break;
			
	}

}
