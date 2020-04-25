#ifndef FQUEUE_H
#define FQUEUE_H
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct {
	int nHead;								//idx of the first element ine queue
	int nTail;								//idx of the first free space 
	int nNoElem;							//current number of elements in queue
	int nMaxElem;							//size of array
	QFITEM** pFQItems;						//array of pointers to info
}QFIFO;
                            
QFIFO* QFCreate(int nSize);							//creates dynamic array of nSize
int QFEmpty(QFIFO* q);								//returns 1 when empty
int QFEnqueue(QFIFO* q, QFITEM* pItem);				//insert an item to queue
QFITEM* QFDequeue(QFIFO* q);						//remove an item from queue
void QFClear(QFIFO* q, void fun(const void*));		//clears the queue
void QFRemove(QFIFO** q, void fun(const void*));	//deletes the queue
#endif