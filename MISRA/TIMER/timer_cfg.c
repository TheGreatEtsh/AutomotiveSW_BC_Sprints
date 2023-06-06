/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *         @Date:  	5:34 PM Monday, May 15, 2023
 *		   @File:  	timer_cfg.c         
 *		 @Module:  	Timer
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Linking configuration file for Timer module     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "timer_interface.h"
#include "timer_cfg.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 const str_timer_config_t str_timer_config [NUMBER_OF_TIMERS_USED] =
{
/*	timer_number,	waveformUsed,	prescalerUsed	*/
	{TIMER_0,		TIMER_OV,		TIMER_PRESCLNG_64}
};
 
/**********************************************************************************************************************
 *  END OF FILE: timer_cfg.c
 *********************************************************************************************************************/
