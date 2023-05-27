/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *         @Date:  	23/5/2023 7:13:52 PM
 *		   @File:  	uart_program.c         
 *		 @Module:  	UART
 *		 @Author:	Ahmed Hesham
 *  @Description:  	program file for uart module     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 #include "uart_interface.h"
 #include "uart_cfg.h"
 #include "uart_private.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/ 
 extern const str_UART_config_t cst_str_UART_config [NUMBER_OF_UART_USED];
 
 volatile uint8_t arr_g_recieveBuffer [UART_RECEIVE_BUFFER_SIZE];
 
 volatile enu_UART_rcvStrCmpltFlg_t enu_g_rcvStrCmpltFlg = UART_RCV_NCMPLT;  
 
 volatile uint16_t gluint16_dataSize;
 
 void (*glptr_callBackFunc)	(void) = NULL_PTR;
 
 /************************************************************************/
 /*						FUNCTIONS IMPLEMENTATIONS					  	 */
 /************************************************************************/
 
 enu_UART_status_t UART_init (void)
 {
	enu_UART_status_t returnValue = UART_OK;
	uint8_t UCSRCValue = 0;
	uint32_t UBRRValue = 0; 
	
	DIO_init(DIO_PORT_D,DIO_P0,DIO_INPUT);
	DIO_init(DIO_PORT_D,DIO_P1,DIO_OUTPUT);
	
	
	
	if (cst_str_UART_config[UART_0].recieverIntState  == UART_RX_INT_ENABLE)
	{
		SET_BIT(UCSRB, RXCIE);
	}
	else if (cst_str_UART_config[UART_0].recieverIntState == UART_RX_INT_DISABLE)
	{
		CLR_BIT(UCSRB, RXCIE);
	}
	else
	{
		returnValue = UART_NOK;
	}
	
	if (cst_str_UART_config[UART_0].transmitterIntState == UART_TX_INT_ENABLE)
	{
		SET_BIT(UCSRB, TXCIE);
	}
	else if (cst_str_UART_config[UART_0].transmitterIntState == UART_TX_INT_DISABLE)
	{
		CLR_BIT(UCSRB, TXCIE);
	}
	else
	{
		returnValue = UART_NOK;
	}
	
	if (cst_str_UART_config[UART_0].recieverState == UART_RX_ENABLE)
	{
		SET_BIT(UCSRB, RXEN);
	}
	else if (cst_str_UART_config[UART_0].recieverState == UART_RX_DISABLE)
	{
		CLR_BIT(UCSRB, RXEN);
	}
	else
	{
		returnValue = UART_NOK;
	}
		 
	if (cst_str_UART_config[UART_0].transmitterState == UART_TX_ENABLE)
	{
		SET_BIT(UCSRB, TXEN);
	}
	else if (cst_str_UART_config[UART_0].transmitterState == UART_TX_DISABLE)
	{
		CLR_BIT(UCSRB, TXEN);
	}
	else
	{
		returnValue = UART_NOK;
	}
	
	#if UART_MODE_SELECT == UART_ASYNCHRONOUS
		CLR_BIT(UCSRCValue,UMSEL); 
		
		#if UART_TRANSMISSION_SPEED == UART_NORMAL_SPEED
		CLR_BIT(UCSRA,U2X);
		
		switch(cst_str_UART_config[UART_0].baudRateUsed)
		{
			case UART_2400_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 2400) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_4800_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 4800) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_9600_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 9600) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_14400_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 14400) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_19200_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 19200) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_28800_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 28800) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_38400_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 38400) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_57600_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 57600) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_76800_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 76800) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_115200_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 115200) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_230400_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 230400) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			case UART_250000_BAUDRATE:
			UBRRValue = ( F_CPU/ ((uint32_t)16 * 250000) ) - 1;
			UBRRL = UBRRValue;
			UBRRH = (UBRRValue >> 8);
			break;
			
			default:
			returnValue = UART_NOK;
			break;
		}
		#elif UART_TRANSMISSION_SPEED == UART_DOUBLE_SPEED
		SET_BIT(UCSRA,U2X);
		/*TO BE IMPLEMENTED*/
		#else
		returnValue = UART_NOK
		#endif
		
	#elif UART_MODE_SELECT == UART_SYNCHRONOUS
		SET_BIT(UCSRCValue,UMSEL);
	#else
		returnValue = UART_NOK
	#endif
	
	#if UART_PARITY_MODE == UART_PARITY_DISABLE
		CLR_BIT(UCSRCValue,UPM1);	CLR_BIT(UCSRCValue,UPM0);
	#elif UART_PARITY_MODE == UART_PARITY_EVEN
		SET_BIT(UCSRCValue,UPM1);	CLR_BIT(UCSRCValue,UPM0);
	#elif UART_PARITY_MODE == UART_PARITY_ODD
		SET_BIT(UCSRCValue,UPM1);	SET_BIT(UCSRCValue,UPM0);
	#else
	returnValue = UART_NOK
	#endif
	
	#if UART_STOP_BITS == UART_STOP_1_BIT
	CLR_BIT(UCSRCValue,USBS);	
	#elif UART_STOP_BITS == UART_STOP_2_BIT
	SET_BIT(UCSRCValue,USBS);	
	#else
	returnValue = UART_NOK
	#endif
	
	switch(cst_str_UART_config[UART_0].dataSize)
	{
		case UART_5_BIT: 
		CLR_BIT(UCSRCValue,UCSZ2);	CLR_BIT(UCSRCValue,UCSZ1);	CLR_BIT(UCSRCValue,UCSZ0);		
		break; 
		
		case UART_6_BIT: 
		CLR_BIT(UCSRCValue,UCSZ2);	CLR_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);		
		break;
		
		case UART_7_BIT: 
		CLR_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	CLR_BIT(UCSRCValue,UCSZ0);		
		break;
		
		case UART_8_BIT: 
		CLR_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);		
		break;
		
		case UART_9_BIT: 
		SET_BIT(UCSRCValue,UCSZ2);	SET_BIT(UCSRCValue,UCSZ1);	SET_BIT(UCSRCValue,UCSZ0);		
		break;
		
		default:
		returnValue = UART_NOK;
		break;
	}
	
	if (returnValue == UART_OK)
	{
		SET_BIT(UCSRCValue,URSEL); 
		UCSRC = UCSRCValue;
	}
	else
	{
		/*DO NOTHING*/
	}
	
	
	SET_BIT(SREG, Ibit);
	
	return returnValue;
 }
 
 enu_UART_status_t UART_deinit (void)
 {
	 enu_UART_status_t returnValue = UART_OK;
	 UCSRB = 0;
	 return returnValue;
 }
 
 enu_UART_bufferStatus_t UART_isEmpty (void)
 {
	 enu_UART_bufferStatus_t returnValue = UART_BUFFER_EMPTY;
	 if (GET_BIT(UCSRA, UDRE) == UART_BUFFER_EMPTY)
	 {
		 /*BUFFER IS EMPTY*/
	 }
	 else
	 {
		 returnValue = UART_BUFFER_NEMPTY;
	 }
	 return returnValue;
 }
 enu_UART_status_t UART_sendByte (uint8_t u8_a_byte)
 {
	 enu_UART_status_t returnValue = UART_OK;
	 if (GET_BIT(UCSRA, UDRE) == UART_BUFFER_EMPTY)
	 {
		 UDR = u8_a_byte;
	 }
	 else  
	 {
		 returnValue = UART_SENDING;
	 } 
	 return returnValue;
 }
 
