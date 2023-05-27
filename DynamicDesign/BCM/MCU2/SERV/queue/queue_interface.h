/*
 * queue_interface.h
 *
 * Created: 5/24/2023 9:23:46 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_
#include "../../LIB/std.h"

typedef enum
{
	QUEUE_NFULL = 0,
	QUEUE_FULL,
	QUEUE_NEMPTY,
	QUEUE_EMPTY
}enu_QUEUE_status_t;

/**
 * \Syntax          : QUEUE_isFull(sint16_t sint16_front, sint16_t sint16_rear, uint16_t uint16_queueSize)
 * \Description     : Checks if the queue is full or not
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : sint16_front
 *						sint16_rear
 *						uint16_queueSize
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	QUEUE_NFULL = 0,
 *										QUEUE_FULL
 */
 enu_QUEUE_status_t QUEUE_isFull(sint16_t sint16_front, sint16_t sint16_rear, uint16_t uint16_queueSize);

/**
 * \Syntax          : QUEUE_isEmpty(sint16_t sint16_front)
 * \Description     : Checks if the queue is empty or not
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : sint16_front
 * \Parameters (out): None
 * \Return value:   : enu_UART_status_t	QUEUE_EMPTY,
 *										QUEUE_NEMPTY
 */
 enu_QUEUE_status_t QUEUE_isEmpty(sint16_t sint16_front);
 
/**
 * \Syntax          : QUEUE_enQueue(	sint16_t*  ptr_sint16_front,
 *										sint16_t*  ptr_sint16_rear,
 *										uint8_t* ptr_uint8_queue,
 *										uint16_t  uint16_queueSize,
 *										uint8_t  uint8_element)
 * \Description     : Enqueue an element in the queue
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_uint8_queue
 *						uint16_queueSize
 *						uint8_element
 * \Parameters (out): ptr_sint16_front
 *						ptr_sint16_rear
 * \Return value:   : enu_UART_status_t	QUEUE_NFULL = 0,
 *										QUEUE_FULL
 */
 enu_QUEUE_status_t QUEUE_enQueue(	sint16_t*  ptr_sint16_front, 
									sint16_t*  ptr_sint16_rear, 
									uint8_t* ptr_uint8_queue, 
									uint16_t  uint16_queueSize, 
									uint8_t  uint8_element);

/**
 * \Syntax          : QUEUE_deQueue(	sint16_t*  ptr_sint16_front,
 *										sint16_t*  ptr_sint16_rear,
 *										uint8_t* ptr_uint8_queue,
 *										uint16_t  uint16_queueSize,
 *										uint8_t*  ptr_uint8_element)
 * \Description     : Dequeue an element from the queue
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ptr_uint8_queue
 *						uint16_queueSize
 * \Parameters (out): ptr_sint16_front
 *						ptr_sint16_rear
 *						ptr_uint8_element
 * \Return value:   : enu_UART_status_t	QUEUE_EMPTY,
 *										QUEUE_NEMPTY
 */
 enu_QUEUE_status_t QUEUE_deQueue(	sint16_t*  ptr_sint16_front,
									sint16_t*  ptr_sint16_rear,
									uint8_t* ptr_uint8_queue,
									uint16_t  uint16_queueSize,
									uint8_t* ptr_uint8_element);
									
#endif /* QUEUE_INTERFACE_H_ */