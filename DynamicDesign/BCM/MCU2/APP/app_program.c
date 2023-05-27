/*
 * app_program.c
 *
 * Created: 5/25/2023 3:17:00 AM
 *  Author: Ahmed Hesham
 */ 
#include "app_interface.h"

str_BCM_instance_t glstr_exchangeDataInstance;

void APP_init (void)
{
	LED_init();
	
	glstr_exchangeDataInstance.dataType = BCM_EXCHANGE;
	BCM_init(&glstr_exchangeDataInstance);
	BCM_setCallBack(&glstr_exchangeDataInstance,APP_saveReceivedTask);
	BCM_dataSentCallBack(APP_dataSentTask);
}

void APP_superLoop(void)
{
	glstr_exchangeDataInstance.dataSize = SIZE_OF_FIRST_INSTANCE;
	uint16_t counter = 0;
	uint8_t dataArr [SIZE_OF_FIRST_INSTANCE];
	for (; counter < SIZE_OF_FIRST_INSTANCE; counter++)
	{
		dataArr[counter] = counter;
	}
	
	glstr_exchangeDataInstance.data = dataArr;
	BCM_send_n(&glstr_exchangeDataInstance);
	
	while(1)
	{
		BCM_dispatcher();
	}
}







void APP_saveReceivedTask(void)
{
// 	uint8_t** ptr_uint8_receivedData = NULL_PTR;
// 	uint16_t uint16_dataSize = 0;
	
	LED_toggle(LED_1);
	
// 	BCM_receiveData(ptr_uint8_receivedData, &uint16_dataSize);
// 	
// 	glstr_exchangeDataInstance.dataSize = uint16_dataSize;
// 	glstr_exchangeDataInstance.data = *ptr_uint8_receivedData;
// 	
// 	BCM_send_n(&glstr_exchangeDataInstance);
}

void APP_dataSentTask(void)
{
	LED_toggle(LED_0);
}