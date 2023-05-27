/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	11:04 PM Saturday, May 13, 2023
 *		   @File:  	dio_interface.h         
 *		 @Module:  	DIO
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for DIO module     
 *  
 *********************************************************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/std.h"
#include "../../LIB/bit_math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 /***************************************_ERROR_TYPES_***************************************/
typedef enum dioError
{
	DIO_OK = 0,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_VALUE,
	DIO_WRONG_DIRECTION
}enu_DIO_status_t;
	
 /***************************************_PORTS_NAMES_***************************************/	
typedef enum
{
	DIO_PORT_A = 'A',
	DIO_PORT_B,
    DIO_PORT_C,
	DIO_PORT_D
}en_DIO_portName_t;


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
	DIO_P7,

}en_DIO_pinName_t;

 /***************************************_DIRECTIONS_***************************************/	
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT
}en_DIO_direction_t;

 /**************************************_SIGNAL_LEVELS_***************************************/
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH
}en_DIO_level_t;

typedef enum
{
	DIO_PULLUP_DISABLE,
	DIO_PULLUP_ENABLE
}enu_DIO_pullUp;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : enu_DIO_status_t DIO_init(u8 uint8_portNumber, u8 uint8_pinNumber, u8 uint8_direction)
* \Description     : Initializes DIO pins’ direction, output current.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_portNumber	port number used
*					 uint8_pinNumber		pin number used
*					 uint8_direction		direction of the pin
* \Parameters (out): None
* \Return value:   : enu_DIO_status_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_DIRECTION
*******************************************************************************/
enu_DIO_status_t DIO_init(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_direction);

/******************************************************************************
* \Syntax          : enu_DIO_status_t DIO_write(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_value)
* \Description     : Write on DIO pins’ a specific output High or Low.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_portNumber	port number used
*					 uint8_pinNumber		pin number used
*					 uint8_value			output value on the pin
* \Parameters (out): None
* \Return value:   : enu_DIO_status_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_VALUE
*******************************************************************************/
enu_DIO_status_t DIO_write(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_value);

/******************************************************************************
* \Syntax          : enu_DIO_status_t DIO_toggle(uint8_t uint8_portNumber, uint8_t uint8_pinNumber)
* \Description     : Toggle the output of a specific pin.
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_portNumber	port number used
*					 uint8_pinNumber		pin number used
* \Parameters (out): None
* \Return value:   : enu_DIO_status_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*******************************************************************************/
enu_DIO_status_t DIO_toggle(uint8_t uint8_portNumber, uint8_t uint8_pinNumber);
						
/******************************************************************************
* \Syntax          : enu_DIO_status_t DIO_read(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t *uint8_value)
* \Description     : Read input from a pin and send it back in a pointer to uint8_t
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_portNumber	port number used
*					 uint8_pinNumber		pin number used
* \Parameters (out): uint8_value			input value will be returned in that parameter
* \Return value:   : enu_DIO_status_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*******************************************************************************/
enu_DIO_status_t DIO_read(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t* uint8_value);	

/******************************************************************************
* \Syntax          : enu_DIO_status_t DIO_pinPullUp(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_pullUpState)
* \Description     : Disables/enables a pull up resistor to a specific input pin
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_portNumber	port number used
*					 uint8_pinNumber		pin number used
* \Parameters (out): None
* \Return value:   : enu_DIO_status_t		DIO_OK
*										WRONG_PIN_NUMBER
*										WRONG_PORT_NUMBER
*										WRONG_VALUE
*******************************************************************************/
enu_DIO_status_t DIO_pinPullUp(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_pullUpState);
	

#endif /* DIO_INTERFACE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: dio_interface.h
 *********************************************************************************************************************/
