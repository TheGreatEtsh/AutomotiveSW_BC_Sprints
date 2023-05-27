/*
 * dio.c
 *
 * Created: 4/3/2023 4:15:37 PM
 *  Author: Ahmed Hesham
 */ 

#include "dio_interface.h"
#include "dio_private.h"
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

enu_DIO_status_t DIO_init(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_direction)
{
	enu_DIO_status_t error = DIO_OK;
	if (uint8_pinNumber < 8)
	{
		
		switch(uint8_direction)
		{
			case DIO_INPUT:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	DDRA &= ~ (1<<uint8_pinNumber);	break;
				case DIO_PORT_B:	DDRB &= ~ (1<<uint8_pinNumber);	break;
				case DIO_PORT_C:	DDRC &= ~ (1<<uint8_pinNumber);	break;
				case DIO_PORT_D:	DDRD &= ~ (1<<uint8_pinNumber);	break;
				default:		error = DIO_WRONG_PORT_NUMBER;	break;
			}
			break;
			
			case DIO_OUTPUT:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	DDRA |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_B:	DDRB |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_C:	DDRC |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_D:	DDRD |= (1<<uint8_pinNumber);		break;
				default:		error = DIO_WRONG_PORT_NUMBER;	break;
			}
			break;
			
			default:
			error = DIO_WRONG_DIRECTION;
			break;
		}
		
	}
	else
	{
		error = DIO_WRONG_PIN_NUMBER;
	}
	return error;
}


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

enu_DIO_status_t DIO_write(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_value)		// Write data to dio
{
	enu_DIO_status_t error = DIO_OK;
	if (uint8_pinNumber < 8)
	{
		switch(uint8_value)
		{
			case DIO_LOW:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	PORTA &= ~ (1<<uint8_pinNumber);		break;
				case DIO_PORT_B:	PORTB &= ~ (1<<uint8_pinNumber);		break;
				case DIO_PORT_C:	PORTC &= ~ (1<<uint8_pinNumber);		break;
				case DIO_PORT_D:	PORTD &= ~ (1<<uint8_pinNumber);		break;
				default:		error = DIO_WRONG_PORT_NUMBER;		break;
			}
			break;
				
			case DIO_HIGH:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	PORTA |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_B:	PORTB |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_C:	PORTC |= (1<<uint8_pinNumber);		break;
				case DIO_PORT_D:	PORTD |= (1<<uint8_pinNumber);		break;
				default:		error = DIO_WRONG_PORT_NUMBER;		break;
			}
			break;
				
			default:
				error = DIO_WRONG_VALUE;
				break;
		}
	}
	else
	{
		error = DIO_WRONG_PIN_NUMBER;
	}
	return error;

}


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
enu_DIO_status_t DIO_toggle(uint8_t uint8_portNumber, uint8_t uint8_pinNumber)						// Toggle dio
{
	enu_DIO_status_t error = DIO_OK;
	if (uint8_pinNumber < 8)
	{
		switch(uint8_portNumber)
		{
			case DIO_PORT_A:	TGL_BIT(PORTA,uint8_pinNumber);		break;
			case DIO_PORT_B:	TGL_BIT(PORTB,uint8_pinNumber);		break;
			case DIO_PORT_C:	TGL_BIT(PORTC,uint8_pinNumber);		break;
			case DIO_PORT_D:	TGL_BIT(PORTD,uint8_pinNumber);		break;
			default:		error = DIO_WRONG_PORT_NUMBER;		break;
		}	
	}
	else
	{
		error = DIO_WRONG_PIN_NUMBER;
	}
	return error;
}


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
enu_DIO_status_t DIO_read(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t *uint8_value)		// Read dio
{
	enu_DIO_status_t error = DIO_OK;
	if (uint8_pinNumber < 8)
	{

		switch(uint8_portNumber)
		{
			case DIO_PORT_A:	*uint8_value = GET_BIT(PINA,uint8_pinNumber);		break;
			case DIO_PORT_B:	*uint8_value = GET_BIT(PINB,uint8_pinNumber);		break;
			case DIO_PORT_C:	*uint8_value = GET_BIT(PINC,uint8_pinNumber);		break;
			case DIO_PORT_D:	*uint8_value = GET_BIT(PIND,uint8_pinNumber);		break;
			default:		error = DIO_WRONG_PORT_NUMBER;				break;
		}
	}
	else
	{
		error = DIO_WRONG_PIN_NUMBER;
	}
	return error;
}


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
enu_DIO_status_t DIO_pinPullUp(uint8_t uint8_portNumber, uint8_t uint8_pinNumber, uint8_t uint8_pullUpState)
{
	enu_DIO_status_t error = DIO_OK;
	if (uint8_pinNumber < 8)
	{
		switch(uint8_pullUpState)
		{
			case DIO_PULLUP_DISABLE:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	CLR_BIT(PORTA, uint8_pinNumber);		break;
				case DIO_PORT_B:	CLR_BIT(PORTB, uint8_pinNumber);		break;
				case DIO_PORT_C:	CLR_BIT(PORTC, uint8_pinNumber);		break;
				case DIO_PORT_D:	CLR_BIT(PORTD, uint8_pinNumber);		break;
				default:		error = DIO_WRONG_PORT_NUMBER;			break;
			}
			break;
			
			case DIO_PULLUP_ENABLE:
			switch(uint8_portNumber)
			{
				case DIO_PORT_A:	SET_BIT(PORTA, uint8_pinNumber);		break;
				case DIO_PORT_B:	SET_BIT(PORTB, uint8_pinNumber);		break;
				case DIO_PORT_C:	SET_BIT(PORTC, uint8_pinNumber);		break;
				case DIO_PORT_D:	SET_BIT(PORTD, uint8_pinNumber);		break;
				default:		error = DIO_WRONG_PORT_NUMBER;		break;
			}
			break;
			
			default:
			error = DIO_WRONG_VALUE;
			break;
		}
	}
	else
	{
		error = DIO_WRONG_PIN_NUMBER;
	}
	return error;

}