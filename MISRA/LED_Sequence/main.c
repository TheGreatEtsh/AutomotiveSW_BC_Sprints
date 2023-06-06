/*
 * LED_Sequence.c
 *
 * Created: 6/6/2023 7:04:52 PM
 * Author : Ahmed Hesham
 */ 

#include "app.h"

int main(void)
{
    /* Replace with your application code */
	
	APP_initModules();
	
	
    while (1) 
    {
		APP_ledSequenceV_1();
    }
}

