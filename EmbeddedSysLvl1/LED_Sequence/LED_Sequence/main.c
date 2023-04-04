/*
 * LED_Sequence.c
 *
 * Created: 4/3/2023 4:06:53 PM
 * Author : Ahmed Hesham
 */ 

#include "Application/app.h"

int main(void)
{
	APP_initModules();
    while (1) 
    {
		APP_ledSequenceV_1();
    }
}

