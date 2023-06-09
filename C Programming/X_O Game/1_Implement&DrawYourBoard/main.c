/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	main.h
 *	       Date:	26/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	main function
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include	"X_O.h"
#include	<stdio.h>

int main()
{
	uint8_t board[9] = { ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ' };
	
	drawBoard(board);
	
	updateBoard(board, 5, 'X');
	
	return 0;
}