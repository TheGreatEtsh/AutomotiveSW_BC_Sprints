/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:	main.c
 *	       Date:	27/3/2023
 *		  Email:	ahmedhesham606@icloud.com
 *	  Developer:	Ahmed Mohamed Hesham
 *  Description:	Has the implementation of the main flow
 *					
 *********************************************************************************************************************/
 
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "standardTypes.h"
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "check.h"


int main()
{
	uint8_t expression[30];

	printf("Enter an Expression\n");
	gets(expression);
	isBalancedParanthethes(expression);
	
	return 0;
}




