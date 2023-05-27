/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *
 *		   @Date:  	23/5/2023 10:28:36 PM
 *		   @File:  	BCM_interface.h         
 *		 @Module:  	Basic Communication Manager
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for BCM module     
 *  
 *********************************************************************************************************************/
#ifndef BCM_INTERFACE_H_
#define BCM_INTERFACE_H_

#include "../../LIB/std.h"
#include "../../SERV/queue/queue_interface.h"
#include "../../MCAL/uart/uart_interface.h"
#include "../../ECUAL/led/led_interface.h"




typedef enum 
{
	BCM_OK = 0,
	BCM_NOK,
	BCM_BUFFER_EMPTY,
	BCM_BUFFER_FULL
	
}enu_BCM_status_t;

typedef enum 
{
	BCM_DISPATCHER_DQ_BUS = 0,
	BCM_DISPATCHER_DQ_HSIZE,
	BCM_DISPATCHER_DQ_LSIZE,
	BCM_DISPATCHER_SIZE,
	BCM_DISPATCHER_SENDING
}enu_BCM_dispatcherStatus_t;

typedef enum
{
	BCM_UART,
	BCM_SPI,
	BCM_I2C
}enu_BCM_busID_t;

typedef enum
{
	BCM_EXCHANGE = 0,
	BCM_STORE,
	BCM_DISPLAY	
}enu_BCM_data_t;

typedef struct
{
	enu_BCM_data_t	dataType;
	uint16_t		dataSize;		/*Size of data*/
	uint8_t*		data;			/*data to be filled in the buffer*/
}str_BCM_instance_t;

/*uint8_t buffer[1024] = {2bits data size, data bits, 2bits data size, data bits}*/



typedef struct
{
	enu_BCM_data_t	dataID;
	enu_BCM_busID_t	busID;
}str_BCM_config_t;


/**
 * \Syntax          : BCM_init (str_BCM_instance_t* ptr_str_BCM_instance)
 * \Description     : Initializes a specific communication protocol
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_str_BCM_instance
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK
 */
enu_BCM_status_t	BCM_init		(str_BCM_instance_t* ptr_str_BCM_instance);

/**
 * \Syntax          : BCM_deinit (str_BCM_instance_t* ptr_str_BCM_instance)
 * \Description     : Deinitializes a specific communication protocol
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_str_BCM_instance
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK
 */
enu_BCM_status_t	BCM_deinit		(str_BCM_instance_t* ptr_str_BCM_instance);

/**
 * \Syntax          : BCM_send_n(str_BCM_instance_t* ptr_str_BCM_instance)
 * \Description     : Enqueue any amount of data in data buffer to be send through 
 *					  a specific communication protocol using dispatcher
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_str_BCM_instance
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK,
 *										BCM_FULL
 */
enu_BCM_status_t	BCM_send_n		(str_BCM_instance_t* ptr_str_BCM_instance);		/*enqueue*/

/**
 * \Syntax          : BCM_dispatcher	(void)
 * \Description     : Dequeue the data from data buffer and send it 
 *					  through a specific communication protocol
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_str_BCM_instance
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK,
 *										BCM_EMPTY
 */
enu_BCM_status_t	BCM_dispatcher	(void);											/*dequeue*/

/**
 * \Syntax          : BCM_receiveData (uint8_t** ptr_ptr_uint8_receivedData, 
 *									   uint16_t* ptr_uint16_dataSize)
 * \Description     : Receives address of data received to a specific communication 
 *					  protocol and the size of it
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): ptr_ptr_uint8_receivedData
 *					  ptr_uint16_dataSize
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK
 */
enu_BCM_status_t	BCM_receiveData (uint8_t** ptr_ptr_uint8_receivedData, uint16_t* ptr_uint16_dataSize);

/**
 * \Syntax          : BCM_setCallBack(str_BCM_instance_t* ptr_str_BCM_instance, 
 *									  void(*ptr_func) (void))
 * \Description     : Set callback function, which is called when there is data received 
 *					  through any communication protocol
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_str_BCM_instance
 *					  void(*ptr_func) (void)
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK
 */
enu_BCM_status_t	BCM_setCallBack(str_BCM_instance_t* ptr_str_BCM_instance, void(*ptr_func) (void));

/**
 * \Syntax          : BCM_ dataSentCallBack (void(*ptr_func) (void))
 * \Description     : Set callback function, which is called when there is data 
 *					  transmitted through any communication protocol
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : void(*ptr_func) (void)
 * \Parameters (out): None
 * \Return value:   : enu_BCM_status_t	BCM_OK = 0,
 *										BCM_NOK
 */
enu_BCM_status_t	BCM_dataSentCallBack	(void(*ptr_func) (void));

#endif /* BCM_INTERFACE_H_ */