/*
 * Registers.h
 *
 * Created: 4/3/2023 4:06:53 PM
 * Author : Ahmed Hesham
 * email  : ahmedhesham606@ilcoud.com
 */ 
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "../Service/standardTypes.h"

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

/********************************_INTERRUPTS_REGISTERS_**********************************/
#define MCUCR		(*((volatile uint8_t*)0x55))			/*MCU Control Register*/
#define ISC00		bit0
#define ISC01		bit1
#define ISC10		bit2
#define ISC11		bit3

#define MCUCSR		(*((volatile uint8_t*)0x54))			/*MCU Control and Status Register*/
#define ISC2		bit6
#define WDRF		bit3

#define GICR		(*((volatile uint8_t*)0x5B))			/*General Interrupt Control Register*/
#define INT1		bit7
#define INT0		bit6
#define INT2		bit5

/********************************_SREG_REGISTER_**********************************/
#define SREG		(*((volatile uint8_t*)0x5F))			/*AVR Status Register*/
#define Ibit		bit7							/*Global Interrupt Enable*/

#endif // !REGISTERS_H_
