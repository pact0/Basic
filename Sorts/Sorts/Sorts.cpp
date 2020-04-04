#include <iostream>
#include "Sorts.h"
#include <time.h>

#define DEBUG

void print_arr(double* arr, int n);
void Measure(double* tab, int n, int i);

void ( *fun[] )( double* x, int n )={
	HeapSort,
	InsterionSort,
	SelectionSort,
	BubbleSort,
	BinaryInsertionSort,
	QuickSort,
	MixedSort
};

const char* funNames[] ={
	"HeapSort",
	"InsterionSort",
	"SelectionSort",
	"BubbleSort",
	"BinaryInsertionSort",
	"QuickSort",
	"MixedSort"
};

int main(int argc, char* argv[])
{
	if( argc != 2 )
	{
		printf("Usage: %s, <tab_size>", argv[0]);
		return 1;
	}
	srand(time(NULL));
	int nSize = atoi(argv[1]);

	double* pTab = NULL;
	pTab = CreateTab(nSize);
	if( pTab == NULL )
	{
		printf("Error allocating memory for main tab\n");
		return 1;
	}

	for( int i = 0; i < nSize; i++ )
	{
		pTab[i] = rand() % nSize;
	}

	double* pTabCopy = NULL;
	pTabCopy = CreateTab(nSize);
	if( pTabCopy == NULL )
	{
		printf("Error allocating memory for a copy\n");
		return 1;
	}
	memcpy(pTabCopy, pTab, nSize * sizeof(double));

#ifdef DEBUG
	print_arr(pTabCopy, nSize);
#endif

	for( int i = 0; i < 7; i++ )
	{
		Measure(pTabCopy, nSize, i);
		memcpy(pTabCopy, pTab, nSize * sizeof(double));
	}
	
	free(pTab);
	free(pTabCopy);
	system("PAUSE");
}


void print_arr(double* arr, int n)
{
	for( int i = 0; i < n; i++ )
	{
		printf("%lf  ", arr[i]);
	}
	printf("\n\n");
}

void Measure(double* tab, int n, int i)
{
	printf("%s:\n", funNames[i]);

	clock_t start = clock();
	fun[i](tab, n);
	double Time = ((double)(clock()) - start) / CLOCKS_PER_SEC;

#ifdef DEBUG
	print_arr(tab, n);
#endif

	printf("Time elapsed: %lf in seconds \n\n", Time);
}