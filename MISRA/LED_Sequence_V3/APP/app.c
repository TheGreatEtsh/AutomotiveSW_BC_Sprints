/*
 * app.c
 *
 * Created: 4/3/2023 7:32:47 PM
 *  Author: Ahmed Hesham
 */ 

#include "app.h"

uint8_t_ blinkMode = BLINK_1;
uint8_t_ timeOn = 1, timeOff = 9;
uint8_t_ counter = 0, tickNumber = 0 ;
volatile uint8_t_ state = TURN_ON;

static void sysTickTask (void);
static void button1Task(void);
static void button0Task (uint8_t_* counter, uint8_t_ state);

void APP_initModules(void)
{
	BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
	LED_init();
	
	EXTINT_Init(INT_0);
	EXTINT_setCallBackInt(INT_0, button1Task);
	
	timer_init();
	timer_set_time(TIMER_0, 100);
	timer_set_callback(TIMER_0, sysTickTask);
	timer_resume(TIMER_0);
}



void APP_ledSequenceV_3 (void)
{
	while (1)
	{
		uint8_t_ button0State = 0;
		BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
		if (TRUE == button0State)
		{
			BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
			if(TRUE == button0State)
			{
				BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				counter++;
				button0Task(&counter, state);
				while(TRUE == button0State)
				{
					BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				}
				
			}
		}
	}
}

static void button0Task (uint8_t_* counter, uint8_t_ state)
{
	switch (state)
	{
		case TURN_ON:
		switch(*counter)
		{
			case 1:
			LED_on(LED_0);
			LED_off(LED_1);
			LED_off(LED_2);
			LED_off(LED_3);
			break;
			
			case 2:
			LED_on(LED_0);
			LED_on(LED_1);
			LED_off(LED_2);
			LED_off(LED_3);
			break;
			
			case 3:
			LED_on(LED_0);
			LED_on(LED_1);
			LED_on(LED_2);
			LED_off(LED_3);
			break;
			
			case 4:
			LED_on(LED_0);
			LED_on(LED_1);
			LED_on(LED_2);
			LED_on(LED_3);
			break;
			
			case 5:
			LED_off(LED_0);
			LED_on(LED_1);
			LED_on(LED_2);
			LED_on(LED_3);
			break;
			
			case 6:
			LED_off(LED_0);
			LED_off(LED_1);
			LED_on(LED_2);
			LED_on(LED_3);
			break;
			
			case 7:
			LED_off(LED_0);
			LED_off(LED_1);
			LED_off(LED_2);
			LED_on(LED_3);
			break;
			
			case 8:
			LED_off(LED_0);
			LED_off(LED_1);
			LED_off(LED_2);
			LED_off(LED_3);
			*counter = 0;	break;
			
			default:
			break;
			
		}
		break;
		
		case TURN_OFF:
		LED_off(LED_0);
		LED_off(LED_1);
		LED_off(LED_2);
		LED_off(LED_3);
		break;
		
		default:
		break;
	}

}

static void button1Task(void)
{
	switch (blinkMode)
	{
		case BLINK_1:	timeOn = 1; timeOff = 9;	blinkMode = BLINK_2;	break;
		case BLINK_2:	timeOn = 2;	timeOff = 8;	blinkMode = BLINK_3;	break;
		case BLINK_3:	timeOn = 3;	timeOff = 7;	blinkMode = BLINK_4;	break;
		case BLINK_4:	timeOn = 5;	timeOff = 5;	blinkMode = BLINK_5;	break;
		case BLINK_5:	timeOn = 8;	timeOff = 2;	blinkMode = BLINK_1;	break;
		default:															break;
	}
}


static void sysTickTask (void)
{
	if (TRUE == (tickNumber < timeOn))
	{
		state = TURN_ON;
		button0Task(&counter, TURN_ON);
		tickNumber++;
	}
	else if (TRUE == ((TRUE == (tickNumber >= timeOn)) && (TRUE == (tickNumber < (timeOn+timeOff)))))
	{
		state = TURN_OFF;
		button0Task(&counter, TURN_OFF);
		tickNumber++;
		if (TRUE == (tickNumber >= (timeOn + timeOff)))
		{
			tickNumber = 0;
		}
	}

}