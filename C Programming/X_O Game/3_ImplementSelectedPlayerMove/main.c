#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include "standardTypes.h"
#include "X_O.h"
#include <stdio.h>

uint8_t board[9] = { ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ' };
uint8_t configArray[2] = { 'X','O' };

int main()
{
	drawBoard(board);

	loadAndUpdate(1);
}