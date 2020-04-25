#include "FQueue.h"
void  QFDel(QFIFO* q);
                                
QFIFO* QFCreate()
{
	QFIFO* list;
	list = (QFIFO*)calloc(1,sizeof(QFIFO));
	if( list == NULL ) return NULL;

	list->pTail = NULL;
	list->pHead = NULL;
	return list;
}

int QFEmpty(QFIFO* q)
{
	return !(q->pHead);
}

int QFEnqueue(QFIFO* q, QFItem* pItem)
{
	QItem* node = (QItem*)calloc(1,sizeof(QItem));
	if( node == NULL ) return 0;

	node->value = pItem;
	if( !QFEmpty(q) )
		q->pTail->next = node;
	else
		q->pHead = node;
	node->next = NULL;
	q->pTail = node;
	return 1;
}

QFItem* QFDequeue(QFIFO* q)
{
	if( q == NULL ) return NULL;
	if( QFEmpty(q) ) return NULL;
	QFItem* temp = q->pHead->value;
	QFDel(q);
	return ( temp );
}

void  QFClear(QFIFO* q)
{
	if( q == NULL ) return;

	while( q->pHead != NULL )
		QFDel(q);
}

void  QFRemove(QFIFO** q)
{
	QFClear(*q);
	free(( *q ));
	*q = NULL;
}

void  QFDel(QFIFO* q)
{
	if( QFEmpty(q) )
		return;
	QItem* temp;
	temp = q->pHead;
	if( !( q->pHead->next ) ) q->pTail = NULL;
	
	q->pHead = q->pHead->next;	
	free(temp);
}