/*
 * extint.h
 *
 * Created: 4/5/2023 4:41:05 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

//#include "../registers.h"
#include "bit_math.h"
#include "interrupts.h"
#include "std.h"

/************************************************************************/
/*						EXTERNAL_INTERRUPTS_REGISTERS					*/
/************************************************************************/
#define MCUCR		(*((volatile uint8_t_*)0x55))			/*MCU Control Register*/
#define ISC00		bit0
#define ISC01		bit1
#define ISC10		bit2
#define ISC11		bit3

#define MCUCSR		(*((volatile uint8_t_*)0x54))			/*MCU Control and Status Register*/
#define ISC2		bit6
#define WDRF		bit3

#define GICR		(*((volatile uint8_t_*)0x5B))			/*General Interrupt Control Register*/
#define INT1		bit7
#define INT0		bit6
#define INT2		bit5

/************************************************************************/
/*							STATUS_REGISTER								*/
/************************************************************************/
#define SREG		(*((volatile uint8_t_*)0x5F))			/*AVR Status Register*/
#define Ibit		bit7									/*Global Interrupt Enable*/




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/****************************************_INTERRUPT_USED_***************************************/
#define INT_0									0
#define INT_1									1
#define INT_2									2

/*******************************************_SENSE_TYPES_***************************************/
#define LOW_LEVEL								1
#define ANY_CHANGE								2
#define FALLING_EDGE							3
#define RISING_EDGE								4

/******************************************_CONFIGURATIONS_***************************************/
/****************************************_SENSE_CONTROL_MODE_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *	OPTION 1	->		LOW_LEVEL
 *	OPTION 2	->		ANY_CHANGE
 *	OPTION 3	->		FALLING_EDGE
 *	OPTION 4	->		RISING_EDGE	
 */

#define SENSE_CONTROL_0		RISING_EDGE

/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT1
 *	OPTION 1	->		LOW_LEVEL
 *	OPTION 2	->		ANY_CHANGE
 *	OPTION 3	->		FALLING_EDGE
 *	OPTION 4	->		RISING_EDGE	
 */

#define SENSE_CONTROL_1		RISING_EDGE

/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT2
 *	OPTION 1	->		FALLING_EDGE
 *	OPTION 2	->		RISING_EDGE	
 */

#define SENSE_CONTROL_2		RISING_EDGE

/**********************************************************************************************************************
 *  GLOBAL TYPEDEFS DATA TYPES
 *********************************************************************************************************************/
typedef enum extintError{
	EXTINT_OK,
	WRONG_INT_NUMBER
	}EN_extintError_t; 


typedef enum{
	bit0,
	bit1,
	bit2,
	bit3,
	bit4,
	bit5,
	bit6,
	bit7
}EN_bitNumber_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/***************************************_PROTOTYPES_***************************************/

/*
 *	CHOOSE EXTERNAL INTERRUPT 
 *	OPTION 1	->		INT_0
 *	OPTION 2	->		INT_1
 *	OPTION 3	->		INT_2
 */
EN_extintError_t EXTINT_Init (uint8_t_ intNumber);

void EXTINT_setCallBackInt (uint8_t_ intNumber, void (*funPtr) (void));




#endif /* EXTINT_H_ */