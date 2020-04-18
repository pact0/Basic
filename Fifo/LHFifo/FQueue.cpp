#include "FQueue.h"

// funkcja prywatna modulu  - tylko usuniecie elemenu z listy (nie info)
void  QFDel(QFIFO* q);

// kreowanie dynamiczne kolejki                                  
QFIFO* QFCreate()
{
	QFIFO* list;
	list = (QFIFO*)calloc(1, sizeof(QFIFO));
	if( list == NULL ) return NULL;

	list->pTail = NULL;
	list->pHead = NULL;

	return list;
}

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty(QFIFO* q)
{
	return !( q->pHead );
}

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gduy blad alokacji
int QFEnqueue(QFIFO* q, QFItem* pItem)
{
	QItem* node = (QItem*)calloc(1, sizeof(QItem));
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

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QFItem* QFDequeue(QFIFO* q)  // ma wywolac QFDel()
{
	if( q == NULL ) return NULL;
	if( QFEmpty(q) ) return NULL;
	QFDel(q);
	return ( q->pHead->value );
}

// czyszczenie kolejki, kolejke mozna uzywac dalej
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


// funkcja prywatna modulu  - tylko usuniecie elemenu z listy (nie info)
void  QFDel(QFIFO* q)
{
	if( QFEmpty(q) )
		return;
	QItem* temp;

	temp = q->pHead;
	if( !( q->pHead->next ) )
		q->pTail = NULL;
	q->pHead = q->pHead->next;
	free(temp);
}