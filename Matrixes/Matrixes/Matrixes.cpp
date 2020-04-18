#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define _DEBUG_
#include "Source.h"

void PrintVec(double* vec, int nSize);
void ReadData(FILE* fin, double** pMatrix, double* b, int nDim);
int CreateVector(double** vec, int nSize);


int main(int argc, const char* argv[])
{
	if( argc != 2 ) 
	{
		printf( "Usage: %s <input_file>\n", argv[0] );
		return 1;
	}
	FILE* file = fopen(argv[1], "r");
	if( file == NULL ) 
	{
		printf( "Cannot open %s",argv[1] );
		return 1;
	}
	int nDim = 0;												//Dimension of a matrix
	fscanf( file, "%d", &nDim );								//Read only the dimension, expected to be first in file
	double** mat = NULL;										//Matrix

	if( CreateMatrix(&mat, nDim) == 0 )							//Allocate data for a matrix
	{
		perror("Allocation error while creating main matrix.\n");
		return 2;
	}
	double* b = NULL;											//Vector
	if( CreateVector(&b, nDim) == 0 )
	{
		perror("Error allocating memory for data vector.\n");
		return 3;
	}
	

	ReadData(file, mat, b, nDim);
	fclose(file);
#ifdef _DEBUG_
	printf("Input matrix:\n");
	PrintMatrix(mat, nDim);
	printf("\nInput vector: \n");
	PrintVec(b, nDim);
#endif
	double det = Det(mat, nDim);

	if( fabs(det) <= 1e-16 )
	{
		perror("Macierz osobliwa.\n");
		return 4;
	}

	double** invMat = NULL;
	if( CreateMatrix(&invMat, nDim) == 0 )
	{
		perror("Allocation error while creating an inverse matrix.\n");
		return 5;
	}

	InverseMatrix(invMat, mat, nDim, det);
#ifdef _DEBUG_
	printf("\nInv matrix:\n");
	PrintMatrix(invMat, nDim);
	printf("\nDet: %lf\n", det);
#endif
	double* res = NULL;
	if( CreateVector(&res, nDim) == 0 ) 
	{
		perror("Error allocating memory for result vector.\n");
		return 6;
	}

	LayoutEqu(invMat, b, res, nDim);
	printf("\nThe result is:\n");
	PrintVec(res, nDim);

	DeleteMatrix(&mat, nDim);
	DeleteMatrix(&invMat, nDim);
	free(res);
	free(b);
	system("PAUSE");

}

void ReadData(FILE* fin, double** pMatrix, double* b, int nDim)
{
	for( int i = 0; i < nDim; i++ ) 
	{
		double* pCursor = *pMatrix++;
		for( int j = 0; j < nDim; j++ )
			fscanf( fin, "%lf", pCursor++ );
		fscanf( fin, "%lf", b++ );
	}
}

int CreateVector(double** vec, int nSize) 
{
	*vec = (double*)malloc( sizeof(double) * nSize );								//Allocate data for vector b
	if( *vec == NULL ) {
		return 0;
	}
	memset( *vec, 0, sizeof(double) * nSize );
	return 1;
}
void PrintVec(double* vec, int nSize) 
{
	for( int i = 0; i < nSize; i++ )
		printf("%lf\n", *vec++);
}

