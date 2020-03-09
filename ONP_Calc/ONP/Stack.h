#ifndef STACK_H

#define STACK_H
#include <stdio.h>
#define DOT '.'


void push( char c );  //put c on stack
char pop();			  //return top element and delete it
char top();			  //return top element of stack
void del();			  //delete top element of stack
int isEmpty();		  //check whether stack is empty

#endif 