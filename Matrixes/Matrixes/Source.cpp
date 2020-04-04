#include "Source.h"

void Cut(double** pTabO, double** pTabI, int nRow, int nCol, int nDim);		//cuts out
void ComplMatrix(double** pTabD, double** pTab, int nDim);					//compliment matrix

int CreateMatrix(double*** pTab, int nSize)
{
	*pTab = (double**)malloc( nSize * sizeof(double*) );
	if( !pTab )
		return 0;

	memset( *pTab, 0, nSize * sizeof(double*) );
	double** p = *pTab;
	for( int i = 0; i < nSize; i++, p++ )
	{
		*p = (double*)malloc( nSize * sizeof(double) );
		if( !*p )
			return 0;

		memset( *p, 0, nSize * sizeof(double) );
	}
	return 1;
}

void DeleteMatrix(double*** pTab, int nSize)
{
	double** tmp = *pTab;
	for( int i = 0; i < nSize; i++ )  
		free(*tmp++);
	free(*pTab);
	*pTab = NULL;
}

void PrintMatrix(double** pTab, int nSize)
{
	for( int i = 0; i < nSize; i++ )
	{
		double* tmp = *pTab++;
		for( int j = 0; j < nSize; j++ )
			printf("%lf ", *tmp++);
		printf("\n");
	}
}

double Det(double** pTab, int nSize)
{
	if( nSize == 1 )
		return **pTab;
	else if( nSize == 2 )
	{
		return ( (**pTab * pTab[1][1] ) - ( pTab[0][1] * pTab[1][0]) );
	}
	double** minor = NULL;	
	if( CreateMatrix(&minor, nSize - 1) == 0 ) 
	{
		perror("Error creating a minor matrix.(Det)\n");
		return DBL_MIN;
	}

	double det = 0;
	int sign = 1;
	double* ptr = *pTab;
	for( int i = 0; i < nSize; i++ )
	{
		Cut(minor, pTab, 0, i, nSize);
		det += sign * Det(minor, nSize - 1) * *ptr++;
		sign = -sign;
	}
	DeleteMatrix(&minor, nSize - 1);
	return det;
}

void TransMatrix(double** pTab, int nDim)
{
	
	double** ptr = pTab;
	for( int i = 0; i < nDim - 1; i++ ) 
	{
		double* temp = *ptr++ + i +1;
		for( int j = i + 1; j < nDim; j++ )
		{
			double t = *temp;
			*temp++ = pTab[j][i];
			pTab[j][i] = t;
		}
	}
	/*
	double** ptr = pTab;
	for( int i = 0; i < nDim - 1; i++ )
	{
		for( int j = i + 1; j < nDim; j++ )
		{
			double temp = ptr[i][j];
			ptr[i][j] = ptr[j][i];
			ptr[j][i] = temp;
		}
	}
	*/
}
void InverseMatrix(double** pInv, double** pTab, int nSize, double det)
{
	ComplMatrix(pInv, pTab, nSize);
	TransMatrix(pInv, nSize);

	for( int i = 0; i < nSize; i++ )										//divide by Det pTab
	{
		double* temp = *pInv++;
		for( int j = 0; j < nSize; j++ )
			*temp++ /= det;
	}
}
void LayoutEqu(double** pInv, double* pB, double* pRes, int nSize)
{
	for( int i = 0; i < nSize; i++, pRes++ ) {
		double* ptr = *pInv++;
		double *temp = pB;
		for( int j = 0; j < nSize; j++ )
			*pRes += *ptr++ * *temp++;
	}
}

void ComplMatrix(double** pTabD, double** pTab, int nDim)
{
	double** ptr;
	CreateMatrix(&ptr, nDim);

	for( int i = 0; i < nDim; i++ ) 
	{
		int sign = ( i % 2 ) ? -1 : 1;
		double* temp = *pTabD++;
		for( int j = 0; j < nDim; j++ ) 
		{
			Cut(ptr, pTab, i, j, nDim);										//Create a new minor for row i and col j
			*temp++ = Det(ptr, nDim - 1) * sign;
			sign = -sign;
		}
	}
	DeleteMatrix(&ptr, nDim - 1);
}

void Cut(double** pTabO, double** pTabI, int nRow, int nCol, int nDim)
{
	for( int i = 0; i < nDim; i++, pTabI++ ) 
	{
		if( i == nRow )
			continue;
		double* pIn = *pTabI;
		double* pOut = *pTabO++;

		for( int j = 0; j < nDim; j++, pIn++ )
		{
			if( j == nCol ) 
				continue;
			*pOut++ = *pIn;
		}
	}
}