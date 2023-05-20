/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *         @Date:  	3:13 PM Sunday, May 14, 2023
 *		   @File:  	buttonlcfg.c         
 *		 @Module:  	Button
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Linking configuration file for Button module     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "button.h"
#include "buttoncfg.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 const st_BUTTON_config_t st_BUTTON_config [NUMBER_OF_MOTORS_USED] = 
{
/*	 BUTTON_#,  PORT_#,	   PIN_#*/
	{BUTTON_0, DIO_PORT_C, DIO_PC4}
};
 
/**********************************************************************************************************************
 *  END OF FILE: buttonlcfg.c
 *********************************************************************************************************************/
