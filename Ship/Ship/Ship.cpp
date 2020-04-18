#include "Source.h"
#define N 6
#define M 7

#define DEBUG

int main(int argc, const char* argv[])
{
	if( argc != 2 ) 
	{
		printf( "Usage: argv[0], <input_file>\n" );
		return 1;
	}

	int** t = CreateTab(N, M);
	int** p = CreateTab(N, M);
	ReadDepthTab( "test.txt", t, N, M);
	
#ifdef DEBUG
	printf("DepthTab: \n");
	PrintTab(t, N, M);
	printf("\n");
	printf("ResTab: \n");
	PrintTab(p, N, M);
	printf("\n");
#endif

	if( !Root(t, N, M, t[0][0], 0, 0, p, N - 1, M - 1) )
		printf("Can't reach the destination.\n");
	else
	{
		printf("ResTab: \n");
		PrintTab(p, N, M);
	}

	FreeTab(&t);
	FreeTab(&p);
	//jezeli ok - wypisac trase - czyli tablice z ruchami (pole zawieracje numer ruchu)
	// pokazuja kolejnosc ruchu staku. 0 jest polem nieodwiedzonym (lub odwiedzonym ale statek nie 
	// mogl tam plynac wiec trzeba przywrocic 0)	
}
