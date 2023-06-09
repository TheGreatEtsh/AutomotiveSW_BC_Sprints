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


#include "standardTypes.h"
#include <stdio.h>

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void drawBoard(uint8_t* board)
{
	uint8_t postion = 0;
	
	for (; postion < 9; postion+=3)
	{
		printf("-------------\n| %c | %c | %c |\n", board[postion], board[postion + 1], board[postion + 2]);
		
	}
	printf("-------------\n");
	printf("------------------------------------------------------------------------------\n");
}

void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
	board[position - 1] = value;
	drawBoard(board);
}