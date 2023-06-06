/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	11:04 PM Saturday, May 13, 2023
 *		   @File:  	dio_interface.h         
 *		 @Module:  	dio
 *		 @Author:	Ahmed Hesham
 *  	 @E-mail:	ahmedhesham606@icloud.com
 *		 @github:	https://github.com/TheGreatEtsh
 *  @Description:  	Interfacing file for dio module     
 *  
 *********************************************************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 /***************************************_ERROR_t_YPES_***************************************/
typedef enum
{
	DIO_OK = 0,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_VALUE,
	DIO_WRONG_DIRECTION
}enu_dio_status_t_;
	
 /***************************************_PORTS_NAMES_***************************************/	
typedef enum
{
	DIO_PORT_A = 'A',
	DIO_PORT_B,
    DIO_PORT_C,
	DIO_PORT_D
}enu_dio_portName_t_;


/***************************************_PIN_NAMES_***************************************/	
typedef enum
{
	DIO_P0 = 0,
	DIO_P1,
	DIO_P2,
	DIO_P3,
	DIO_P4,
	DIO_P5,
	DIO_P6,
	DIO_P7
}enu_dio_pin_name_t_;

 /***************************************_DIRECTIONS_***************************************/	
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT
}enu_dio_direction_t_;

 /**************************************_SIGNAL_LEVELS_***************************************/
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH
}enu_dio_level_t_;

typedef enum
{
	DIO_PULLUP_DISABLE,
	DIO_PULLUP_ENABLE
}enu_dio_pullUp;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : enu_dio_status_t_ dio_init(u8 uint8_port_number, u8 uint8_pin_number, u8 uint8_direction)
* \Description     : Initializes dio pins’ direction, output current.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_port_number	port number used
*					 uint8_pin_number		pin number used
*					 uint8_direction		direction of the pin
* \Parameters (out): None
* \Return value:   : enu_dio_status_t_	DIO_OK
*										DIO_WRONG_PIN_NUMBER
*										DIO_WRONG_PORT_NUMBER
*										DIO_WRONG_DIRECTION
*******************************************************************************/
enu_dio_status_t_ dio_init(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number, uint8_t_ uint8_direction);

/******************************************************************************
* \Syntax          : enu_dio_status_t_ dio_write(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number, uint8_t_ uint8_value)
* \Description     : Write on dio pins’ a specific output High or Low.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_port_number	port number used
*					 uint8_pin_number		pin number used
*					 uint8_value			output value on the pin
* \Parameters (out): None
* \Return value:   : enu_dio_status_t_	DIO_OK
*										DIO_WRONG_PIN_NUMBER
*										DIO_WRONG_PORT_NUMBER
*										DIO_WRONG_VALUE
*******************************************************************************/
enu_dio_status_t_ dio_write(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number, uint8_t_ uint8_value);

/******************************************************************************
* @Syntax          : enu_dio_status_t_ dio_toggle(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number)
* @Description     : Toggle the output of a specific pin.
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Param (in) 	   : uint8_port_number	port number used
*					 uint8_pin_number		pin number used
* @Param 	  (out): None
* @Return value:   : enu_dio_status_t_	DIO_OK
*										DIO_WRONG_PIN_NUMBER
*										DIO_WRONG_PORT_NUMBER
*******************************************************************************/
enu_dio_status_t_ dio_toggle(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number);
						
/******************************************************************************
* \Syntax          : enu_dio_status_t_ dio_read(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number, uint8_t_ *uint8_value)
* \Description     : Read input from a pin and send it back in a pointer to uint8_t_
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_port_number	port number used
*					 uint8_pin_number	pin number used
* \Parameters (out): uint8_value		input value will be returned in that parameter
* \Return value:   : enu_dio_status_t_	DIO_OK
*										DIO_WRONG_PIN_NUMBER
*										DIO_WRONG_PORT_NUMBER
*******************************************************************************/
enu_dio_status_t_ dio_read(uint8_t_ uint8_port_number, uint8_t_ uint8_pin_number, uint8_t_* ptr_uint8_value);	


#endif /* DIO_INTERFACE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: dio_interface.h
 *********************************************************************************************************************/
