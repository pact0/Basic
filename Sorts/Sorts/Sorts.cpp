#include "Sorts.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//#define DEBUG
int* CreateTab( int nSize );
typedef void ( *Func )( int*, int );
void print_arr( int* arr, int n ); 
void Measure( int* tab, int n, int i, const char** funNames, Func* fun );
void RandomFill( int* tab, int size );

int main(int argc, char* argv[])
{
	if( argc != 2 ) { printf( "Usage: %s	<tab_size>	", argv[0] ); return 1; }

	srand( (int)time( NULL ) );
	int nSize = atoi( argv[1] );

	int* pTab = CreateTab( nSize );
	if( pTab == NULL ) { printf( "Error allocating memory for main tab\n" ); return 2; }

	int* pTabCopy = CreateTab( nSize );
	if( pTabCopy == NULL ) { printf("Error allocating memory for a copy\n"); return 3; }

	RandomFill( pTab, nSize );

	Func fun[] = {
	HeapSort,
	InsterionSort,
	SelectionSort,
	BubbleSort,
	BinaryInsertionSort,
	QuickSort,
	MixedSort };

	const char* funNames[] = {
		"HeapSort",
		"InsterionSort",
		"SelectionSort",
		"BubbleSort",
		"BinaryInsertionSort",
		"QuickSort",
		"MixedSort"
	};

#ifdef DEBUG
	print_arr( pTab, nSize );
#endif

	for( int i = 0; i < sizeof( fun )/sizeof( Func ); ++i )
	{
		memcpy( pTabCopy, pTab, nSize * sizeof(int) );
		Measure( pTabCopy, nSize, i, funNames, fun );
	}
	
	free(pTab);
	free(pTabCopy);
	system("PAUSE");
	return 0;
}


void print_arr( int* arr, int n )
{
	for( int i = 0; i < n; ++i )
	{
		printf( "%d  ", *arr++ );
	}
	printf( "\n\n" );
}

void Measure( int* tab, int n, int i, const char** funNames, Func* fun )
{
	printf( "%s:\n", funNames[i] );

	clock_t start = clock();
	fun[i]( tab, n );
	double Time = ( (double)(clock()) - start ) / CLOCKS_PER_SEC;

#ifdef DEBUG
	print_arr(tab, n);
#endif

	printf( "Time elapsed: %lf in seconds \n\n", Time );
}

int* CreateTab( int nSize )
{
	int* tmp = (int*)malloc( sizeof(int) * nSize );
	if( tmp )
		memset( tmp, 0, sizeof(int) * nSize );
	return tmp;
}

void RandomFill( int* tab, int size )
{
	for( int i = 0; i < size; ++i )
		*tab++ = rand() % size;
}