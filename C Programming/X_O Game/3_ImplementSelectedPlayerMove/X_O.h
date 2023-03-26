/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	X_O.h
 *	       Date:	26/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Aboard will be intialized with numbers from 1 to 9,
 *					which state each postion and Implement selected player move
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
* \Description     : This function will take player's number then loah his config, asks
*					 him for the postion then updates the board
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : playerNumber	load player's config 
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/
void loadAndUpdate(uint8_t playerNumber);


#endif	// !X_O_H