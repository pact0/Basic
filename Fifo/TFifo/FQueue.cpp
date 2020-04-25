#include "FQueue.h"

void QFDel(QFIFO* q);

QFIFO* QFCreate(int nSize)
{
	QFIFO* q = (QFIFO*)calloc( 1,sizeof(QFIFO) );
	if( q == NULL ) return NULL;

	q->pFQItems = (QFITEM**)calloc(nSize, sizeof(QFITEM*));
	if( q->pFQItems == NULL ) return NULL;
	
	q->nMaxElem = nSize;
	q->nNoElem	= 0;
	q->nHead = 0;
	q->nTail = 0;
	return q;
}

int QFEmpty(QFIFO* q)
{
	return !( q->nNoElem );
}

int QFEnqueue(QFIFO* q, QFITEM* pItem)
{
	if( q->nNoElem == q->nMaxElem )
	{
		printf("Can't add another item.");
		return 0;
	}

	q->pFQItems[q->nTail] = pItem;
	q->nNoElem++;
	q->nTail++;
	if( q->nTail == q->nMaxElem+1 )	q->nTail = 0;

	return 1;
}

QFITEM* QFDequeue(QFIFO* q)
{
	if( QFEmpty(q) ) 
	{
		perror("Queue is empty. Can't remove anything.");
		return NULL;
	}
	QFITEM* temp = q->pFQItems[q->nHead];
	QFDel(q);
	return ( temp );
}

void QFDel(QFIFO* q)
{
	q->pFQItems[q->nHead] = NULL;
	q->nNoElem--;
	q->nHead++;
	if( q->nHead == q->nMaxElem ) q->nHead = 0;
}

void QFClear(QFIFO* q, void fun(const void*))
{
	free(q->pFQItems);
	q->nNoElem = 0;
	memset( q, 0, sizeof( QFIFO) );
}

void QFRemove(QFIFO** q, void fun(const void* ))
{
	QFClear( *q, fun );
	free( *q );
	*q = NULL;
}

