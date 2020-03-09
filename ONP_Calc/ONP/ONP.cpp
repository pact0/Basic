#include <iostream>
#include "ONP.h"
#include "Stack.h"
#include "dStack.h"

int main()
{
	onp();
}


void skipSpaces()
{
	char c;
	while( ( c = getchar() ) == ' ' );

	ungetc(c, stdin);
}
double getNum()// reads number and its sign  -123
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
		value = value * 10 + ( c - '0' );		//get the value 

	if( c == DOT )
		while( isDigit(c = getchar()) )
		{
			value += ( c - '0' ) * coef;
			coef *= 0.1;
		}
	ungetc(c, stdin);						//this will be an operand so return it to stdin
	return sign * value;
}
int isDigit(char c)
{
	return( c >= '0' && c <= '9' );
}
int isOper(char nOper) // + - / ^ *
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
int prior(char nOper)// priority of oper    1. (+ -)  2. (* /) 3. ^
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


double onp()
{
	char c;
	dpush( getNum());					//assumed that always a number 1sr
	while( isOper(c = getOper()) )			//always an operand later
	{
		while( prior(c) <= prior(top()) )
			Calc();
		push(c);							//push c to top
		dpush(getNum());				//always a number after operands
	}

	while( !isEmpty() )
		Calc();

	printf("%lf", dpop());
		return 0;
}

double Eval(double arg1, double arg2, char nOper)
{

	switch(nOper)
	{
	case '+': return arg1 + arg2;
	case '-': return arg1 - arg2;
	case '/': if( fabs(arg2) > 1e-15 )
				return arg1 / arg2;
		perror("ERROR: ");
	case '*': return arg1 * arg2;
	case '^': return pow(arg1,  arg2);
	}

	return 0;
}

void Calc()
{
	double arg2 = dpop();
	dpush(Eval(dpop(), arg2, pop()));
}