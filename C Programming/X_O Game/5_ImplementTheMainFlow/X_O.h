/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	X_O.h
 *	       Date:	26/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	A board will be intialized with numbers from 1 to 9,
 *					which state each postion and Implement selected player move
 *					, and finally the state of the game
 *
 *********************************************************************************************************************/

#ifndef X_O_H
#define X_O_H

 /**********************************************************************************************************************
  * INCLUDES
  *********************************************************************************************************************/
#include "standardTypes.h"



  /**********************************************************************************************************************
   *  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void drawBoard (uint8_t *board);
* \Description     : This function will take a board as an input and
*					 Prints it on the console
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : board			Pointer to the board array elements
*					 position		Position in the board to be edited
*					 value			The value which be added to the board at the postion mentioned
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/

void drawBoard(uint8_t* board);


/******************************************************************************
* \Syntax          : void updateBoard(uint8_t* board, uint8_t position, uint8_t value);
* \Description     : This function will take the board, postion to update
*					 and value to set this postion
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : board			Pointer to the board array elements
*					 position		Position in the board to be edited
*					 value			The value which be added to the board at the postion mentioned
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/

void updateBoard(uint8_t* board, uint8_t position, uint8_t value);

/******************************************************************************
* \Syntax          : void updateBoard(uint8_t* board, uint8_t position, uint8_t value);
* \Description     : This function will take player's number then load his config, asks
*					 him for the postion then updates the board
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : playerNumber	load player's config
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/
void loadAndUpdate(uint8_t playerNumber);

/******************************************************************************
* \Syntax          : void getGameState(uint8_t* gameState);
* \Description     : This function check after each move if there is a win, draw,
*					 continue playing
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): gameState		It will hold the return of the state of game
* \Return value:   : 0				For winning
*					 1				For drawing
*					 2				For continue
*******************************************************************************/
void getGameState(uint8_t* gameState);

/******************************************************************************
* \Syntax          : uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);
* \Description     : This function will take player number and asks the player to choose
*					  Between X and O
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : playerNumber		This will determine which player is entering symbol
*					  symbol			pointer to the address of symbol will be modified
* \Parameters (out): symbol			the pointer will be modify it's state after the user input his symbol
* \Return value:   : 0 when the input symbol is not wrong and/or was not choosen before
*					  1 when the input symbol is wrong and/or was choosen before
*******************************************************************************/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);


/******************************************************************************
* \Syntax          : void setPlayerConfig(uint8_t* configArray);\
* \Description     : This function will prompt and asks each user about their preferred symbols
*					 and save it in the configArray
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : playerNumber		This will determine which player is entering symbol
*					 symbol			pointer to the address of symbol will be modified
* \Parameters (out): configArray		Will hold the symbols for the players for the rest of the game
* \Return value:   : None
*******************************************************************************/
void setPlayerConfig(uint8_t* configArray);
#endif	// !X_O_H