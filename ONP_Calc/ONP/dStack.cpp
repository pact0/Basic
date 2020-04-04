#include "dStack.h"
#include <memory.h>
#include <stdio.h>

dStack* initDStack()
{
	return NULL;
}

void dEmptyStack(dStack** pStack)
{
	while( !disEmpty(*pStack) )
		ddel(pStack);
}

void dpush(dStack** pStack, double c)
{
	dStackItem* dptr = (dStackItem*)malloc(sizeof(dStackItem));
	if( !dptr )
	{
		perror("ERROR: allocation.");
		return;
	}
	dptr->dcKey = c;
	dptr->dpNext = *pStack;
	*pStack = dptr;
}
double dpop(dStack** pStack)
{
	if( !disEmpty(*pStack) )
	{
		double n = dtop(*pStack);
		ddel(pStack);
		return n;
	}
	perror("ERROR: Stack underflow.\n");
	return DBL_MIN;
}
double dtop(dStack* pStack)
{
	if( !disEmpty(pStack) )
		return pStack->dcKey;

	perror("ERROR: Stack underflow.");
	return DBL_MIN;
}
void ddel(dStack** pStack)
{
	if( !disEmpty(*pStack) )
	{
		dStackItem* dptr = *pStack;
		*pStack = dptr->dpNext;
		free(dptr);
	}
	else
		perror("ERROR: Stack underflow.");
}
int disEmpty(dStack* pStack)
{
	return !pStack;
}