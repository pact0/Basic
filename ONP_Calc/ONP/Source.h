#ifndef SOURCE

#define SOURCE
#include <iostream>
double onp_calc();
void skipSpaces();
double getNum();									// number with sign 
int isDigit(char c);								// returns true/false whether input is a digit
int isOper(char nOper);								// returns true/false whether input is an operand
int prior(char nOper);								// priority of operands					
char getOper();										// reads an operand									
double Eval(double arg1, double arg2, char nOper);	// calculates the value 

#endif 