/*
 * timer.c
 *
 * Created: 4/5/2023 12:38:08 AM
 *  Author: Ahmed Hesham
 */ 

#include "timer.h"

uint32_t TIMER_0_numberOfOVFs	=	0;

uint32_t TIMER_0_numberOfCTCs	=	0;	

uint8_t  TIMER_0_remTicks		=	0;

void (*TIMER_0_callBack) (void) = nullPtr;

void (*TIMER_1_callBack) (void) = nullPtr;

void (*TIMER_2_callBack) (void) = nullPtr;

EN_timerError_t TIMER_init(uint8_t timerUsed)
{
	EN_timerError_t error = TIMER_OK;
	
	if (timerUsed == TIMER_0)
	{
		#if			TIMER_0_MODE		==		OV_TIMER
		/*Choosing Normal Mode*/
		CLR_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
		/*Enabling OVF Interrupt 0*/
		SET_BIT(TIMSK,TOIE0);
		
		#elif		TIMER_0_MODE		==		CTC_TIMER
		/*Choosing CTC Mode*/
		SET_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
		/*Enabling CTC Interrupt 0*/
		SET_BIT(TIMSK,OCIE0);
		
		#endif
		/*Enabling Global Interrupt*/
		SET_BIT(SREG, Ibit);

	}
	else if (timerUsed == TIMER_1)
	{
	}
	else if (timerUsed == TIMER_2)
	{
	}
	else
	{
		error = WRONG_TIMER_USED;
	}
	return error;
}

EN_timerError_t TIMER_setTime(uint8_t timerUsed, uint32_t desiredTime)
{
	EN_timerError_t error = TIMER_OK;
	
	if (timerUsed == TIMER_0)
	{
		uint32_t tickTime = TIMER_0_PRESCALER / XTAL_FREQ;
		uint32_t numberOfTicks = ((desiredTime*1000)/tickTime);
		
		#if		TIMER_0_MODE		==		OV_TIMER
		TIMER_0_numberOfOVFs = numberOfTicks / 256;
		TIMER_0_remTicks = numberOfTicks % 256;
		if (TIMER_0_remTicks)
		{
			TCNT0 = 256 - TIMER_0_remTicks;
			TIMER_0_numberOfOVFs++;
		}
		
		#elif	TIMER_0_MODE		==		CTC_TIMER
		uint8_t divisionFactor = 255;
		while(divisionFactor > numberOfTicks)
		{
			divisionFactor--;
		}
		while(numberOfTicks % divisionFactor)
		{
			divisionFactor--;
		}
		TIMER_0_numberOfCTCs = numberOfTicks / divisionFactor;
		OCR0 = divisionFactor - 1;
		
		#endif
	}
	else if (timerUsed == TIMER_1)
	{
	}
	else if (timerUsed == TIMER_2)
	{
	}
	else
	{
		error = WRONG_TIMER_USED;
	}
	return error;
	
}

EN_timerError_t TIMER_start(uint8_t timerUsed)
{
	EN_timerError_t error = TIMER_OK;
	
	if (timerUsed == TIMER_0)
	{
		#if		TIMER_0_PRESCALER == PRESCLNG_1
		CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
		
		#elif	TIMER_0_PRESCALER == PRESCLNG_8
		CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
		
		#elif	TIMER_0_PRESCALER == PRESCLNG_64
		CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
		
		#elif	TIMER_0_PRESCALER == PRESCLNG_256
		SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
		
		#elif	TIMER_0_PRESCALER == PRESCLNG_1024
		SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
		
		#endif
	}
	else if (timerUsed == TIMER_1)
	{
	}
	else if (timerUsed == TIMER_2)
	{
	}
	else
	{
		error = WRONG_TIMER_USED;
	}
	return error;
	
}

EN_timerError_t TIMER_stop(uint8_t timerUsed)
{
	EN_timerError_t error = TIMER_OK;
	
	if (timerUsed == TIMER_0)
	{
		CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
	}
	else if (timerUsed == TIMER_1)
	{
	}
	else if (timerUsed == TIMER_2)
	{
	}
	else
	{
		error = WRONG_TIMER_USED;
	}
	return error;
	
}

void TIMER_setCallBack(uint8_t timerUsed, void (*funPtr)(void))
{
	if(funPtr != nullPtr)
	{
		if (timerUsed == TIMER_0)
		{
			TIMER_0_callBack = funPtr;
		}
		else if (timerUsed == TIMER_1)
		{
			TIMER_1_callBack = funPtr;
		}
		else if (timerUsed == TIMER_2)
		{
			TIMER_2_callBack = funPtr;
		}
	}
}



#if			TIMER_0_MODE		==		OV_TIMER
ISR(TIMER0_OVF)
{
	static uint32_t OVFCounter = 0;
	OVFCounter  ++;
	if (OVFCounter  == TIMER_0_numberOfOVFs)
	{
		if(TIMER_0_callBack != nullPtr)
		{
			TIMER_0_callBack();
		}
		OVFCounter  =	0;
		TCNT0 = 256 - TIMER_0_remTicks;
		
	}
}

#elif		TIMER_0_MODE		==		CTC_TIMER
ISR(TIMER0_COMP)
{
	static uint32_t CTCCounter = 0;
	CTCCounter  ++;
	if (CTCCounter  == TIMER_0_numberOfCTCs)
	{
		if(TIMER_0_callBack != nullPtr)
		{
			TIMER_0_callBack();
		}
		CTCCounter  =	0;
	}
}
#endif