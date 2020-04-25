#include "FQueue.h"
void  QFDel(QFIFO* q);
                            
QFIFO* QFCreate()
{
	QFIFO* list;
	list = (QFIFO*)calloc(1, sizeof(QFIFO));
	if( list == NULL ) return NULL;

	QItem* node = (QItem*)calloc(1, sizeof(QItem));
	if( node == NULL ) return NULL;
	list->pHead = node;
	list->pHead->next = NULL;
	list->pTail = node;
	return list;
}

int QFEmpty(QFIFO* q)//returns 1 if empty
{
	return !( q->pHead->next );
}

int QFEnqueue(QFIFO* q, QFItem* pItem)
{
	QItem* node = (QItem*)calloc(1, sizeof(QItem));
	if( node == NULL ) return 0;
	
	node->value= pItem;
	node->next = NULL;
	if( !QFEmpty(q) )
		q->pTail->next = node;
	else
		q->pHead->next = node;
	q->pTail = node;
	return 1;
}

QFItem* QFDequeue(QFIFO* q)  // ma wywolac QFDel()
{
	if( q == NULL ) return NULL;
		
	if( QFEmpty(q) ) return NULL;
	QFItem* temp = q->pHead->next->value;
	QFDel(q);
	return ( temp );
}

void  QFClear(QFIFO* q)
{
	if( q == NULL ) return;

	while( !QFEmpty(q) )
		QFDel(q);
}

void  QFRemove(QFIFO** q)
{
	QFClear(*q);
	free(( *q )->pHead);
	free(( *q ));
	*q = NULL;
}

void  QFDel(QFIFO* q)
{
	QItem* temp;
	temp = q->pHead->next;
	q->pHead->next = temp->next;
	free(temp);
}