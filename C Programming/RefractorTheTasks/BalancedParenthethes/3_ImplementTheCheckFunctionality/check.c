/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	check.c
 *	       Date:	27/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation of is balanced parenthethes function
 *
 *********************************************************************************************************************/

#include "check.h"
#include "stack.h"
#include <stdio.h>


/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
sint8_t isBalancedParanthethes(uint8_t* expression)
{
	uint8_t curlyBrackets = 0, roundedBrackets = 0, straightBrackets = 0, smallBrackets = 0;
	uint8_t poppedData = 0;
	sint8_t returnValue = 0;
	ST_stack_t stack;
	createEmptyStack(&stack);

	uint8_t counter = 0;

	while (*(expression + counter))
	{
		if	(*(expression + counter) == '{' || *(expression + counter) == '}' 
			|| *(expression + counter) == '(' || *(expression + counter) == ')' 
			|| *(expression + counter) == '<' || *(expression + counter) == '>' 
			|| *(expression + counter) == '[' || *(expression + counter) == ']')
		
			push(&stack, (*(expression + counter)));
		counter++;
	}

	while (!pop(&stack, &poppedData))
	{
		switch (poppedData)
		{
		case '}':
			curlyBrackets++;
			break;
		case '{':
			curlyBrackets--;
			break;
		case ')':
			roundedBrackets++;
			break;
		case '(':
			roundedBrackets--;
			break;
		case '[':
			straightBrackets++;
			break;
		case ']':
			straightBrackets++;
			break;
		case'<':
			smallBrackets++;
			break;
		case'>':
			smallBrackets++;
			break;
		default:
			break;
		}
	}
	if (smallBrackets || straightBrackets)
	{
		returnValue = -2;
		printf("Wrong brackets inserted\n");
	}
	else if (roundedBrackets == 0 && curlyBrackets == 0)
	{
		returnValue = 0;
		printf("The parentheses are balanced\n");
	}

	else
	{
		returnValue = -1;
		printf("The parentheses are not balanced\n");
	}

	return returnValue;
}