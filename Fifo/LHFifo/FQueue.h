#ifndef FQUEUE_H
#define FQUEUE_H

#include "global.h"
#include <stdlib.h>

typedef struct QItem {
	QFItem* value;
	QItem* next;
}QItem;
typedef struct QFIFO {
	QItem* pHead;
	QItem* pTail;
} QFIFO;
                                
QFIFO* QFCreate();							//creats queue
int QFEmpty(QFIFO* q);						//checks whether the queue is empty
int QFEnqueue(QFIFO* q, QFItem* pItem);		//adds an item to queue
QFItem* QFDequeue(QFIFO* q);				//removes an item from queue
void  QFClear(QFIFO* q);					//clears all elements - the queue is still usable
void  QFRemove(QFIFO** q);					//removes all emenets and frees from memory
#endif										