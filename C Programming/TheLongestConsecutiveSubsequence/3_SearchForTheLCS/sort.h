/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	sort.c
 *	       Date:	28/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the prototype for the sort function
 *
 *********************************************************************************************************************/
#ifndef SORT_H
#define SORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "standardTypes.h"


/* Description:
 * - This function takes reference to two elements 
 * - and then swap their content
 * Return:
 * Nothing to retuen
 */
void SWAP(uint32_t* x, uint32_t* y);

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
sint8_t insertionSort(sint32_t* array, uint8_t arraySize);

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(sint32_t* array, uint8_t arraySize);

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
sint8_t lcsGetSize(sint32_t* array, uint8_t arraySize, uint8_t* sizeofLCS);


#endif // !SORT_H
