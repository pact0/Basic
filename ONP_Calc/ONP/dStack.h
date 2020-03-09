#ifndef STACK_H_d

#define STACK_H_d
#include <stdio.h>
#include <float.h>


void dpush(double c);	  //put c on stack
double dpop();			  //return top element and delete it
double dtop();			  //return top element of stack
void ddel();			  //delete top element of stack
int disEmpty();		      //check whether stack is empty
double Eval(double arg1, double arg,char nOper);
#endif 