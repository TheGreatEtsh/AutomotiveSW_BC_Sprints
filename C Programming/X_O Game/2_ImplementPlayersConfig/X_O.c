/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	X_O.c
 *	       Date:	26/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Aboard will be intialized with numbers from 1 to 9,
 *					which state each postion number
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include "standardTypes.h"
#include <stdio.h>

extern uint8_t configArray;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void setPlayerConfig(uint8_t* configArray)
{
	printf("Player 1 please enter your prefered symbol X or O\n");
	scanf("%c", configArray);

	if (configArray[0] == 'X')
	{
		configArray[1] = 'O';
		printf("Player 1 symbol: X\nPlayer 2 symbol: O\n");
	}
	else if (configArray[0] == 'O')
	{
		configArray[1] = 'X';
		printf("Player 1 symbol: O\nPlayer 2 symbol: X\n");
	}
	else
	{
		printf("Wrong entery\n");
		setPlayerConfig(configArray);
	}
}
