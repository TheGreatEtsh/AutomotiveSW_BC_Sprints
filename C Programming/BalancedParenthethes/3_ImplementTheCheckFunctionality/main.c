#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "standardTypes.h"
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "check.h"


int main()
{
	uint8_t expression[10];

	printf("Enter an Expression\n");
	gets(expression);
	isBalancedParanthethes(expression);
	
	return 0;
}




