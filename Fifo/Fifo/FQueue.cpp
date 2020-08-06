#include "FQueue.h"
void  QFDel( QFIFO* q );
                                
QFIFO* QFCreate()
{
	return ( QFIFO* )calloc( 1, sizeof( QFIFO ) );
}

int QFEmpty( QFIFO* q )
{
	return !( q && q->pHead );
}

int QFEnqueue( QFIFO* q, QInfo* pItem )
{
	if( !q ) return NULL;
	QFItem* node = ( QFItem* )calloc( 1,sizeof( QFItem ) );
	if( !node ) return 0;

	node->value = pItem;
	if( !QFEmpty(q) )
		q->pTail->next = node;
	else
		q->pHead = node;
	q->pTail = node;
	return 1;
}

QInfo* QFDequeue( QFIFO* q )
{
	if( !q || QFEmpty(q) ) return NULL;
	QInfo* temp = q->pHead->value;
	QFDel(q);
	return  temp;
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
	if( !q || !(*q) ) {
		printf( "Error: nullptr.(QFRemove)" );
		return;
	}
	QFClear( *q );
	free( *q );
	*q = NULL;
}

void  QFDel( QFIFO* q )
{
	if( !q || QFEmpty(q) ) {
		printf( "Error: nullptr or empty queue.(QFDel)" );
		return;
	}
	QFItem* temp = q->pHead;
	q->pHead = temp->next;
	if( QFEmpty(q) ) q->pTail = NULL;
	free( temp );
}