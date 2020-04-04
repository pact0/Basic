#include "Stack.h"

Stack* initStack()
{
	return NULL;
}

void EmptyStack(Stack** pStack)
{
	while( !isEmpty(*pStack) )
		del(pStack);
}

void push(Stack** pStack, char c)
{
	StackItem* ptr = (StackItem*)malloc(sizeof(StackItem));
	if( !ptr )
	{
		perror("ERROR: allocation.");
		return;
	}
	ptr->cKey = c;
	ptr->pNext = *pStack;
	*pStack = ptr;
}
char top(Stack* pStack)
{
	if( !isEmpty(pStack) )
		return pStack->cKey;
	return 0;
}
void del(Stack** pStack)
{
	if( !isEmpty(*pStack) )
	{
		StackItem* ptr = *pStack;
		*pStack = ptr->pNext;
		free(ptr);
	}
	else
		perror("ERROR: Underflow.");
}

char pop(Stack** pStack)
{
	char c;
	if( c = top(*pStack) )
	{
		del(pStack);
		return c;
	}
	perror("ERROR: Stack underflow.");
	return 0;
}

int isEmpty(Stack* pStack)
{
	return !pStack;
}
