#ifndef STACK_H

#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#define DOT '.'

typedef struct tagStackItem
{
	char cKey;
	tagStackItem* pNext;
}StackItem;

typedef StackItem Stack;

Stack* initStack();
void push(Stack** pStack ,char c );				//put c on stack
char pop(Stack** pStack);						//return top element and delete it
char top(Stack* pStack);						//return top element of stack
void del(Stack** pStack);						//delete top element of stack
int isEmpty(Stack* pStack);						//check whether stack is empty
void EmptyStack(Stack** pStack);
#endif 