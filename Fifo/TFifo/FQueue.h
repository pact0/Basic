#ifndef FQUEUE_H
#define FQUEUE_H
#include "global.h"

typedef struct QFIFO {

}QFIFO;
// kreowanie dynamiczne kolejki (struktury i tablicy)                                
QFIFO* QFCreate(int nSize);  // nSize  - rozmiar tablicy

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int     QFEmpty(QFIFO* q);

// wstawienie elementu do kolejki
int     QFEnqueue(QFIFO* q, QFITEM* pItem);

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu
QFITEM* QFDequeue(QFIFO* q);

// czyszczenie kolejki, kolejke mozna uzywac
void    QFClear(QFIFO* q, /*<wsk do funkcji typu void z parametrem const void*>*/);

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie wskaznika
void    QFRemove(QFIFO** q, /*<wsk do funkcji typu void z parametrem const void*>*/);
#endif // !FQUEUE_H
