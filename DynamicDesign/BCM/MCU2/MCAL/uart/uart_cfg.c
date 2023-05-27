/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *         @Date:  	11/5/2023
 *		   @File:  	uartLCfg.c         
 *		 @Module:  	UART
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Linking configuration file for uart module     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "uart_interface.h"
#include "uart_cfg.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 const str_UART_config_t cst_str_UART_config [NUMBER_OF_UART_USED] = 
{
/*	UART_ID,	dataSize,	baudRate,			reciverState,	reciverIntState, 	transmitterState,	transmitterIntState		*/
	{UART_0,	UART_8_BIT,		UART_9600_BAUDRATE,	UART_RX_ENABLE, UART_RX_INT_ENABLE,	UART_TX_ENABLE,	UART_TX_INT_DISABLE},
};
 
/**********************************************************************************************************************
 *  END OF FILE: uartLCfg.c
 *********************************************************************************************************************/
