/*
 * bcm_program.c
 *
 * Created: 5/23/2023 9:21:53 PM
 *  Author: Ahmed Hesham
 */ 
#include "bcm_cfg.h"
#include "bcm_interface.h"

extern const str_BCM_config_t cst_str_BCM_config [BCM_NUMBER_OF_CHANNELS];

uint8_t gluint8_dataToBeSend = 0;

uint16_t gluint8_dataLocation [10];

uint8_t gluint8_data [BCM_BUFFER_SIZE];

sint16_t glsint16_front = -1, glsint16_rear = -1;

void (*ptr_BCM_callBackFunc) (void) = NULL_PTR;


enu_BCM_status_t	BCM_init		(str_BCM_instance_t* ptr_str_BCM_instance)
{
	enu_BCM_status_t returnValue = BCM_OK;
	for(uint8_t counter = 0; counter < BCM_NUMBER_OF_CHANNELS; counter++)	
	{
		returnValue = BCM_NOK;
		if (cst_str_BCM_config[counter].dataID == ptr_str_BCM_instance->dataType)
		{
			if(cst_str_BCM_config[counter].busID == BCM_UART)
			{
				returnValue = BCM_OK;
				UART_init();
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_SPI)
			{
				returnValue = BCM_OK;
				/*SPI_init()*/
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_I2C)
			{
				returnValue = BCM_OK;
				/*I2C_init()*/
				break;
			}
			else
			{
				/*BCM_NOK*/
				break;
			}
		}
	}
	return returnValue;
}

enu_BCM_status_t	BCM_deinit		(str_BCM_instance_t* ptr_str_BCM_instance)
{
	enu_BCM_status_t returnValue = BCM_OK;
	for(uint8_t counter = 0; counter < BCM_NUMBER_OF_CHANNELS; counter++)
	{
		returnValue = BCM_NOK;
		if (cst_str_BCM_config[counter].dataID == ptr_str_BCM_instance->dataType)
		{
			if(cst_str_BCM_config[counter].busID == BCM_UART)
			{
				returnValue = BCM_OK;
				UART_deinit();
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_SPI)
			{
				returnValue = BCM_OK;
				/*SPI_deinit()*/
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_I2C)
			{
				returnValue = BCM_OK;
				/*I2C_deinit()*/
				break;
			}
			else
			{
				/*BCM_NOK*/
				break;
			}
		}
	}
	return returnValue;	
}


enu_BCM_status_t	BCM_send_n		(str_BCM_instance_t* ptr_str_BCM_instance)
{
	enu_BCM_status_t returnValue = BCM_OK;
	uint16_t sizeOfBuffer = 0, availableSize = 0;
	enu_BCM_busID_t busUsed = BCM_UART;
	uint8_t sizeHigherByte = 0, sizeLowerByte = 0;
	
	sizeOfBuffer = sizeof(gluint8_data)/sizeof(gluint8_data[0]); 
	
	for(uint8_t counter = 0; counter < BCM_NUMBER_OF_CHANNELS; counter++)
	{
		returnValue = BCM_NOK;
		if (cst_str_BCM_config[counter].dataID == ptr_str_BCM_instance->dataType)
		{
			if(cst_str_BCM_config[counter].busID == BCM_UART)
			{
				returnValue = BCM_OK;
				busUsed = BCM_UART;
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_SPI)
			{
				returnValue = BCM_OK;
				busUsed = BCM_SPI;
				break;
			}
			else if (cst_str_BCM_config[counter].busID == BCM_I2C)
			{
				returnValue = BCM_OK;
				busUsed = BCM_I2C;
				break;
			}
			else
			{
				/*BCM_NOK*/
				break;
			}
		}
	}
	
	if (glsint16_rear < glsint16_front)
	{
		availableSize = sizeOfBuffer - (glsint16_rear + glsint16_front);
	}
	else if (glsint16_rear > glsint16_front)	
	{	
		availableSize = sizeOfBuffer - (glsint16_rear - glsint16_front);
		
	}
	else
	{
		availableSize = sizeOfBuffer;
	}
	
	if (availableSize > ptr_str_BCM_instance->dataSize)
	{
		/*ENQUEUING BUS USED*/
		QUEUE_enQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, busUsed);
	
		/*ENQUEUING DATA SIZE*/
		sizeHigherByte = ptr_str_BCM_instance->dataSize/256;
		sizeLowerByte  = (uint8_t) ptr_str_BCM_instance->dataSize;
		
		QUEUE_enQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, sizeHigherByte);
		QUEUE_enQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, sizeLowerByte);
		
		/*ENQUEING DATA*/
		for(uint16_t counter = 0; counter < ptr_str_BCM_instance->dataSize; counter++)
		{
			QUEUE_enQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, ptr_str_BCM_instance->data[counter]);
		}
	}
	else
	{
		returnValue = BCM_BUFFER_FULL;
	}
	return returnValue;	
}

