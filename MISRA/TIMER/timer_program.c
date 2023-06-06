/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *         @Date:  	5:34 PM Monday, May 15, 2023
 *		   @File:  	timer_program.c         
 *		 @Module:  	Timer
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Program file for Timer module     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "timer_interface.h"
#include "timer_cfg.h"
#include "timer_private.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const str_timer_config_t str_timer_config [NUMBER_OF_TIMERS_USED];

void (*timer_0_callback) (void) = NULL_PTR;

void (*timer_1_callback) (void) = NULL_PTR;

void (*timer_2_callback) (void) = NULL_PTR;

uint32_t_ gl_uint32_timer0_number_OVFs	=	0;

uint8_t_  gl_uint8_timer0_rem_ticks		=	0;

volatile uint32_t_ gl_uint32_timer0_OVF_counter	=	0;

uint32_t_ gl_uint32_timer1_number_OVFs	=	0;

uint16_t_ gl_uint16_timer1_rem_ticks		=	0;

volatile uint32_t_ gl_uint32_timer1_OVF_counter	=	0;

uint32_t_ gl_uint32_timer2_number_OVFs	=	0;

uint32_t_ gl_uint8_timer2_rem_ticks		=	0;

volatile uint32_t_ gl_uint32_timer2_OVF_counter	=	0;

uint8_t_ gl_uint8_normalToPwm		=	0;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION IMPLEMENTATION
 *********************************************************************************************************************/
 
/**
 * @Syntax          : enu_timer_error_t_ timer_init( void )
 * @Description     : Initialize Timer according to preprocessed configured definitions
 * @Sync\Async      : Synchronous
 * @Reentrancy      : Reentrant
 * @Parameters (in) : None
 * @Parameters (out): None
 * @Return value:   : enu_timer_error_t_		TIMER_OK = 0
 *											TIMER_WRONG_TIMER_USED = 1
 *											TIMER_WRONG_DESIRED_TIME = 2
 *											TIMER_NOK = 3
 */
enu_timer_error_t_ timer_init( void )
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	uint8_t_ uint8_counter = 0;
	
	for (; uint8_counter < NUMBER_OF_TIMERS_USED; uint8_counter++)
	{
		switch(str_timer_config[uint8_counter].timerUsed)
		{
			case TIMER_0:
			switch(str_timer_config[uint8_counter].waveformUsed)
			{
				case TIMER_OV:
				/*Choosing Normal Mode*/
				CLR_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
				/*Enabling OVF Interrupt 0*/
				SET_BIT(TIMSK,TOIE0);
				//SET_BIT(TIMSK,TOIE0);
				break;
				
				case TIMER_CTC:
				/*Choosing CTC Mode*/
				SET_BIT(TCCR0,WGM01); CLR_BIT(TCCR0,WGM00);
				/*Enabling CTC Interrupt 0*/
				SET_BIT(TIMSK,OCIE0);
				break;
				
				case TIMER_PWM:
				/*TO BE IMPLEMENTED*/
				break;
				
				default:
				enu_return_value = TIMER_NOK;
				break;
			}
			break;
			
			case TIMER_1:
			switch(str_timer_config[uint8_counter].waveformUsed)
			{
				case TIMER_OV:
				CLR_BIT(TCCR1A,COM1A1);
				CLR_BIT(TCCR1A,COM1A0);
				
				CLR_BIT(TCCR1B,WGM13);
				CLR_BIT(TCCR1B,WGM12);
				CLR_BIT(TCCR1A,WGM11);
				CLR_BIT(TCCR1A,WGM10);
				
				//SET_BIT(TIMSK, TOIE1);
				break;
				
				case TIMER_CTC:
				break;
				
				case TIMER_PWM:
				break;
				
				default:
				enu_return_value = TIMER_NOK;
				break;
			}
			break;
			
			case TIMER_2:
			switch(str_timer_config[uint8_counter].waveformUsed)
			{
				case TIMER_OV:
				/*Choosing Normal Mode*/
				CLR_BIT(TCCR2,WGM21); CLR_BIT(TCCR2,WGM20);
				/*Enabling OVF Interrupt 0*/
				SET_BIT(TIMSK,TOIE2);
				break;
				
				case TIMER_CTC:
				/*Choosing CTC Mode*/
				SET_BIT(TCCR0,WGM21); CLR_BIT(TCCR0,WGM20);
				/*Enabling CTC Interrupt 0*/
				SET_BIT(TIMSK,OCIE2);
				break;
				
				case TIMER_PWM:
				/*TO BE IMPLEMENTED*/
				break;
				
				default:
				enu_return_value = TIMER_NOK;
				break;
			}
			break;
			default:
			enu_return_value =  TIMER_WRONG_TIMER_USED;
			break;
		}
		if (enu_return_value != TIMER_OK)
		{
			break;
		}
		else
		{
			/*DO NOTHING*/
		}
	}
	
	/*Enabling Global Interrupt*/
	SET_BIT(SREG, Ibit);
	
	return enu_return_value;
}

