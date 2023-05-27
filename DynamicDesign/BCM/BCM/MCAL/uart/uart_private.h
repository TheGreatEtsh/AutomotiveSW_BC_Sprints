/**
 * uart_private.h
 *
 * Created: 5/23/2023 3:30:46 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


typedef enum
{
	BIT_0 = 0,
	BIT_1,
	BIT_2,
	BIT_3,
	BIT_4,
	BIT_5,
	BIT_6,
	BIT_7
}enu_bitNumber_t;

/************************************************************************/
/*							UART_REGISTERS								*/
/************************************************************************/
#define UDR		(*((volatile uint8_t*)(0x2C)))
#define UCSRA	(*((volatile uint8_t*)(0x2B)))
#define RXC		BIT_7
#define	TXC	    BIT_6
#define UDRE	BIT_5
#define FE		BIT_4
#define DOR		BIT_3
#define PE		BIT_2
#define U2X		BIT_1
#define MPCM	BIT_0

#define UCSRB	(*((volatile uint8_t*)(0x2A)))
#define RXCIE	BIT_7
#define	TXCIE   BIT_6
#define UDRIE   BIT_5
#define RXEN	BIT_4
#define TXEN	BIT_3
#define UCSZ2	BIT_2
#define RXB8	BIT_1
#define TXB8	BIT_0

#define UCSRC	(*((volatile uint8_t*)(0x40)))
#define URSEL	BIT_7
#define	UMSEL   BIT_6
#define UPM1    BIT_5
#define UPM0	BIT_4
#define USBS	BIT_3
#define UCSZ1	BIT_2
#define UCSZ0	BIT_1
#define UCPOL	BIT_0


#define UBRRH	(*((volatile uint8_t*)(0x40)))

#define UBRRL	(*((volatile uint8_t*)(0x29)))

/************************************************************************/
/*							STATUS_REGISTER								*/
/************************************************************************/
#define SREG		(*((volatile uint8_t*)0x5F))			/*AVR Status Register*/
#define Ibit		BIT_7									/*Global Interrupt Enable*/



#endif /* UART_PRIVATE_H_ */