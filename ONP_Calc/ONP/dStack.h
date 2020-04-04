#ifndef STACK_H_d

#define STACK_H_d
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct tagdStackItem
{
	double dcKey;
	tagdStackItem* dpNext;
}dStackItem;

typedef dStackItem dStack;

dStack* initDStack();
void dpush(dStack** pStack, double c);			//put c on stack
double dpop(dStack** pStack);					//return top element and delete it
double dtop(dStack* pStack);					//return top element of stack
void ddel(dStack** pStack);						//delete top element of stack
int disEmpty(dStack* pStack);					//check whether stack is empty
void dEmptyStack(dStack** pStack);
#endif 