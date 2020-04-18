#include "Source.h"

int Move(int** pDepthTab, int nRow, int nCol, int nDepth, int nextMove, int x, int y, int* px, int* py, int** pRoot)
{
	switch( nextMove )
	{
	case UP:	*px = x + 1; break; 
	case DOWN:	*px = x - 1; break; 
	case LEFT:	*py = y + 1; break; 
	case RIGHT: *py = y - 1; break; 
	}
	if( *px >= nRow || *px < 0 || *py >= nCol || *py < 0 || pRoot[*px][*py] != 0 || nDepth >= pDepthTab[*px][*py] )
	{
		*px = x;
		*py = y;
		return 0;
	}
	return 1;
}

int Root(int** pDepthTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest)
{
	static int moves = 0;
	++moves;
	pRoot[x][y] = moves;

	if( x == x_dest && y == y_dest )
	{
		printf( "\nMoves made to reach destination: %d\n\n", moves );
		return 1;
	}
	int px = x;
	int py = y;

	for( int i = UP; i <= LEFT; i++ )
		if( Move(pDepthTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot) )
			if( Root(pDepthTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest) )
				return 1;

	pRoot[x][y] = 0;
	return 0;
}

void ReadDepthTab(const char* sFile, int** pTab, int nRow, int nCol)
{
	FILE* file = fopen(sFile, "r");
	if( file == NULL )
	{
		printf( "Cannot open %s", file );
		return;
	}
	for( int i = 0; i < nRow; i++ )
	{
		int* pCursor = *pTab++;
		for( int j = 0; j < nCol; j++ )
			fscanf( file, "%d", pCursor++ );
	}
	fclose(file);
}

int** CreateTab(int nRow, int nCol)
{
	int **tab = (int**)calloc( 1, nRow * sizeof(int*) );
	if( !tab ) return NULL;

	*tab = (int*)calloc( 1, nRow * nCol * sizeof(int) );
	if( *tab == NULL ) 
	{
		free(*tab);
		*tab = NULL;
		return NULL;
	}
	int** p = tab;
	for( int i = 0; i < nRow; ++i )
	{
		*p++ = *tab + i * nCol;
	}
	return tab;
}

void PrintTab(int** pRoot, int nRow, int nCol)
{
	for( int i = 0; i < nRow; i++ )
	{
		for( int j = 0; j < nCol; j++ )
			printf("%d ", pRoot[i][j]);
		printf("\n");
	}
}

void FreeTab(int*** pTab)
{
	free(**pTab);
	free(*pTab);
	*pTab = NULL;
}	