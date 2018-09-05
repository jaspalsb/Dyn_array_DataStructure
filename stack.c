/*********************************************************************
** Author: Jaspal Bainiwal
** Date: 04/23/2018
** Description: This is the implementation of the dynamic array for ADT's
stack and bag.
** Input: an expression with () {} [] 
** Output: test if it is balanced
************************************************************************/
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: 	s pointer to a string
pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s + i);
	if (c == '\0')
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
param: 	s pointer to a string
pre: s is not null
post:
*/
int isBalanced(char* s)
{
	/*using the same format from the testdynArray.c file*/
	DynArr *dyn;
	dyn = newDynArr(2);
	char postfix;
	postfix = nextChar(s);
	while (postfix != '\0')
	{
		postfix = nextChar(s);
		if (postfix == '(')
		{
			pushDynArr(dyn, postfix);
		}
		else if (postfix == '{')
		{
			pushDynArr(dyn, postfix);
		}
		else if (postfix == '[')
		{
			pushDynArr(dyn, postfix);
		}
		/*To avoid stack underflow I make sure the array is not empty*/
		else if ((postfix == ')') && !(isEmptyDynArr(dyn)))
		{
			if (topDynArr(dyn) == postfix)
			{
				popDynArr(dyn);
			}
		}
		else if ((postfix == '}') && !(isEmptyDynArr(dyn)))
		{
			if (topDynArr(dyn) == postfix)
			{
				popDynArr(dyn);
			}
		}
		else if ((postfix == ']') && !(isEmptyDynArr(dyn)))
		{
			if (topDynArr(dyn) == postfix)
			{
				popDynArr(dyn);
			}
		}
		postfix = nextChar(s);
	}
	/*Now that the while loop has reached \0 it should exit that loop
	if the dyn array hasn't popped every element that pushed off yet that means that
	the string was not balanced*/
	if (isEmptyDynArr(dyn))
	{

		return 1;
	}
	else
	{

		deleteDynArr(dyn);
		return 0;
	}
}



int main(int argc, char* argv[]) {

	char* s = argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}

