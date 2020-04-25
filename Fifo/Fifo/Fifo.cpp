#include <iostream>
#include "FQueue.h"
void PrintList(QFIFO* q);
#define DEBUG

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

	QFClear(List);

#ifdef DEBUG
	PrintList(List);
	printf("\n\n\n");
#endif

	QFItem* a = QFDequeue(List);

#ifdef DEBUG
	printf("a = %d\n\n\n", a);
	PrintList(List);
	printf("\n\n\n");
#endif

	free(a);
	QFEnqueue(List, &test4);
	QFEnqueue(List, &test4);
	QFEnqueue(List, &test4);
	QFRemove(&List);

#ifdef DEBUG
	PrintList(List);
	printf("\n\n\n");
#endif
	return 0;
}

void PrintList(QFIFO* q)
{
	QItem* temp = q->pHead;
	if( temp == NULL ) return;
	while( temp->next )
	{
		printf("%d  ", ( temp->value->n_Key ));
		temp = temp->next;
	}
	printf("%d  ", ( temp->value->n_Key ));
}