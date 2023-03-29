#include "standardTypes.h"

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

	if (!functionReturn)
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