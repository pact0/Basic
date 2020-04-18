#ifndef FQUEUE_H
#define FQUEUE_H

#include "global.h"
#include <iostream>

typedef struct QItem {
	QFItem* value;
	QItem* next;
}QItem;

typedef struct QFIFO {
	QItem* pHead;
	QItem* pTail;
} QFIFO;




// kreowanie dynamiczne kolejki                                  
QFIFO* QFCreate();

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty(QFIFO* q);

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gduy blad alokacji
int QFEnqueue(QFIFO* q, QFItem* pItem);

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QFItem* QFDequeue(QFIFO* q);  // ma wywolac QFDel() 

// czyszczenie kolejki, kolejke mozna uzywac dalej
void  QFClear(QFIFO* q);

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void  QFRemove(QFIFO** q);
#endif