/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_set_time
*					 (enu_timer_number_t_ enu_timer_used, f32 f32_desired_time)
* @Description     : set the time at which the timer interrupts
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
*					 f32					f32_a_desiredTime
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_set_time(enu_timer_number_t_ enu_timer_used, f32_t_ f32_desired_time)
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	uint32_t_ uint32_tickTime = 0;
	uint32_t_ uint32_numberOfTicks = 0;
	uint16_t_ uint16_TCNTValue = 0;
	
	switch(enu_timer_used)
	{
		case TIMER_0:
		switch(str_timer_config[enu_timer_used].waveformUsed)
		{
			case TIMER_OV:
			uint32_tickTime = str_timer_config[enu_timer_used].prescalerUsed / XTAL_FREQ;
			uint32_numberOfTicks = ((f32_desired_time*1000)/uint32_tickTime);
			
			gl_uint32_timer0_number_OVFs = uint32_numberOfTicks / 256;
			gl_uint8_timer0_rem_ticks = uint32_numberOfTicks % 256;
			
			if (gl_uint8_timer0_rem_ticks != 0)
			{
				TCNT0 = 256 - gl_uint8_timer0_rem_ticks;
				gl_uint32_timer0_number_OVFs++;
			}
			else 
			{
				/*DO NOTHING*/
			}
			break;
			
			case TIMER_CTC:
			/*TO BE IMPLEMENTED*/
			break;
			
			case TIMER_PWM:
			/*DO NOTHING*/
			break;
			
			default:
			enu_return_value = TIMER_NOK;
			break;
		}
		break;
		
		case TIMER_1:
		switch(str_timer_config[enu_timer_used].waveformUsed)
		{
			case TIMER_OV:
			uint32_tickTime = str_timer_config[enu_timer_used].prescalerUsed / XTAL_FREQ;
			uint32_numberOfTicks = ((f32_desired_time*1000)/uint32_tickTime);
			
			gl_uint32_timer1_number_OVFs = uint32_numberOfTicks / 65536;
			gl_uint16_timer1_rem_ticks = uint32_numberOfTicks % 65536;
			
			if (gl_uint16_timer1_rem_ticks != 0)
			{
				uint16_TCNTValue = 65536 - gl_uint16_timer1_rem_ticks;
				
				TCNT1L |= uint16_TCNTValue;
				TCNT1H |= (uint16_TCNTValue>>8);
				
				gl_uint32_timer2_number_OVFs++;
			}
			else 
			{
				/*DO NOTHING*/
			}
			break;
			
			case TIMER_CTC:
			/*TO BE IMPLEMENTED*/
			break;
			
			case TIMER_PWM:
			/*DO NOTHING*/
			break;
			
			default:
			enu_return_value = TIMER_NOK;
			break;
		}
		break;
		
		case TIMER_2:
		switch(str_timer_config[enu_timer_used].waveformUsed)
		{
			case TIMER_OV:
			uint32_tickTime = str_timer_config[enu_timer_used].prescalerUsed / XTAL_FREQ;
			uint32_numberOfTicks = ((f32_desired_time*1000)/uint32_tickTime);
			
			gl_uint32_timer2_number_OVFs = uint32_numberOfTicks / 256;
			gl_uint8_timer2_rem_ticks = uint32_numberOfTicks % 256;
			
			if (gl_uint8_timer2_rem_ticks != 0)
			{
				TCNT2 = 256 - gl_uint8_timer2_rem_ticks;
				gl_uint32_timer2_number_OVFs++;
			}
			else
			{
				/*DO NOTHING*/
			}
			break;
			
			case TIMER_CTC:
			/*TO BE IMPLEMENTED*/
			break;
			
			case TIMER_PWM:
			/*DO NOTHING*/
			break;
			
			default:
			enu_return_value = TIMER_NOK;
			break;
		}
		break;
		
		default:
		enu_return_value =  TIMER_WRONG_TIMER_USED;
		break;
		
	}
	return enu_return_value;
}


