#include <iostream>
#include "ONP.h"
#include "Stack.h"

int main()
{
	onp ();
}


void skipSpaces()
{
	char c;
	while ( (c = getchar()) == ' ' );

	ungetc( c, stdin );		
}
int getNum()// reads number and its sign  -123
{
	char c;
	int sign = 1;
	int value = 0;

	skipSpaces ();

	if ((c = getchar ()) == '+' || c == '-')
	{
		if (c == '-')
			sign = -1;
	}
	else
		ungetc (c, stdin);
	
	while( isDigit (c = getchar ()) )
		value = value * 10 + (c-'0');		//get the value 
	
	ungetc (c, stdin);						//this will be an operand so return it to stdin
	return sign*value;
}
int isDigit (char c)
{
	return(c >= '0' && c <= '9');
}
int isOper (char nOper) // + - / ^ *
{
	switch(nOper)
	{
	case '+': //move to next
	case '-': //++
	case '/': //++
	case '*': //++
	case '^': return 1;
	}
	return 0;
}
int prior (char nOper)// priority of oper    1. (+ -)  2. (* /) 3. ^
{
	switch (nOper)
	{
	case '+': 
	case '-': return 1;
	case '/': 
	case '*': return 2;
	case '^': return 3;
	}
	return 0;
}
char getOper()
{
	skipSpaces();
	return getchar();
}
void onp ()
{
	char c;
	printf("%d", getNum());					//assumed that always a number 1sr
	while( isOper(c = getOper()) )			//always an operand later
	{
		while( prior(c) <= prior(top()) )	
			printf("%c", pop());			//print and delete all oper 
		push(c);							//push c to top
		printf("%d", getNum());				//always a number after operands
	}

	while( !isEmpty() )						
		printf("%c", pop());
}