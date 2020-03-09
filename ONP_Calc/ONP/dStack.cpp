#include "dStack.h"
#include <memory.h>
#include <stdio.h>
#define MAXSTACK 32 

double dStack[MAXSTACK] = {};
int ndHead = 0;

void demptyStack()
{
	memset(dStack, 0, MAXSTACK * sizeof(double));  
	ndHead = 0;
}
void dpush(double c)
{
	if( ndHead >= MAXSTACK )
	{
		printf("ERROR: stack overflow.\n");
		return;
	}
	dStack[ndHead++] = c;
}
double dpop()
{
	if( !disEmpty() )
	{
		double n = dtop();
		ddel();
		return n;
	}
	printf("ERROR: Stack underflow. \n");
	return DBL_MIN;
}
double dtop()
{
	if( !disEmpty() )
		return dStack[ndHead - 1];
	return DBL_MIN;
}
void ddel()
{
	if( !disEmpty() )
		ndHead--;
	else
		printf("ERROR: Stack underflow.");

}
int disEmpty()
{
	return !ndHead;
}