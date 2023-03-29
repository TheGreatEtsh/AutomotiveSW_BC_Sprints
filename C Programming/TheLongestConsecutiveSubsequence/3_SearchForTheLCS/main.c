/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	main.c
 *	       Date:	28/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation of the main application
 *
 *********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS


 /**********************************************************************************************************************
  * INCLUDES
  *********************************************************************************************************************/

#include "sort.h"
#include "standardTypes.h"
#include <stdio.h>
int main()
{
	sint32_t array[15] = { 0 };
	uint8_t enteredElements = 0, variable = 0, sizeofLCS = 1;
	sint8_t functionReturn = 0;
	
	printf("enter any key at first then Enter array elements then q if you want to stop entering elements\n");

	do
	{
		scanf("%c", &variable);
		if (variable == 'q')
			break;

		scanf("%d", &array[enteredElements]);
		enteredElements++;
	} while (variable != 'q');

	if (enteredElements)
		enteredElements--;



	functionReturn = lcsGetSize(array, enteredElements, &sizeofLCS);
	if (functionReturn == 0)
	{
		printArray(array, enteredElements);
		printf("The Longest Consecutive Subsequence = %d\n", sizeofLCS);
	}
	else if (functionReturn == -1)
	{
		printf("Array is Empty\n");
	}
	else if (functionReturn == -2)
	{
		printf("You exceeded size constrains\n");
	}
	else if (functionReturn == -3)
	{
		printf("There is no Consecutive Subsequence\n");
	}


	return 0;
}