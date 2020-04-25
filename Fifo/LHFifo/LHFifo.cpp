#include <iostream>
#include "FQueue.h"
//#define DEBUG
void PrintList(QFIFO* q);
int main()
{
	QFIFO* List = QFCreate();
	QFItem test;
	QFItem test2;
	QFItem test3;
	QFItem test4;
	test.n_Key = 1;
	test2.n_Key = 2;
	test3.n_Key = 3;
	test4.n_Key = 4;
	QFEnqueue(List, &test);
	QFEnqueue(List, &test2);
	QFEnqueue(List, &test3);
	QFEnqueue(List, &test4);

#ifdef DEBUG
	PrintList(List);
	printf("\n\n\n");
#endif

	QFItem* a = QFDequeue(List);
	QFItem* b = QFDequeue(List);
	
#ifdef DEBUG
	printf("a = %d\n", *a);
	printf("b = %d\n\n\n", *b);
	PrintList(List);
	printf("\n\n\n");
#endif

	QFRemove(&List);

#ifdef DEBUG
	PrintList(List);
	printf("\n\n\n");
#endif
	return 0;
}

void PrintList(QFIFO* q)
{
	if( q == NULL ) return;
	if( QFEmpty(q) ) return;
	QItem* tmp = q->pHead->next;
	while( tmp != NULL )
	{
		printf("%d ", tmp->value->n_Key);
		tmp = tmp->next;
	}
}