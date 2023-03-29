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
	uint8_t enteredElements = 0, variable = 0;
	sint8_t functionReturn = 0;
	
	printf("enter any key at first then Enter array elements then q next to last element to exist\n");
	
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

	 //printArray(array, enteredElements);
	
	functionReturn = insertionSort(array, enteredElements);
	if (functionReturn == 0)
	{
		printArray(array, enteredElements);
	}
	else if (functionReturn == -1)
	{
		printf("Array is Empty\n");
	}
	else
	{
		printf("You exceeded size constrains\n");
	}


	return 0;
}