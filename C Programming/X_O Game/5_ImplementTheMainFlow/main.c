#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include "standardTypes.h"
#include "X_O.h"
#include <stdio.h>

uint8_t board[9] = { ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ' };
uint8_t configArray[2];
uint8_t roundCounter = 0;
uint8_t playerTurn;

int main()
{
	uint8_t gameState = 2;
	setPlayerConfig(configArray);

	drawBoard(board);
	while (gameState == 2)
	{
		playerTurn = 1;
		loadAndUpdate(playerTurn);
		roundCounter++;
		getGameState(&gameState);

		if (gameState != 2)
		{
			break;
		}

		playerTurn = 2;
		loadAndUpdate(playerTurn);
		roundCounter++;
		getGameState(&gameState);

	}

	if (gameState == 0)
	{
		if (playerTurn == 1)
			printf("%c is the WINNER\n", configArray[0]);
		else
			printf("%c is the WINNER\n", configArray[1]);
	}
	else
		printf("It's a DRAW\n");

}