/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_resume(enu_timer_number_t_ enu_timer_used)
* @Description     : makes the timer to start/resume counting
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_resume(enu_timer_number_t_ enu_timer_used)
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	switch(enu_timer_used)
	{
		case TIMER_0:
		switch(str_timer_config[TIMER_0].prescalerUsed)
		{
			case TIMER_PRESCLNG_1:
			CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
			break;
			
			case TIMER_PRESCLNG_8:
			CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
			break;
			
			case TIMER_PRESCLNG_64:
			CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
			break;
			
			case TIMER_PRESCLNG_256:
			SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);
			break;
			
			case TIMER_PRESCLNG_1024:
			SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);
			break;
			
			default: enu_return_value = TIMER_NOK;	break;
		}
		break;
		
		case TIMER_1:
		switch(str_timer_config[TIMER_1].prescalerUsed)
		{
			case TIMER_PRESCLNG_1:
			CLR_BIT(TCCR1B, CS12);	CLR_BIT(TCCR1B, CS11);	SET_BIT(TCCR1B, CS10);
			break;
			
			case TIMER_PRESCLNG_8:
			CLR_BIT(TCCR1B, CS12);	SET_BIT(TCCR1B, CS11);	CLR_BIT(TCCR1B, CS10);
			break;
			
			case TIMER_PRESCLNG_64:
			CLR_BIT(TCCR1B, CS12);	SET_BIT(TCCR1B, CS11);	SET_BIT(TCCR1B, CS10);
			break;
			
			case TIMER_PRESCLNG_256:
			SET_BIT(TCCR1B, CS12);	CLR_BIT(TCCR1B, CS11);	CLR_BIT(TCCR1B, CS10);
			break;
			
			case TIMER_PRESCLNG_1024:
			SET_BIT(TCCR1B, CS12);	CLR_BIT(TCCR1B, CS11);	SET_BIT(TCCR1B, CS10);
			break;
			
			default: enu_return_value = TIMER_NOK;	break;
		}
		break;
		
		case TIMER_2:
		switch(str_timer_config[TIMER_1].prescalerUsed)
		{
			case TIMER_PRESCLNG_1:
			CLR_BIT(TCCR2,CS22); CLR_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
			break;
			
			case TIMER_PRESCLNG_8:
			CLR_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	CLR_BIT(TCCR2,CS20);
			break;
			
			case TIMER_PRESCLNG_64:
			SET_BIT(TCCR2,CS22); CLR_BIT(TCCR2,CS21);	CLR_BIT(TCCR2,CS20);
			break;
			
			case TIMER_PRESCLNG_256:
			SET_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	CLR_BIT(TCCR2,CS20);
			break;
			
			case TIMER_PRESCLNG_1024:
			SET_BIT(TCCR2,CS22); SET_BIT(TCCR2,CS21);	SET_BIT(TCCR2,CS20);
			break;
			
			default: enu_return_value = TIMER_NOK;	break;
		}
		break;
		default:
		enu_return_value =  TIMER_NOK;
		break;
		
	}
	return enu_return_value;
}


/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_pause(enu_timer_number_t_ enu_timer_used)
* @Description     : makes the timer to pause counting
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_pause(enu_timer_number_t_ enu_timer_used)
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	switch(enu_timer_used)
	{
		case TIMER_0:
		CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);	break;
		
		case TIMER_1:
		CLR_BIT(TCCR1B,CS12);	CLR_BIT(TCCR1B,CS11);	CLR_BIT(TCCR1B,CS10);	break;
		
		case TIMER_2:
		CLR_BIT(TCCR2, CS22);	CLR_BIT(TCCR2, CS21);	CLR_BIT(TCCR2, CS20);	break;
		
		default:	
		enu_return_value =			TIMER_WRONG_TIMER_USED;							break;
		
	}
	return enu_return_value;
}

