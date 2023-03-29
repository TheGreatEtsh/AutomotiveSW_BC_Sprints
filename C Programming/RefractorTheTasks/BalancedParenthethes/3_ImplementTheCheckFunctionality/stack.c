/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	stack.c
 *	       Date:	27/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation of stack functions
 *					
 *********************************************************************************************************************/

#include "standardTypes.h"
#include "stack.h"
#include <stdio.h>



/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t* stack)
{

	for (uint8_t counter = 0; counter < STACK_SIZE; counter++)
		stack->elements[counter] = 0;

	stack->top = -1;
}

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
sint8_t isFull(ST_stack_t* stack)
{
	if (stack->top == STACK_SIZE - 1)
		return -1;
	else
		return 0;
}


/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
sint8_t isEmpty(ST_stack_t* stack)
{
	if (stack->top == -1)
		return -2;
	else
		return 0;
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
sint8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
	if (isEmpty(stack) == -2)
	{
		printf("you can not get stack's top, stack is Empty\n\n");
		return -2;
	}
	else
	{

		*topData = stack->elements[stack->top];
		return 0;
	}
}

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
sint8_t printStack(ST_stack_t* stack)
{
	if (isEmpty(stack) == -2)
	{
		printf("you can not print, stack is Empty\n\n");
		return -2;
	}
	else if (isFull(stack) == -1)
	{
		printf("Stack content from bottom to top: \n");
		for (uint8_t i = 0; i <= stack->top; i++)
		{
			printf("%d\n", stack->elements[i]);
		}
		printf("\n");
		return -1;
	}
	else
	{
		printf("Stack content from bottom to top: \n");
		for (uint8_t counter = 0; counter <= stack->top; counter++)
		{
			printf("%d\n", stack->elements[counter]);
		}
		printf("\n");
		return 0;
	}
}

/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
sint8_t push(ST_stack_t* stack, uint8_t data)
{
	if (isFull(stack) == -1)
	{
		printf("You can not push, stack is Full\n\n");
		return -1;
	}
	else
	{
		stack->top++;
		stack->elements[stack->top] = data;
		return 0;
	}
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
sint8_t pop(ST_stack_t* stack, uint8_t* data)
{
	if (isEmpty(stack) == -2)
	{
		printf("You can not pop, stack is Empty\n\n");
		return -2;
	}
	else
	{
		*data = stack->elements[stack->top];
		stack->top--;
		return 0;
	}
}
