/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	10/5/2023
 *		   @File:  	uart.h         
 *		 @Module:  	UART
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for uart module     
 *  
 *********************************************************************************************************************/
#ifndef <UART_H>
#define <UART_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************_PARITY_MODE_OPTIONS_**********************************/
#define UART_PARITY_EVEN   			0
#define UART_PARITY_ODD    			1
#define UART_PARITY_DISABLE			2


/**********************************_MODE_SELECT_OPTIONS_**********************************/
#define UART_ASYNCHRONOUS			0
#define UART_SYNCHRONOUS            1
 

/*******************************_TANSMISSION_SPEED_OPTIONS_******************************/
#define UART_NORMAL_SPEED   		0
#define UART_DOUBLE_SPEED           1


/***********************************_STOP_BIT_OPTIONS_***********************************/
#define UART_STOP_1_BIT				0
#define UART_STOP_2_BIT             1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum 
{
	UART_5_BIT = 0,
	UART_6_BIT,
	UART_7_BIT,
	UART_8_BIT,	
	UART_9_BIT	
}en_UART_dataSize_t;

typedef enum
{
	UART_RX_INT_DISABLE = 0,
	UART_RX_INT_ENABLE
}en_UART_rxInt_t;

typedef enum
{
	UART_TX_INT_DISABLE = 0,
	UART_TX_INT_ENABLE
}en_UART_txInt_t;

 
typedef enum
{
	UART_RX_DISABLE = 0,
	UART_RX_ENABLE
}en_UART_rx_t;


typedef enum
{
	UART_TX_DISABLE = 0,
	UART_TX_ENABLE
}en_UART_tx_t;

typedef enum
{
	UART_2400_BAUDRATE = 0,
	UART_4800_BAUDRATE,
	UART_9600_BAUDRATE,
	UART_14400_BAUDRATE,
	UART_19200_BAUDRATE,
	UART_28800_BAUDRATE,
	UART_38400_BAUDRATE,
	UART_57600_BAUDRATE,
	UART_76800_BAUDRATE,
	UART_115200_BAUDRATE,
	UART_230400_BAUDRATE,
	UART_250000_BAUDRATE
}en_UART_baudRate_t;

typedef enum
{
	UART_0 = 0,
	UART_1,
	UART_3,
	UART_4,
	UART_5
}en_UART_number_t;

typedef struct
{
	en_UART_number_t 	uartUsed;
	en_UART_dataSize_t 	dataSize;
	en_UART_baudRate_t 	baudRateUsed;
	en_UART_rx_t		recieverState;
	en_UART_rxInt_t 	recieverIntState;
	en_UART_tx_t		transmitterState;
	en_UART_txInt_t 	transmitterIntState;
}st_UART_config_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
 
#endif  /* UART_H */
/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/