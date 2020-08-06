#include "FQueue.h"

void QFDel( QFIFO* q );

QFIFO* QFCreate( int nSize )
{
	if( nSize <= 0 ) {
		printf( "Size needs to be greater than 0" );
		return NULL;
	}
	QFIFO* q = (QFIFO*)calloc(1, sizeof(QFIFO));
	if( !q ) {
		printf( "Nullptr(QFCreate)" );
		return NULL;
	}
	q->pFQItems = ( QFITEM** )calloc( nSize, sizeof(QFITEM*) );
	if( !( q->pFQItems ) ) {
		printf( "Nullptr(QFCreate)" );
		return NULL;
	}
	q->nMaxElem = nSize;
	return q;
}

int QFEmpty(QFIFO* q)
{
	return !( q && q->nNoElem );
}

int QFEnqueue( QFIFO* q, QFITEM* pItem )
{
	if( !q ) {
		printf( "Nullptr.(QFEnqueue)" );
		return 0;
	}
	if( q->nNoElem == q->nMaxElem )
	{
		printf( "Can't add another item." );
		return 0;
	}

	q->pFQItems[q->nTail] = pItem;
	q->nNoElem++;
	q->nTail = ( q->nTail + 1 ) % q->nMaxElem;
	return 1;
}

QFITEM* QFDequeue( QFIFO* q )
{
	if( !q ) {
		printf( "Nullptr(QFDequeue)" );
		return NULL;
	}
	if( QFEmpty(q) )
	{
		printf( "Queue is empty. Can't remove anything." );
		return NULL;
	}
	QFITEM* temp = q->pFQItems[q->nHead];
	QFDel(q);
	return temp;
}

void QFDel( QFIFO* q )
{
	if( !q || QFEmpty(q) ) {
		printf( "Error: nullptr or queue is empty.(QFDel)" );
		return;
	}
	q->pFQItems[q->nHead] = NULL;
	q->nNoElem--;
	q->nHead = ( q->nHead + 1 ) % q->nMaxElem;
}

void QFClear( QFIFO* q, void(_cdecl* fun)( const void* ) )
{
	if( !q ) {
		printf( "Error: nullptr.(QFClear)" );
		return;
	}
	while( !QFEmpty(q) ) fun(QFDequeue(q));
	q->nHead = 0;
	q->nTail = 0;
}

void QFRemove( QFIFO** q, void(_cdecl* fun)( const void* ) )
{
	if( !q || !( *q ) ) {
		printf( "Error: nullptr.(QFRemove)" );
		return;
	}
	QFClear(*q, fun);
	free( ( *q )->pFQItems );
	free(*q);
	*q = NULL;
}

