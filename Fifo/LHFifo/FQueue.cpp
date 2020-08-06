#include "FQueue.h"

void  QFDel( QFIFO* q );
                            
QFIFO* QFCreate()
{
	QFIFO* list = ( QFIFO* )calloc( 1, sizeof(QFIFO) );
	if( !list ) return NULL;

	QFItem* node = ( QFItem* )calloc( 1, sizeof(QFItem) );
	if( !node ) return NULL;
	list->pHead = list->pTail = node;
	return list;
}

int QFEmpty(QFIFO* q)
{
	return !( q && q->pHead->next );
}

int QFEnqueue( QFIFO* q, QInfo* pItem )
{
	if( !q ) return NULL;
	QFItem* node = ( QFItem* )calloc( 1, sizeof( QFItem ) );
	if( !node ) return NULL;
	
	node->value = pItem;
	q->pTail->next = node;
	q->pTail = node;
	return 1;
}

QInfo* QFDequeue( QFIFO* q )
{
	if( !q || QFEmpty(q) ) return NULL;
	QInfo* temp = q->pHead->value;
	QFDel(q);
	return ( temp );
}

void  QFClear( QFIFO* q )
{
	if( !q ) {
		printf( "Error: nullptr.(QFClear)" );
		return;
	}
	while( !QFEmpty(q) ) free( QFDequeue(q) );
}

void  QFRemove( QFIFO** q )
{
	if( !q || !( *q ) ) {
		printf( "Error: nullptr.(QFRemove)" );
		return;
	}
	QFClear( *q );
	free( (*q)->pHead );
	free( *q );
	*q = NULL;
}

void  QFDel( QFIFO* q )
{
	if( !q || QFEmpty(q) ) {
		printf( "Error: nullptr or empty queue.(QFDel)" );
		return;
	}
	QFItem* temp = q->pHead->next;
	q->pHead->next = temp->next;
	if( QFEmpty(q) ) q->pTail = q->pHead;
	free(temp);
}