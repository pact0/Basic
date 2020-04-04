#include <iostream>
#include "Source.h"
#include "Stack.h"
#include "dStack.h"

void skipSpaces()
{
	char c;
	while( ( c = getchar() ) == ' ' );

	ungetc(c, stdin);
}
double getNum()
{
	char c;
	int sign = 1;
	double value = 0;
	double coef = 0.1;

	skipSpaces();

	if( ( c = getchar() ) == '+' || c == '-' )
	{
		if( c == '-' )
			sign = -1;
	}
	else
		ungetc(c, stdin);

	while( isDigit(c = getchar()) )
		value = value * 10 + ( c - (double)'0' );

	if( c == DOT )
		while( isDigit(c = getchar()) )
		{
			value += ( c - (double)'0' ) * coef;
			coef *= 0.1;
		}
	ungetc(c, stdin);						//this will be an operand so return it to stdin

	if( sign == -1 )
		return -value;

	return value;
}
int isDigit(char c)
{
	return( c >= '0' && c <= '9' );
}
int isOper(char nOper)
{
	switch( nOper )
	{
	case '+': //move to next
	case '-': //++
	case '/': //++
	case '*': //++
	case '^': return 1;
	}
	return 0;
}
int prior(char nOper)
{
	switch( nOper )
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


double onp_calc()
{
	char c;
	Stack* pStack = initStack();
	dStack* pdStack = initDStack();
	dpush(&pdStack, getNum());						//assumed that always a number 1st
	while( isOper(c = getOper()) )					//always an operand later
	{
		while( prior(c) <= prior(top(pStack)) )
		{
			double arg2 = dpop(&pdStack);
			dpush(&pdStack, Eval(dpop(&pdStack), arg2, pop(&pStack)));
		}
		push(&pStack, c);							//push c to top
		dpush(&pdStack, getNum());					//always a number after an operand
	}

	while( !isEmpty(pStack) )
	{
		double arg2 = dpop(&pdStack);
		dpush(&pdStack, Eval(dpop(&pdStack), arg2, pop(&pStack)));
	}



	return dpop(&pdStack);
}

double Eval(double arg1, double arg2, char nOper)
{

	switch( nOper )
	{
	case '+': return arg1 + arg2;
	case '-': return arg1 - arg2;
	case '/': if( fabs(arg2) > 1e-15 )
		return arg1 / arg2;
		perror("ERROR: Stack overflow.");
		return DBL_MIN;
	case '*': return arg1 * arg2;
	case '^': return pow(arg1, arg2);
	}

	return DBL_MIN;
}
