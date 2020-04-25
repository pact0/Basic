#include "Source.h"

int Move(int** pDepthTab, int nRow, int nCol, int nDepth, int nextMove, int x, int y, int* px, int* py, int** pRoot)
{	
	switch( nextMove )
	{
	case UP:	*px = x - 1; *py = y; break;
	case DOWN:	*px = x + 1; *py = y; break;
	case LEFT:	*py = y - 1; *px = x; break;
	case RIGHT: *py = y + 1; *px = x; break;
	default: return 0;
	}
	if( *px >= 0 && *px < nRow && *py >= 0 && *py < nCol )
		if( pDepthTab[*px][*py] > nDepth && pRoot[*px][*py] == 0 )
			return 1;
	return 0;
}

int Root(int** pDepthTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest)
{
	static int moves = 0;
	pRoot[x][y] = ++moves;

	if( x == x_dest && y == y_dest )
	{
#ifdef DEBUG
		printf("\nMoves made to reach destination: %d\n\n", moves);
#endif
		return 1;
}
	int px = x;
	int py = y;

	for( int i = UP; i <= LEFT; i++ ) {
		if( Move(pDepthTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot) )
		{
			if( Root(pDepthTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest) )
			{
				return 1;
			}
		}
	}
	moves--;
	pRoot[x][y] = 0;
	return 0;
}

int ReadDepthTab(const char* sFile, int** pTab, int nRow, int nCol)
{
	FILE* file = fopen(sFile, "r");
	if( file == NULL )
	{
		printf( "Cannot open %s", file );
		return 0;
	}
	for( int i = 0; i < nRow; i++ )
	{
		int* pCursor = *pTab++;
		for( int j = 0; j < nCol; j++ )
			fscanf( file, "%d", pCursor++ );
	}
	fclose(file);
	return 1;
}

int** CreateTab(int nRow, int nCol)
{
	int **tab = (int**)calloc( 1, nRow * sizeof(int*) );
	if( tab == NULL ) return NULL;
	*tab = (int*)calloc( 1, nRow * nCol * sizeof(int) );
	if( *tab == NULL ) 
	{
		free(*tab);
		return NULL;
	}
	int** p = tab;
	int* t = *tab;
	for( int i = 0; i < nRow; ++i )
	{
		*p++ = t;
		t += nCol;
	}
	return tab;
}

void PrintTab(int** pRoot, int nRow, int nCol)
{
	for( int i = 0; i < nRow; i++)
	{
		int *p = *pRoot++;
		for( int j = 0; j < nCol; j++ )
			printf("%d ", *p++);
		printf("\n");
	}
}

void FreeTab(int*** pTab)
{
	free(**pTab);
	free(*pTab);
	*pTab = NULL;
}	