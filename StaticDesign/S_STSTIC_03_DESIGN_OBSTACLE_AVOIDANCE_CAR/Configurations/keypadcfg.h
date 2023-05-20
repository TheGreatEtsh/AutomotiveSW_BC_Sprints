/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *
 *		   @Date:  	3:32 PM Sunday, May 14, 2023
 *		   @File:  	keypadcfg.h         
 *		 @Module:  	Keypad
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Pre-configuration file for Keypad module     
 *  
 *********************************************************************************************************************/
#ifndef <KEYPADCFG_H>
#define <KEYPADCFG_H>
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "keypad.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define KEYPAD_NUMBER_OF_ROWS		3
#define KEYPAD_NUMBER_OF_COLUMNS	3

#define KEYPAD_R0_PORT				DIO_PORT_C
#define KEYPAD_R1_PORT				DIO_PORT_C
#define KEYPAD_R2_PORT				DIO_PORT_C
			
#define KEYPAD_C0_PORT				DIO_PORT_C
#define KEYPAD_C1_PORT				DIO_PORT_C
#define KEYPAD_C2_PORT				DIO_PORT_C
			
#define KEYPAD_R0_PIN				DIO_PC2
#define KEYPAD_R1_PIN				DIO_PC3
#define KEYPAD_R2_PIN				DIO_PC4
			
#define KEYPAD_C0_PIN				DIO_PC5
#define KEYPAD_C1_PIN				DIO_PC6
#define KEYPAD_C2_PIN				DIO_PC7

 
#endif  /* KEYPADCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: keypadcfg.h
 *********************************************************************************************************************/
