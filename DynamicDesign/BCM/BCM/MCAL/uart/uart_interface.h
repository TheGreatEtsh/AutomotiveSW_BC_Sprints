/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *
 *		   @Date:  	23/5/2023
 *		   @File:  	uart_interface.h         
 *		 @Module:  	UART
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for uart module     
 *  
 *********************************************************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/std.h"
#include "../../LIB/interrupts.h"
#include "../../LIB/bit_math.h"
#include "../dio/dio_interface.h"
#include "../../ECUAL/led/led_interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/ 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************_PARITY_MODE_OPTIONS_**********************************/
typedef enum
{
	UART_PARITY_EVEN = 0,
	UART_PARITY_ODD,    
	UART_PARITY_DISABLE
}enu_UART_parity_t;


/**********************************_MODE_SELECT_OPTIONS_**********************************/
typedef enum
{
	UART_ASYNCHRONOUS = 0,
	UART_SYNCHRONOUS
}enu_UART_synch_t;


typedef enum 
{
	UART_5_BIT = 0,
	UART_6_BIT,
	UART_7_BIT,
	UART_8_BIT,	
	UART_9_BIT	
}enu_UART_dataSize_t;

/*******************************_TANSMISSION_SPEED_OPTIONS_******************************/
typedef enum
{
	UART_NORMAL_SPEED = 0,
	UART_DOUBLE_SPEED
}enu_UART_transSpeed_t;


/***********************************_STOP_BIT_OPTIONS_***********************************/
typedef enum
{
	UART_STOP_1_BIT = 0,
	UART_STOP_2_BIT
}enu_UART_stopBits_t;


typedef enum
{
	UART_RX_INT_DISABLE = 0,
	UART_RX_INT_ENABLE
}enu_UART_rxInt_t;

typedef enum
{
	UART_TX_INT_DISABLE = 0,
	UART_TX_INT_ENABLE
}enu_UART_txInt_t;

 
typedef enum
{
	UART_RX_DISABLE = 0,
	UART_RX_ENABLE
}enu_UART_rx_t;


typedef enum
{
	UART_TX_DISABLE = 0,
	UART_TX_ENABLE
}enu_UART_tx_t;

typedef enum
{
	UART_BUFFER_NEMPTY = 0,
	UART_BUFFER_EMPTY 	
}enu_UART_bufferStatus_t;

typedef enum
{
	UART_RCV_CMPLT,
	UART_RCV_NCMPLT	
}enu_UART_rcvStrCmpltFlg_t;
 
typedef enum
{
	UART_DATA_SIZE = 0,
	UART_DATA	
}enu_UART_rcvMode_t;

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
}enu_UART_baudRate_t;

typedef enum
{
	UART_OK = 0,
	UART_SENDING = 1,
	UART_RECIEVE = 1,
	UART_NOK
}enu_UART_status_t;

typedef struct
{
	uint8_t			 		uartUsed;
	enu_UART_dataSize_t 	dataSize;
	enu_UART_baudRate_t 	baudRateUsed;
	enu_UART_rx_t			recieverState;
	enu_UART_rxInt_t 		recieverIntState;
	enu_UART_tx_t			transmitterState;
	enu_UART_txInt_t 		transmitterIntState;
}str_UART_config_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 /**
 * \Syntax          : UART_init(void)
 * \Description     : Initializes UART pins’ direction, and specifications
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	UART_OK = 0,
 *										UART_NOK
 */
 enu_UART_status_t UART_init (void);
 
 /**
 * \Syntax          : UART_deinit(void)
 * \Description     : Deinitializes UART 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	UART_OK = 0,
 *										UART_NOK
 */
 enu_UART_status_t UART_deinit (void);
 
 /**
 * \Syntax          : UART_sendByte (uint8_t uint8_byte)
 * \Description     : Sending one byte through UART channel
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : uint8_byte
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	UART_OK = 0,
 *										UART_SENDING,
 *										UART_NOK
 */
 enu_UART_status_t UART_sendByte (uint8_t uint8_byte);
 
 /**
 * \Syntax          : UART_setCallBack (void (*ptr_func)(void))
 * \Description     : Set callback function
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : void (*ptr_func) (void)
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	UART_OK = 0,
 *										UART_NOK
 */
 enu_UART_status_t UART_setCallBack (void (*ptr_func)(void));
 
 /**
 * \Syntax          : UART_receiveData(uint8_t** ptr_ptr_uint8_receivedData, uint16_t* ptr_uint16_dataSize)
 * \Description     : Receives data buffer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): ptr_ptr_uint8_receivedData
 *					  ptr_uint16_dataSize
 * \Return value:   : enu_UART_status_t	UART_OK = 0,
 *										UART_NOK
 */
 enu_UART_status_t UART_receiveData(uint8_t** ptr_ptr_uint8_receivedData, uint16_t* ptr_uint16_dataSize);
 
 /**
 * \Syntax          : UART_isEmpty (void)
 * \Description     : Checks if data register is empty
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	UART_BUFFER_NEMPTY = 0,
 *										UART_BUFFER_EMPTY
 */
 enu_UART_bufferStatus_t UART_isEmpty (void);
 
#endif  /* UART_H */
/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/