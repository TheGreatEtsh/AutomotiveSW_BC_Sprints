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

extern uint8_t configArray [2];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{
	uint8_t returnValue = 0;
	
	if (playerNumber == 1)
	{
		printf("Player 1 please enter your prefered symbol X or O\n");
		scanf("%s", symbol);
		
		if (*symbol == configArray[0] || *symbol == configArray[1] )
		{
			printf("Symbol is choosen\n");
			returnValue = 1;
		}
		else if (*symbol == 'X' || *symbol == 'O')
		{
			printf("Entery is successful\n");
			returnValue = 0;
		}
		else
		{
			printf("Entery is wrong\n");
			returnValue = 1;
		}
	}

	if (playerNumber == 2)
	{
		printf("Player 2 please enter your prefered symbol X or O\n");
		
		scanf("%s", symbol);

		if (*symbol == configArray[0] || *symbol == configArray[1])
		{
			printf("Symbol is choosen\n");
			returnValue = 1;
		}
		else if (*symbol == 'X' || *symbol == 'O')
		{
			printf("Entery is successful\n");
			returnValue = 0;

		}
		else
		{
			printf("Entery is wrong\n");
			returnValue = 1;
		}
	}

	return returnValue;
}

void setPlayerConfig(uint8_t* configArray)
{
	static uint8_t wrongEntery_1 = 0, wrongEntery_2 = 0;
	uint8_t symbol = 0;
	
	while (getPlayerSymbol(1, &symbol));

	configArray[0] = symbol;
	
	while (getPlayerSymbol(2, &symbol));

	configArray[1] = symbol;
}




