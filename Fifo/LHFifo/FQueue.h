#ifndef FQUEUE_H
#define FQUEUE_H

#include "global.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct QFItem {
	QInfo* value;
	QFItem* next;
}QFItem;
typedef struct QFIFO {
	QFItem* pHead;
	QFItem* pTail;
} QFIFO;
                                
QFIFO* QFCreate();								//creats queue
int QFEmpty( QFIFO* q );						//checks whether the queue is empty
int QFEnqueue( QFIFO* q, QInfo* pItem );		//adds an item to queue
QInfo* QFDequeue( QFIFO* q );					//removes an item from queue
void  QFClear( QFIFO* q );						//clears all elements - the queue is still usable
void  QFRemove( QFIFO** q );					//removes all emenets and frees from memory
#endif										