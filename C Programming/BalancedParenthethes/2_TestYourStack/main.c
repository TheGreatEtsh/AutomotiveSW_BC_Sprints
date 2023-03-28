/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	main.c
 *	       Date:	27/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation of the main flow
 *					
 *********************************************************************************************************************/
 
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "standardTypes.h"
#include <stdio.h>
#include "stack.h"



int main()
{
	ST_stack_t stack;
	uint8_t poppedData = 0;
	uint8_t stackTop = 0;
	
	/*1. Create an empty stack								*/
	createEmptyStack(&stack);

	/*2. Push 5 different characters to the stack			*/
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	
	/*3. Print all stack data								*/
	printStack(&stack);

	/*4. Pop one character from the stack					*/
	pop(&stack, &poppedData);

	/*5. Print the stack's top								*/
	getStackTop(&stack, &stackTop);
	printf("Stack's top %d\n", stackTop);

	/*6. Print all stack data								*/
	printStack(&stack);

	/*7. Push another 7 different characters to the stack	*/
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);
	push(&stack, 7);

	/*8. Print the stack's top								*/
	if (getStackTop(&stack, &stackTop) != -2)
		printf("Stack's top %d\n", stackTop);
	else
	{
		/*DO NOTHING*/
	}

	/*9. Print all stack data								*/
	printStack(&stack);

	/*10. Pop 4 characters from the stack					*/
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);

	/*11. Print the stack's top 							*/
	if (getStackTop(&stack, &stackTop) != -2)
		printf("Stack's top %d\n", stackTop);
	else
	{
		/*DO NOTHING*/
	}

	/*12. Print all stack data								*/
	printStack(&stack);

	/*13. Pop 7 more times from the stack					*/
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);
	pop(&stack, &poppedData);

	/*14. Print the stack's top 							*/
	if (getStackTop(&stack, &stackTop) != -2)
		printf("Stack's top %d\n", stackTop);
	else
	{
		/*DO NOTHING*/
	}


	/*15. Print all stack data								*/
	printStack(&stack);

	return 0;
}




