/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *
 *		   @Date:  	5:34 PM Monday, May 15, 2023
 *		   @File:  	timer_interface.h         
 *		 @Module:  	Timer
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for Timer module     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "interrupts.h"
#include "bit_math.h"
#include "std.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/**************************************_CLOCK_FREQUENCY_USED_************************************/
#define XTAL_FREQ					(F_CPU / 1000000UL)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum timerError{
	TIMER_OK = 0,
	TIMER_WRONG_TIMER_USED,
	TIMER_WRONG_DESIRED_TIME,
	TIMER_NOK
}enu_timer_error_t_;
	
typedef enum
{
	TIMER_0 = 0,
	TIMER_1,
    TIMER_2
}enu_timer_number_t_;

typedef enum
{
	TIMER_OV = 0,
	TIMER_PWM,
    TIMER_CTC
}enu_timer_waveform_used_t_;

typedef enum
{	
	TIMER_NO_CLK		= 0,
	TIMER_PRESCLNG_1	= 1,
	TIMER_PRESCLNG_8	= 8,
	TIMER_PRESCLNG_64	= 64,
	TIMER_PRESCLNG_256	= 256,
	TIMER_PRESCLNG_1024	= 1024,
	TIMER_XCK_FLNG_EDGE	= 10,
	TIMER_XCK_RSNG_EDGE	= 15
}enu_timer_prescaler_used_t_;


typedef struct
{
	enu_timer_number_t_			enu_timerUsed;
	enu_timer_waveform_used_t_	enu_waveformUsed;
	enu_timer_prescaler_used_t_	enu_prescalerUsed;
}str_timer_config_t_;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
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
*******************************************************************************/
enu_timer_error_t_ timer_init( void );

/******************************************************************************
* @Syntax          : enu_timer_error_t_ timer_set_time
*					 (enu_timer_number_t_ enu_timer_used, f32_t_ f32_desired_time)
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
enu_timer_error_t_ timer_set_time(enu_timer_number_t_ enu_timer_used, f32_t_ f32_desired_time);

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
enu_timer_error_t_ timer_resume(enu_timer_number_t_ enu_timer_used);

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
enu_timer_error_t_ timer_pause(enu_timer_number_t_ enu_timer_used);

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
enu_timer_error_t_ timer_disable_interrupt(enu_timer_number_t_ enu_timer_used);

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
enu_timer_error_t_ timer_enable_interrupt(enu_timer_number_t_ enu_timer_used);

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
enu_timer_error_t_ timer_set_callback(enu_timer_number_t_ enu_timer_used, void (*funPtr)(void));


#endif /* TIMER_INTERFACE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: timer_interface.h
 *********************************************************************************************************************/