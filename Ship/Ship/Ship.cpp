#include "Source.h"
#define N 8
#define M 8
//#define DEBUG
int main(int argc, char* argv[])
{
	if( argc != 2 ) 
	{
		printf( "Usage: argv[0], <input_file>\n" );
		return 1;
	}
	int** t = CreateTab(N, M);
	if( t == NULL )
	{
		printf("Allocation error. (CreateTab t)\n");
		return 1;
	}
	int** p = CreateTab(N, M);
	if( p == NULL )
	{
		printf("Allocation error. (CreateTab p)\n");
		return 1;
	}
#ifdef DEBUG
	printf("DepthTab: \n");
	PrintTab(t, N, M);
	printf("\n");
	printf("ResTab: \n");
	PrintTab(p, N, M);
	printf("\n");
#endif
	if( ReadDepthTab("test.txt", t, N, M) )
	{
#ifdef DEBUG
		printf("DepthTab: \n");
		PrintTab(t, N, M);
		printf("\n");
#endif
		if( !Root(t, N, M, t[0][0], 0, 0, p, N - 1, M - 1) )
			printf("Can't reach the destination.\n");
		else
		{
			printf("ResTab: \n");
			PrintTab(p, N, M);
		}
	}
	FreeTab(&t);
	FreeTab(&p);
	return 0;
}