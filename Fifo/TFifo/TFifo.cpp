#include "FQueue.h"
//#define DEBUG
void PrintList(QFIFO* q);

int main()
{

	QFIFO* List = QFCreate(5);

#ifdef DEBUG
	PrintList(List);
	printf("\n\n");
#endif
	
	QFITEM p;
	QFITEM p2;
	QFITEM p3;
	
	p.pTab = (int*)malloc(2 * sizeof(int));
	p.pTab[0] = 1;
	p.pTab[1] = 1*2;
	p.n_Key = 1;

	p2.pTab = (int*)malloc( 2 * sizeof(int));
	p2.pTab[0] = 2;
	p2.pTab[1] = 2 * 2;
	p2.n_Key = 2;

	p3.pTab = (int*)malloc( 2 * sizeof(int));
	p3.pTab[0] = 3;
	p3.pTab[1] = 3 * 2;
	p3.n_Key = 3;

	QFEnqueue(List, &p);
	QFEnqueue(List, &p2);
	QFEnqueue(List, &p3);

#ifdef DEBUG
	printf("Complete list:\n");
	PrintList(List);
	printf("\n\n");
#endif

	QFDequeue(List);
#ifdef DEBUG
	printf("Dequeued list(1):\n");
	PrintList(List);
	printf("\n\n");
#endif
	QFDequeue(List);

#ifdef DEBUG
	printf("Dequeued list(2):\n");
	PrintList(List);
	printf("\n\n");
#endif

	QFClear(List, freeInfo);

#ifdef DEBUG
	printf("Cleared list:\n");
	PrintList(List);
	printf("\n\n");
#endif

	QFRemove(&List, freeInfo);

#ifdef DEBUG
	printf("Cleared list:\n");
	PrintList(List);
	printf("\n\n");
#endif
	return 0;
}

void freeInfo(const void* p)
{
	if( p == NULL ) return;
	QFIFO* q = (QFIFO*)p;
	if( q == NULL ) return;
	for( int i = 0; i < q->nMaxElem; i++ )
	{
		if(q->pFQItems[i] == NULL) return;
		free(q->pFQItems[i]->pTab);
	}
}

void PrintList(QFIFO* q)
{
	if( q == NULL ) return;
	if( q->pFQItems == NULL ) return;
	for( int i = 0; i <= q->nNoElem; i++ )
	{
		if(   q->pFQItems[q->nHead + i] == NULL ) return;
		printf("n_key = %d  tab[0] = %d  tab[1] = %d\n", q->pFQItems[q->nHead+i]->n_Key, q->pFQItems[q->nHead + i]->pTab[0], q->pFQItems[q->nHead + i]->pTab[1]);
	}
}