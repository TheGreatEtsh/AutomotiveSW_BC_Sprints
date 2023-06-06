/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	3:35 PM Tuesday, June 6, 2023
 *		   @File:  	dio_interface.h         
 *		 @Module:  	dio
 *		 @Author:	Ahmed Hesham
 *		 @E-mail:	ahmedhesham606@icloud.com
 *		 @github:	https://github.com/TheGreatEtsh
 *  @Description:  	Private file for dio module     
 *********************************************************************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


/************************************************************************/
/*							DIO_REGISTERS								*/
/************************************************************************/
// PORTD registers
#define PIND		(*((volatile uint8_t*)(0x30)))
#define DDRD		(*((volatile uint8_t*)(0x31)))
#define PORTD		(*((volatile uint8_t*)(0x32)))

// PORTC registers
#define PINC		(*((volatile uint8_t*)(0x33)))
#define DDRC		(*((volatile uint8_t*)(0x34)))
#define PORTC		(*((volatile uint8_t*)(0x35)))

// PORTB registers
#define PINB 		(*((volatile uint8_t*)(0x36)))
#define DDRB		(*((volatile uint8_t*)(0x37)))
#define PORTB		(*((volatile uint8_t*)(0x38)))

// PORTA registers
#define	PINA		(*((volatile uint8_t*)0x39))
#define	DDRA		(*((volatile uint8_t*)0x3A))
#define PORTA		(*((volatile uint8_t*)0x3B))



#endif /* DIO_PRIVATE_H_ */