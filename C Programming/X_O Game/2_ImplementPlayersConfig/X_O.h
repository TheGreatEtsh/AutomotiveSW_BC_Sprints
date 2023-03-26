/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	X_O.h
 *	       Date:	26/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Aboard will be intialized with numbers from 1 to 9,
 *					which state each postion number
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
*					  symbol			pointer to the address of symbol will be modified
* \Parameters (out): symbol			the pointer will be modify it's state after the user input his symbol
* \Return value:   : 0 when the input symbol is not wrong and/or was not choosen before
*					  1 when the input symbol is wrong and/or was choosen before
*******************************************************************************/
void setPlayerConfig(uint8_t* configArray);



#endif