/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_disable_interrupt(enu_timer_number_t_ enu_timer_used)
* @Description     : Disables timer's interrupts
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_disable_interrupt(enu_timer_number_t_ enu_timer_used)
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	switch(enu_timer_used)
	{
		case TIMER_0:	CLR_BIT(TIMSK,TOIE0);				break;
		
		case TIMER_1:	CLR_BIT(TIMSK,TOIE1);				break;
		
		case TIMER_2:	CLR_BIT(TIMSK,TOIE2);				break;
		
		default:	enu_return_value =  TIMER_WRONG_TIMER_USED;	break;
		
	}
	return enu_return_value;
}

/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_enable_interrupt(enu_timer_number_t_ enu_timer_used)
* @Description     : Enables timer's interrupts
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_enable_interrupt(enu_timer_number_t_ enu_timer_used)
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	switch(enu_timer_used)
	{
		case TIMER_0:	SET_BIT(TIMSK,TOIE0);				break;
		
		case TIMER_1:	SET_BIT(TIMSK,TOIE1);				break;
		
		case TIMER_2:	SET_BIT(TIMSK,TOIE2);				break;
		
		default:	enu_return_value =  TIMER_WRONG_TIMER_USED;	break;
		
	}
	return enu_return_value;
}

/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_set_callback
*					 (enu_timer_number_t_ enu_timer_used, void (*funPtr)(void))
* @Description     : sets the call back function for a specific timer
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : enu_timer_number_t_		enu_timer_used
*					 void					(*funPtr)(void)
* @Parameters (out): None
* @Return value:   : enu_timer_error_t_		TIMER_OK = 0
*											TIMER_WRONG_TIMER_USED = 1
*											TIMER_WRONG_DESIRED_TIME = 2
*											TIMER_NOK = 3
*******************************************************************************/
enu_timer_error_t_ timer_set_callback(enu_timer_number_t_ enu_timer_used, void (*funPtr)(void))
{
	enu_timer_error_t_ enu_return_value = TIMER_OK;
	
	if(funPtr != NULL_PTR)	
	{	
		switch(enu_timer_used)
		{
			case TIMER_0:	timer_0_callback = funPtr;			break;
			
			case TIMER_1:	timer_1_callback = funPtr;			break;
			
			case TIMER_2:	timer_2_callback = funPtr;			break;
			
			default:	enu_return_value = TIMER_WRONG_TIMER_USED;	break;
		}
	}
	else
	{
		enu_return_value = TIMER_NOK;
	}
	return enu_return_value;
}

ISR(TIM0_OVF_INT)
{
	if (gl_uint8_normalToPwm == 0	)
	{
		gl_uint32_timer0_OVF_counter ++;
		if (gl_uint32_timer0_OVF_counter == gl_uint32_timer0_number_OVFs)
		{
			if(timer_0_callback != NULL_PTR)
			{
				timer_0_callback();
			}
			gl_uint32_timer0_OVF_counter   =	0;
			TCNT0 = 256 - gl_uint8_timer0_rem_ticks;
		}
	}
	else
	{
		/*TO BE IMPLEMENTED*/
	}
}

ISR(TIM1_OVF_INT)
{
	gl_uint32_timer1_OVF_counter ++;
	if (gl_uint32_timer1_OVF_counter  == gl_uint32_timer1_number_OVFs)
	{
		if(timer_1_callback != NULL_PTR)
		{
			timer_1_callback();
		}
		gl_uint32_timer1_OVF_counter  =	0;
		TCNT1 = 65536 - gl_uint16_timer1_rem_ticks;
		
	}

}

ISR(TIM2_OVF_INT)
{
	gl_uint32_timer2_OVF_counter ++;
	if (gl_uint32_timer2_OVF_counter  == gl_uint32_timer2_number_OVFs)
	{
		if(timer_2_callback != NULL_PTR)
		{
			timer_2_callback();
		}
		gl_uint32_timer2_OVF_counter  =	0;
		TCNT2 = 256 - gl_uint8_timer2_rem_ticks;
		
	}

}
/**********************************************************************************************************************
 *  END OF FILE: timer_program.c
 *********************************************************************************************************************/
