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

#endif // !REGISTERS_H_
