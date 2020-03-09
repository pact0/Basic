#include "Stack.h"

#define MAXSTACK 32

char Stack[MAXSTACK] = {};
int nHead = 0;				//index of first empty element of the stack 

void push(char c)
{
	if (nHead >= MAXSTACK)
	{
		printf("ERROR: stack overflow.\n");
		return;
	}
	Stack[nHead++] = c;
}
char pop()
{
	char c;
	if (c = top())
	{
		del();
		return c;
	}
	printf("ERROR: Stack underflow. \n");
	return 0;
}
char top()
{
	if (!isEmpty())
		return Stack[nHead - 1];
	return 0;
}
void del()
{
	if (!isEmpty())
		nHead--;
	else
		printf("ERROR:");

}
int isEmpty()
{
	return !nHead;
}