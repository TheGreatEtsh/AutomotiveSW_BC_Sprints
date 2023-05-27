/*
 * queue_program.c
 *
 * Created: 5/24/2023 9:23:10 PM
 *  Author: programize.com edited by Ahmed Hesham
 */ 
#include "queue_interface.h"

// Check if the queue is full
enu_QUEUE_status_t QUEUE_isFull(sint16_t sint16_front, sint16_t sint16_rear, uint16_t uint16_queueSize) 
{
	enu_QUEUE_status_t returnValue = QUEUE_NFULL;
	if ((sint16_front == sint16_rear + 1) || (sint16_front == 0 && sint16_rear == uint16_queueSize - 1)) 
	{
		return returnValue = QUEUE_FULL;
	}
	else
	{
		/*QUEUE IS NOT FULL*/
	}
	return returnValue;
}

// Check if the queue is empty
enu_QUEUE_status_t QUEUE_isEmpty(sint16_t sint16_front)
{
	enu_QUEUE_status_t returnValue = QUEUE_NEMPTY;
	if (sint16_front == -1) 
	{
		returnValue = QUEUE_EMPTY;
	}
	else
	{
		/*QUEUE IS NOT EMPTY*/
	}
	return returnValue;
}

// Adding an element
enu_QUEUE_status_t QUEUE_enQueue(	sint16_t*  sint16_front,
									sint16_t*  sint16_rear,
									uint8_t* ptr_uint8_queue,
									uint16_t  uint16_queueSize,
									uint8_t  uint8_element)
{
	enu_QUEUE_status_t returnValue = QUEUE_NFULL;
	if (QUEUE_FULL == QUEUE_isFull(*sint16_front, *sint16_rear, uint16_queueSize))
	{
		/*QUEUE IS FULL*/
		returnValue = QUEUE_FULL;
	}
	else 
	{
		if (-1 == *sint16_front) 
		{
			*sint16_front = 0;
		}
		
		*sint16_rear = (*sint16_rear + 1) % uint16_queueSize;
		ptr_uint8_queue[*sint16_rear] = uint8_element;
	}
	return returnValue;
}

// Removing an element
enu_QUEUE_status_t QUEUE_deQueue(	sint16_t*  sint16_front,
									sint16_t*  sint16_rear,
									uint8_t* ptr_uint8_queue,
									uint16_t  uint16_queueSize,
									uint8_t* ptr_uint8_element)
{
	enu_QUEUE_status_t returnValue = QUEUE_NEMPTY;
	if (QUEUE_EMPTY == QUEUE_isEmpty(*sint16_front)) 
	{
		/*QUEUE IS EMPTY*/
		returnValue = QUEUE_EMPTY;
	} 
	else 
	{
		*ptr_uint8_element = ptr_uint8_queue[*sint16_front];
		if (*sint16_front == *sint16_rear) 
		{
 			/*Q has only one element, so we reset the
 			queue after dequeing it*/
			*sint16_front = -1;
			*sint16_rear = -1;
		}
		else 
		{
			*sint16_front = (*sint16_front + 1) % uint16_queueSize;
		}
		
	}
	return returnValue;
}