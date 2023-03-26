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
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include "standardTypes.h"
#include <stdio.h>

extern uint8_t board[9];
extern uint8_t configArray[2];
extern uint8_t roundCounter;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void drawBoard(uint8_t* board)
{
	uint8_t postion = 0;

	for (; postion < 9; postion += 3)
	{
		printf("-------------\n| %c | %c | %c |\n", board[postion], board[postion + 1], board[postion + 2]);

	}
	printf("-------------\n");
	printf("------------------------------------------------------------------------------\n");
}

void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
	position--;
	board[position] = value;
	drawBoard(board);
}

void loadAndUpdate(uint8_t playerNumber)
{

	int position = 0;
	int actPosition = 0;

	if (playerNumber == 1)
		printf("Player 1 enter your prefered postion from 1 to 9\n");
	else if (playerNumber == 2)
		printf("Player 2 enter your prefered postion from 1 to 9\n");

	scanf("%d", &position);
	
	actPosition = position - 1;

	if (position > 0 && position < 10 && board [actPosition] == ' ')
	{
		
		if (playerNumber == 1)
			updateBoard(board, position, configArray[0]);
		else if (playerNumber == 2)
			updateBoard(board, position, configArray[1]);
	}
	else
	{
		printf("Wrong entry\n");
		loadAndUpdate(playerNumber);
	}
}

void getGameState(uint8_t* gameState)
{
	if (roundCounter < 4)
		*gameState = 2;
	else if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
		*gameState = 0;
	else if (board[6] == board[4] && board[4] == board[2] && board[6] != ' ')
		*gameState = 0;
	else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
		*gameState = 0;
	else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
		*gameState = 0;
	else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		*gameState = 0;
	else if (board[6] == board[3] && board[3] == board[0] && board[6] != ' ')
		*gameState = 0;
	else if (board[7] == board[4] && board[4] == board[1] && board[7] != ' ')
		*gameState = 0;
	else if (board[8] == board[5] && board[5] == board[2] && board[8] != ' ')
		*gameState = 0;
	else if (roundCounter == 9)
		*gameState = 1;
	else
		*gameState = 2;
	
}