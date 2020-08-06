#include "PQueue.h"
void UpdateDown( PQItem* q, int l, int p );
void UpdateUp( PQItem* q,  int l, int p );


PQueue* PQInit( int nSize ) {
	if( nSize <= 0 ) return NULL;
	PQueue* q = ( PQueue* )calloc( 1,  sizeof( PQueue ) );
	if( !q ) return NULL;

	q->pPQueue = ( PQItem* )calloc( nSize, sizeof( PQItem ) );
	if( !q->pPQueue ) return NULL;
	q->nPQSize = nSize;
	return q;
}

int PQEnqueue( PQueue* q, int prior, PQINFO* item ) {
	if( !q || PQSize(q) == q->nPQSize ) return 0;
	int x = PQSize(q);
	q->pPQueue[x].nPrior = prior;
	q->pPQueue[x].pInfo = item;

	if( !PQisEmpty(q) ) {
		UpdateUp(q->pPQueue, 0, x);
	}
	++q->nPQCurrSize;
	return 1;
}

PQINFO* PQDequeue( PQueue* q ) {
	if( !q || PQisEmpty( q ) ) return NULL;

	PQINFO* temp = q->pPQueue[0].pInfo;
	int x = --q->nPQCurrSize;
	if( x ) q->pPQueue[0] = q->pPQueue[x];
	q->pPQueue[x].nPrior = 0;
	q->pPQueue[x].pInfo = NULL;
	if( x > 1 ) UpdateDown(q->pPQueue, 0, x - 1);
	return temp;
}

void PQClear( PQueue* q, void( __cdecl* fun )( const void*  ) ) {
	if( !q || !fun ) {
		printf( "Nullptr(PQClear)." );
		return;
	}
	while( !PQisEmpty( q ) ) fun( PQDequeue( q ) );
}

void PQRelease( PQueue** q, void( __cdecl* fun )( const void* ) ) {
	if( !q ) {
		printf( "Nullptr(PQRelease)." );
		return;
	}
	PQClear( *q, fun );
	free( ( *q )->pPQueue );
	free( *q );
	*q = NULL;
}

int PQgetPrior( PQueue* q, int idx ) {
	if( !q || PQisEmpty(q) ) return PRIOR_ERROR;
	if( idx < 0 || idx >= PQSize(q) ) return POS_ERROR;
	return q->pPQueue[idx].nPrior;
}

int PQGetPrior( PQueue* q, PQINFO* item, int( __cdecl* comp )( const void*, const void* ) ){
	return PQgetPrior( q, PQFind( q, item, comp ) );
}

int PQSetPrior( PQueue* q, PQINFO* item, int prior, int( __cdecl* comp )( const void*, const void* ) ) {
	return PQsetPrior(q, PQFind( q, item, comp ), prior );
}

int PQsetPrior( PQueue* q, int pos, int nNewPrior ) {
	int prior = PQgetPrior(q, pos);
	if( prior != PRIOR_ERROR && prior != POS_ERROR ) {
		q->pPQueue[pos].nPrior = nNewPrior;

		if( prior < nNewPrior )
			UpdateUp( q->pPQueue, 0, pos );
		else
			UpdateDown( q->pPQueue, pos, PQSize(q) );
	}
	return prior;
}

int PQFind( PQueue* q, PQINFO* prior, int( __cdecl* comp )( const void*, const void* ) ) {
	if( !q ) return PRIOR_ERROR;
	if( !comp ) return POS_ERROR;
	for( int i = 0; i < PQSize(q); ++i ) if( !comp(q->pPQueue[i].pInfo, prior) ) return i;
	return POS_ERROR;
}

int PGMaxPrior( PQueue* q ) {
	return ( !q || PQisEmpty(q) ) ? PRIOR_ERROR : q->pPQueue[0].nPrior;
}

int PQisEmpty( PQueue* q ) {
	return !( q && q->nPQCurrSize );
}

int PQSize( PQueue* q ) {
	return ( q ) ? q->nPQCurrSize : PRIOR_ERROR;
}

void PQPrint( PQueue* q, int idx, void fun( const void* ) ) {
	if( !q || PQisEmpty(q) || idx < 0 ) {
		printf( "Nullptr, index < 0 or queue is empty(PQPrint)." );
		return;
	}
	if( idx >= PQSize(q) ) return;
	if( fun ) fun(q->pPQueue[idx].pInfo);
	printf("prior: %d \n", q->pPQueue[idx].nPrior);
	PQPrint(q, 2 * idx + 1, fun);
	PQPrint( q, 2 * idx + 2, fun );
}

void UpdateUp(PQItem* q,int l, int p )
{
	if( p >= l ) return;

	int x = ( p + 1 ) / 2 -1;
	PQItem t = q[x];
	while( x > l && t.nPrior < q[p].nPrior ) {
		q[p] = q[x];
		p = x;
		x = ( p + 1 ) / 2 - 1;
	}
	q[x] = t;
}

void UpdateDown( PQItem* q, int l, int p )
{
	if( l >= p ) return;

	int i = l;
	int j = 2 * i + 1;
	int x = q[i].nPrior;
	PQItem t = q[i];
	while( j <= p )
	{
		if( j < p && q[j].nPrior < q[j + 1].nPrior ) j++;
		if( x > q[j].nPrior ) break;
		q[i] = q[j];
		i = j;
		j = 2 * i + 1;
	}
	q[i] = t;
}