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


/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
sint8_t lcsGetSize(sint32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{
	uint8_t counter = 1, i = 0;
	sint8_t functionReturn = 0, returnValue = 0;
	
	*sizeofLCS = 1;

	functionReturn = insertionSort(array, arraySize);
	
	if(! functionReturn)
	{
		while (i < arraySize)
		{
			if (array[i + 1] - array[i] == 1)
			{
				counter++;
				if (counter > *sizeofLCS)
				{
					*sizeofLCS = counter;
				}
				else
				{
					/*DO NOTHING*/
				}
			}
			else
			{
				counter = 1;
			}
			i++;
		}
		if (*sizeofLCS > 1)
		{
			returnValue = 0;
		}
		else
		{
			returnValue = -3;
		}
	}
	else if (functionReturn == -1)
	{
		returnValue = -1;
	}
	else if (functionReturn == -2)
	{
		returnValue = -2;
	}
	else 
	{
		/*DO NOTHING*/
	}
	return returnValue;
}