enu_BCM_status_t	BCM_dispatcher	(void)
{
	enu_BCM_status_t returnValue = BCM_OK;
 	static enu_BCM_dispatcherStatus_t enu_BCM_dispatcherStatus = BCM_DISPATCHER_DQ_BUS;
	static uint16_t dataSize = 0, dataIndex = 0;
	static uint8_t dataBusUsed = 0, sizeHigherByte = 0, sizeLowerByte = 0;
	uint16_t sizeOfBuffer = 0;
	uint8_t data = 0;
	
	
	sizeOfBuffer = sizeof(gluint8_data)/sizeof(gluint8_data[0]);
	
	if (QUEUE_NEMPTY == QUEUE_isEmpty(glsint16_front))	
	{	
		switch (enu_BCM_dispatcherStatus)
		{
			case BCM_DISPATCHER_DQ_BUS:
			/*DEQUEUING DATA BUS*/
			QUEUE_deQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, &dataBusUsed);
			
			case BCM_DISPATCHER_DQ_HSIZE:
			switch(dataBusUsed)
			{
				case BCM_UART:
				/*DEQUEUING DATA SIZE*/
				if (UART_BUFFER_EMPTY == UART_isEmpty())
				{
					QUEUE_deQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, &sizeHigherByte);
					UART_sendByte(sizeHigherByte);
					enu_BCM_dispatcherStatus = BCM_DISPATCHER_DQ_LSIZE;
					break;
				}
				else
				{
					/*UART IS NOT EMPTY*/
					break;
				}
				
				case BCM_SPI:
				/*TO BE IMPLEMENTED*/
				break;
				
				case BCM_I2C:
				/*TO BE IMPLEMENTED*/
				break;
				
				default:
				returnValue = BCM_NOK;
				break;
			}
			break;
			
			case BCM_DISPATCHER_DQ_LSIZE:
			switch(dataBusUsed)
			{
				case BCM_UART:
				/*DEQUEUING DATA SIZE*/
				if (UART_BUFFER_EMPTY == UART_isEmpty())
				{
					QUEUE_deQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, &sizeLowerByte);
					UART_sendByte(sizeLowerByte);
					enu_BCM_dispatcherStatus = BCM_DISPATCHER_SIZE;
					break;
				}
				else
				{
					/*UART IS NOT EMPTY*/
					break;
				}
				
				case BCM_SPI:
				/*TO BE IMPLEMENTED*/
				break;
				
				case BCM_I2C:
				/*TO BE IMPLEMENTED*/
				break;
				
				default:
				returnValue = BCM_NOK;
				break;
				
			}
			if (BCM_DISPATCHER_SIZE == enu_BCM_dispatcherStatus)
			{
				/*GO TO BCM_DISPATCHER_SIZE STATE*/
			}
			else
			{
				break;
			}
			
			case BCM_DISPATCHER_SIZE:
			dataSize = (uint16_t) sizeHigherByte * 256 + sizeLowerByte;
			enu_BCM_dispatcherStatus = BCM_DISPATCHER_SENDING;
			
			case BCM_DISPATCHER_SENDING:
			switch(dataBusUsed)
			{
				case BCM_UART:
				/*DEQUEUING DATA SIZE*/
				if (UART_BUFFER_EMPTY == UART_isEmpty())
				{
					if(dataIndex < dataSize)
					{
						QUEUE_deQueue(&glsint16_front, &glsint16_rear, gluint8_data, sizeOfBuffer, &data);
						UART_sendByte(data);
						dataIndex++;
					}
					if (dataIndex == dataSize)
					{
						if(NULL_PTR != ptr_BCM_callBackFunc)
						{
							ptr_BCM_callBackFunc();
						}
						
						dataSize = 0;
						dataIndex = 0;
						enu_BCM_dispatcherStatus = BCM_DISPATCHER_DQ_BUS;
					}
					else
					{
						/*DISPATCHER IS STILL SENDING*/
					}
					
					break;
				}
				else
				{
					/*UART IS NOT EMPTY*/
					break;
				}
				
				case BCM_SPI:
				/*TO BE IMPLEMENTED*/
				break;
				
				case BCM_I2C:
				/*TO BE IMPLEMENTED*/
				break;
				
				default:
				returnValue = BCM_NOK;
				break;
				
			}
			default: 
			returnValue = BCM_NOK;
			break;
		}
		
	}
	else 
	{
		returnValue = BCM_BUFFER_EMPTY;
	}
	return returnValue;	
}

enu_BCM_status_t BCM_receiveData(uint8_t** ptr_uint8_receivedData, uint16_t* uint16_dataSize)
{
	enu_BCM_status_t returnValue = BCM_OK;
	UART_receiveData(ptr_uint8_receivedData, uint16_dataSize);
	
	return returnValue;
}

enu_BCM_status_t BCM_setCallBack(str_BCM_instance_t* ptr_str_BCM_instance, void(*ptr_func) (void))
{
	enu_BCM_status_t returnValue = BCM_OK;
	
	if (NULL_PTR != ptr_func)
	{
		for(uint8_t counter = 0; counter < BCM_NUMBER_OF_CHANNELS; counter++)
		{
			returnValue = BCM_NOK;
			if (cst_str_BCM_config[counter].dataID == ptr_str_BCM_instance->dataType)
			{
				if(cst_str_BCM_config[counter].busID == BCM_UART)
				{
					returnValue = BCM_OK;
					UART_setCallBack(ptr_func);
					break;
				}
				else if (cst_str_BCM_config[counter].busID == BCM_SPI)
				{
					returnValue = BCM_OK;
					/*SPI_init()*/
					break;
				}
				else if (cst_str_BCM_config[counter].busID == BCM_I2C)
				{
					returnValue = BCM_OK;
					/*I2C_init()*/
					break;
				}
				else
				{
					/*BCM_NOK*/
					break;
				}
			}
		}
	}
	else
	{
		returnValue = BCM_NOK;
	}
	
	return returnValue;
}

enu_BCM_status_t	BCM_dataSentCallBack	(void(*ptr_func) (void))
{
	enu_BCM_status_t returnValue = BCM_OK;
	if(NULL_PTR != ptr_func)
	{
		ptr_BCM_callBackFunc = ptr_func;
	}
	else
	{
		returnValue = BCM_NOK;
	}
	return returnValue;
}