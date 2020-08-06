#include "PQueue.h"
#define DEBUG

void ClearFun( const void* p );
int CompareFun( const void* p, const void* q );
void PrintInfo( const void* p );

int main()
{
	int size = 5;
	if( size <= 0 ) {
		printf("Size can't be lower or equal to zero.");
		return 1;
	}
	PQueue* Queue = PQInit( 5 );
	if( Queue == NULL ) return 1;

	PQINFO p;
	PQINFO p2;
	PQINFO p3;
	PQINFO p4;
	PQINFO p5;
	
	p.pTab  = (int*)( malloc(2 * sizeof( int ) ) ); if( p.pTab  == NULL ) return 1;
	p2.pTab = (int*)( malloc(2 * sizeof( int ) ) ); if( p2.pTab == NULL ) return 1;
	p3.pTab = (int*)( malloc(2 * sizeof( int ) ) ); if( p3.pTab == NULL ) return 1;
	p4.pTab = (int*)( malloc(2 * sizeof( int ) ) ); if( p4.pTab == NULL ) return 1;
	p5.pTab = (int*)( malloc(2 * sizeof( int ) ) ); if( p5.pTab == NULL ) return 1;

	p.nKey  = 1;	p.pTab[0]  = 11;	p.pTab[1]  = 12;
	p2.nKey = 2;	p2.pTab[0] = 21;	p2.pTab[1] = 22;
	p3.nKey = 90;	p3.pTab[0] = 31;	p3.pTab[1] = 32;
	p4.nKey = 21;	p4.pTab[0] = 31;	p4.pTab[1] = 32;
	p5.nKey = 4;	p5.pTab[0] = 31;	p5.pTab[1] = 32;

	if( !PQEnqueue( Queue, 10, &p	) )	{ printf( "Couldn't add to queue" ); return 1; }
	free(PQDequeue(Queue)->pTab);

#ifdef DEBUG
	PQPrint(Queue, 0, PrintInfo);	
	printf("\n\n");
#endif
	if( !PQEnqueue( Queue, 12, &p2	) )	{ printf( "Couldn't add to queue" ); return 1; }
#ifdef DEBUG
	PQPrint(Queue, 0, PrintInfo);	printf("\n\n");
#endif
	if( !PQEnqueue( Queue, 33, &p3	) )	{ printf( "Couldn't add to queue" ); return 1; }
#ifdef DEBUG
	PQPrint(Queue, 0, PrintInfo);
	printf("\n\n");
#endif
	if( !PQEnqueue( Queue, 7, &p4	) )	{ printf( "Couldn't add to queue" ); return 1; }
#ifdef DEBUG
	PQPrint(Queue, 0, PrintInfo);
	printf("\n\n");
#endif
	if( !PQEnqueue( Queue, 4, &p5	) )	{ printf( "Couldn't add to queue" ); return 1; }

#ifdef DEBUG
	PQPrint(Queue, 0, PrintInfo );
	printf( "\n\n" );
#endif
	printf( "%d \n\n",PQGetPrior( Queue, Queue->pPQueue[1].pInfo, CompareFun ) );
	PQSetPrior(Queue, Queue->pPQueue[1].pInfo, 7, CompareFun);
	printf( "%d \n\n", PQGetPrior( Queue, Queue->pPQueue[1].pInfo, CompareFun ) );
	printf( "max prior: %d\n\n", PGMaxPrior( Queue ) );
#ifdef DEBUG
	PQPrint( Queue, 0, PrintInfo );
	printf( "\n\n" );
#endif
	free( PQDequeue( Queue )->pTab );
#ifdef DEBUG
	PQPrint( Queue, 0, PrintInfo );	printf("\n\n");
#endif
	free( PQDequeue( Queue )->pTab );
#ifdef DEBUG
	PQPrint( Queue, 0, PrintInfo );	
	printf("\n\n");
#endif
	PQClear( Queue, ClearFun );
#ifdef DEBUG
	PQPrint( Queue, 0, PrintInfo );	
	printf("\n\n");
#endif
	PQRelease( &Queue, ClearFun );
	return 0;
}

void ClearFun( const void* p ) {
	if( !p ) return;
	free( ( (PQINFO*)p )->pTab );
}

int CompareFun( const void* p, const void* q ) {
	if( ( ( PQINFO* )p )->nKey > ( ( PQINFO* )q )->nKey )
		return 1;
	else if( ( ( PQINFO* )p )->nKey < ( ( PQINFO* )q )->nKey )
		return -1;
	return 0;
}

void PrintInfo( const void* p ) {
	printf( "value: %d ", ( ( PQINFO* )p )->nKey );
}