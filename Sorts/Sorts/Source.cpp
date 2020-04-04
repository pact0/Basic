#include "Sorts.h"
void QuickSortHelper(double* tab, int i, int n);
void Update(double *tab,int l,int p);

void HeapSort(double* tab, int n)
{
	
	for( int j = n / 2; j >= 0; j-- )
	{
		Update(tab, j, n - 1);
	}
	for( int j = n - 1; j > 0; j-- )
	{
		double x = tab[j];
		tab[j] = tab[0];
		tab[0] = x;
		Update(tab, 0, j - 1);
	}
	
}

void Update(double *tab,int l, int p)
{
	int i = l;
	int j = 2 * i;
	double x = tab[i];

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
		j = 2 * i;
	}
	tab[i] = x;

	/*int v = l;
	while( true )
	{
		int left = 2 * v;
		int right = left + 1;
		if( left > p )
			return;
		int m = left;
		if( left < p )
			if( tab[left] < tab[right] )
				m = right;
		if( tab[m] <= tab[v] ) 
			break;

		double x = tab[v];
		tab[v] = tab[m];
		tab[m] = x;
		v = m;
	}
	*/
}

void InsterionSort(double* tab, int n)
{
	for( int i = 1; i < n; i++ )
	{
		double x = tab[i];
		int j = i - 1;
		while( x < tab[j] )
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = x;
	}
}
	
void SelectionSort(double* tab, int n)
{
	for( int i = 0; i < n-1; i++ )
	{
		int k = i;
		double x = tab[i];
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

void BubbleSort(double* tab, int n)
{
	for(int i = 1; i < n; i++ )
		for( int j = n-1; j >= i; j-- )
		{
			if( tab[j-1] > tab[j] )
			{
				double x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
			}
		}
}

void BinaryInsertionSort(double* tab, int n)
{
	for( int i = 1; i < n; i++ )
	{
		int p = i - 1;
		double x = tab[i];
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
void QuickSort(double* tab, int n)
{
	QuickSortHelper(tab, 0, n-1);
}
void QuickSortHelper(double* tab, int l, int p)
{
	int i = l;
	int j = p;
	double x = tab[( l + p  ) / 2];

	do
	{
		while( tab[i] < x )
			i++;
		while( x < tab[j] )
			j--;
		if( i <= j )
		{
			double w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
	} while( i <= j );

	if( l < j )
		QuickSortHelper(tab, l, j);
	if( i < p )
		QuickSortHelper(tab, i, p);
}

void MixedSort(double* tab, int n)
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
				double x = tab[j - 1];
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
				double x = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		p = k - 1;
	} while( l <= p );
}

void Swap(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

double* CreateTab(int nSize) 
{
	double* tmp = NULL;
	tmp = (double*)malloc(sizeof(double) * nSize);
	if( tmp == NULL )
		return NULL;
	memset(tmp, 0, sizeof(double) * nSize);
	return tmp;
}

