#include "Sorts.h"
void QuickSortHelper( int* tab, int i, int n );
void Update( int *tab,int l,int p );

void HeapSort(int* tab, int n)
{
	
	for( int j = n / 2; j >= 0; j-- )
	{
		Update( tab, j, n - 1 );
	}
	for( int j = n - 1; j > 0; j-- )
	{
		int x = tab[j];
		tab[j] = tab[0];
		tab[0] = x;
		Update( tab, 0, j - 1 );
	}
	
}

void Update( int *tab,int l, int p )
{
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1;
	int x = tab[i];

	while( j <= p )
	{
		if( j < p )
		{
			if( tab[j] < tab[j + 1] )
				j++;
		}
		if( x >= tab[j] )
			break;
		tab[i] = tab[j];
		i = j;
		j = 2 * i + 1;
	}
	tab[i] = x;
}

void InsterionSort( int* tab, int n )
{
	for( int i = 1; i < n; i++ )
	{
		int x = tab[i];
		int j = i - 1;
		while( j >= 0 && x < tab[j] )
		{
			tab[j + 1] = tab[j--];
		}
		tab[j + 1] = x;
	}
}
	
void SelectionSort( int* tab, int n )
{
	for( int i = 0; i < n-1; i++ )
	{
		int k = i;
		int x = tab[i];
		for( int j = i+1; j < n; j++ )
		{
			if( tab[j] < x )
			{
				k = j;
				x = tab[j];
			}
		}
		tab[k] = tab[i];
		tab[i] = x;
	}
}

void BubbleSort( int* tab, int n )
{
	for( int i = 1; i < n; i++ )
		for( int j = n-1; j >= i; j-- )
		{
			if( tab[j-1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
			}
		}
}

void BinaryInsertionSort( int* tab, int n )
{
	for( int i = 1; i < n; i++ )
	{
		int p = i - 1;
		int x = tab[i];
		int l = 0;

		while( l <= p )
		{
			int m = ( l + p ) / 2;
			if( x < tab[m] )
				p = m - 1;
			else
				l = m + 1;
		}
		for( int j = i - 1; j >= l; j-- )
			tab[j + 1] = tab[j];
		tab[l] = x;
	}
}
void QuickSort( int* tab, int n )
{
	QuickSortHelper( tab, 0, n-1 );
}

void QuickSortHelper( int* tab, int l, int p )
{
	int i = l;
	int j = p;
	int x = tab[( l + p  ) / 2];

	do
	{
		while( tab[i] < x )
			i++;
		while( x < tab[j] )
			j--;
		if( i <= j )
		{
			int w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
	} while( i <= j );

	if( l < j )
		QuickSortHelper( tab, l, j );
	if( i < p )
		QuickSortHelper( tab, i, p );
}

void MixedSort( int* tab, int n )
{
	int l = 1;
	int p = n-1; 
	int k = n-1;
	do
	{
		for( int j = p ; j >= l; j-- )
		{
			if( tab[j - 1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		l = k + 1;
		for( int j = l; j <= p; j++ )
		{
			if( tab[j - 1] > tab[j] )
			{
				int x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		p = k - 1;
	} while( l <= p );
}