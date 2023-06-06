/*
 * app.c
 *
 * Created: 4/3/2023 7:32:47 PM
 *  Author: Ahmed Hesham
 */ 

#include "app.h"

void APP_initModules(void)
{
	BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
	LED_init();
}

void APP_ledUnitTesting (void)
{
	LED_on(LED_1);
}

void APP_ledSequenceV_1 (void)
{
	static uint8_t_  counter;
	static uint8_t_ buttonState = 0;
	BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &buttonState);
	if (buttonState)
	{
		_delay_ms(60);
		BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &buttonState);
		if(buttonState)
		{
			BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &buttonState);
			counter++;
			switch(counter)
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
					counter = 0;	break;
					
				default:
					break;
				 
			}
			while(buttonState)
			{
				BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &buttonState);
			}
			
		}
	}
}
