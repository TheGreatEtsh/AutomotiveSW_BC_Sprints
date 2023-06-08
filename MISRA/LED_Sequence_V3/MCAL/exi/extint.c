/*
 * extint.c
 *
 * Created: 4/5/2023 4:40:48 PM
 *  Author: Ahmed Hesham
 */ 
#include "ExtInt.h"


void (*EXTINT_0_callBack) (void) = NULL_PTR;
void (*EXTINT_1_callBack) (void) = NULL_PTR;
void (*EXTINT_2_callBack) (void) = NULL_PTR;

EN_extintError_t EXTINT_Init (uint8_t_ intNumber)
{
	EN_extintError_t error =EXTINT_OK;
	/* Step 1	->		Choose Sense Control */
	switch(intNumber)
	{
		case INT_0:
		#if			SENSE_CONTROL_0		==		LOW_LEVEL
		CLR_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		ANY_CHANGE
		SET_BIT(MCUCR,ISC00);
		CLR_BIT(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		FALLING_EDGE
		CLR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		RISING_EDGE
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		#else
		error = EXTINT_NOK;
		#endif
		break;
		
		case INT_1:
		#if			SENSE_CONTROL_1		==		LOW_LEVEL
		CLR_BIT(MCUCR,ISC10);
		CLR_BIT(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		ANY_CHANGE
		SET_BIT(MCUCR,ISC10);
		CLR_BIT(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		FALLING_EDGE
		CLR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		RISING_EDGE
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		#else
		error = EXTINT_NOK;
		#endif
		break;
		
		case INT_2:
		#if			SENSE_CONTROL_2		==		FALLING_EDGE
		CLR_BIT(MCUCR,ISC2);
		#elif		SENSE_CONTROL_2		==		RISING_EDGE
		SET_BIT(MCUCSR,ISC2);
		#else
		error = EXTINT_NOK;
		#endif
		break;
		
		default: error = WRONG_INT_NUMBER;
		break;
	}
	/* Step 2	->		Enable Peripheral Interrupt */
	switch(intNumber)
	{
		case INT_0:	SET_BIT(GICR,INT0);		break;
		case INT_1:	SET_BIT(GICR,INT1);		break;
		case INT_2:	SET_BIT(GICR,INT2);		break;
		default: error = WRONG_INT_NUMBER;	break;
	}
	
	
	/* Step 3	->		Enable Global Interrupt */
	SET_BIT(SREG,Ibit);
	
	return error;
}


void EXTINT_setCallBackInt (uint8_t_ intNumber, void (*funPtr) (void))
{
	if (TRUE == (funPtr != NULL_PTR))
	{
		
		if (TRUE == (intNumber == INT_0))
		{
			EXTINT_0_callBack = funPtr;
		}
		else if (TRUE == (intNumber == INT_1))
		{
			EXTINT_1_callBack = funPtr;
		}
		else if (TRUE == (intNumber == INT_2))
		{
			EXTINT_2_callBack = funPtr;
		}
		else
		{
			/*WRONG INT NUMBER*/
		}
	}
	else
	{
		/*PTR TO FUNCTION IS POINTING TO NULL*/
	}
}


ISR(EXT_INT_0)
{
	if (TRUE == (EXTINT_0_callBack != NULL_PTR))
	{
		EXTINT_0_callBack();
	}
	else
	{
		/*CALLBACK FUNCTION IS POINTING TO NULL*/
	}
	
}

ISR(EXT_INT_1)
{
	if (TRUE == (EXTINT_1_callBack != NULL_PTR))
	{
		EXTINT_1_callBack();
	}
	else
	{
		/*CALLBACK FUNCTION IS POINTING TO NULL*/
	}
}

ISR(EXT_INT_2)
{
	if (TRUE == (EXTINT_2_callBack != NULL_PTR))
	{
		EXTINT_2_callBack();
	}
	else
	{
		/*CALLBACK FUNCTION IS POINTING TO NULL*/
	}
}