enu_UART_status_t UART_receiveData(uint8_t** ptr_uint8_receivedData, uint16_t* uint16_dataSize)
{
	enu_UART_status_t returnValue = UART_OK;
	*ptr_uint8_receivedData =  arr_g_recieveBuffer;
	*uint16_dataSize = gluint16_dataSize;
	return returnValue;
}


enu_UART_status_t UART_setCallBack (void (*ptr_func)(void))
{
	/*TO BE IMPLEMENTED*/
	enu_UART_status_t returnValue = UART_OK;
	if(NULL_PTR != ptr_func)
	{
		glptr_callBackFunc = ptr_func;
	}
	else
	{
		returnValue = UART_NOK;
	}
	return returnValue;
}
  
 
 ISR(USART_RXC_INT)
 {
	 static uint16_t counter = 0;
	 static enu_UART_rcvMode_t receiveMode = UART_DATA_SIZE;
	  

	if (receiveMode == UART_DATA_SIZE)
	{
		if(counter == 0)
		{
			gluint16_dataSize = (UDR * 256);
			counter = 1;
		}
		else if (counter == 1)
		{
			gluint16_dataSize += UDR;
			receiveMode = UART_DATA;
			counter = 0;
		}
		else
		{
			
			/*DO NOTHING*/
		}
	}
	else if (receiveMode == UART_DATA)
	{
		
		if(counter < gluint16_dataSize)
		{
			arr_g_recieveBuffer[counter] = UDR;
			counter++;
			if(counter == gluint16_dataSize)
			{
				
				if (NULL_PTR != glptr_callBackFunc)
				{
					glptr_callBackFunc();
				}
				else
				{
					/*DO NOTHING*/
				}
				counter = 0;
				gluint16_dataSize = 0;
				receiveMode = UART_DATA_SIZE;
			}
			
		}
		else
		{
			/*DO NOTHING*/
		}
	}
	 
	 
 }
/**********************************************************************************************************************
 *  END OF FILE: uart.c
 *********************************************************************************************************************/
