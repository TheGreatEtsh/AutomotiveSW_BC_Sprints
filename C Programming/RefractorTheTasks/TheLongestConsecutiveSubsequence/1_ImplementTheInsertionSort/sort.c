/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	sort.c
 *	       Date:	28/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation for the sort function 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "standardTypes.h"
#include <stdio.h>
 /**********************************************************************************************************************
  * GLOBAL FUNCTIONS DEFINITION
  *********************************************************************************************************************/

void SWAP(uint32_t* x, uint32_t* y)
{
	(*x) = (*x) + (*y);
	(*y) = (*x) - (*y);
	(*x) = (*x) - (*y);
}

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
sint8_t insertionSort(sint32_t* array, uint8_t arraySize)
{
	sint8_t returnValue = 0;
	if(arraySize > 0 && arraySize < 11)
	{
		sint32_t key = 0, i = 1, j = 0;
		for (; i < arraySize; i++)
		{
			key = array[i];
			j = i - 1;
			while (j >= 0 && key < array[j])
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = key;
		}
		returnValue = 0;
	}
	else if ( arraySize > 10)
	{
		returnValue = -2;
	}
	else if (arraySize == 0)
	{
		returnValue = -1;
	}

	return	returnValue;
}

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(sint32_t* array, uint8_t arraySize)
{
	uint8_t i = 0;
	printf("Array Elements: ");
	for (; i < arraySize; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n\n");
}