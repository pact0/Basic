#ifndef MATRIX_H
#include <memory.h>
#include <iostream>

int CreateMatrix(double*** pTab, int nSize);								//creates a matrix
double Det(double** pTab, int nSize);										//recursive det
void DeleteMatrix(double*** pTab, int nSize);								//removes the matrix and its elements
void PrintMatrix(double** pTab, int nSize);									//printf a matrix
void TransMatrix(double** pTab, int nDim);									//transpones a matrix
void InverseMatrix(double** pInv, double** pTab, int nSize, double det);	//interverses a matrix 
void LayoutEqu(double** pInv, double* pB, double* pRes, int nSize);			//rozwiazuje ukl rownan
#endif
