#include <iostream>
#include "FQueue.h"

void PrintList(QFIFO* q);
int main()
{
	QFIFO* List = QFCreate();
	QFItem test;
	QFItem test2;
	QFItem test3;
	QFItem test4;
	test.n_Key = 1;
	QFEnqueue(List, &test);
	//PrintList(List);
	test2.n_Key = 2;
	QFEnqueue(List, &test2);	
	//PrintList(List);
	test3.n_Key = 3;
	QFEnqueue(List, &test3);
	//PrintList(List);
	test4.n_Key = 4;
	QFEnqueue(List, &test4);
	//PrintList(List);
	//printf ( "\n\n\n");
	//PrintList(List);


	QFClear(List);
	//PrintList(List);
	QFItem *a = QFDequeue(List);
	//printf("%d", a);
	QFEnqueue(List, &test4);
	QFEnqueue(List, &test4);
	QFEnqueue(List, &test4);

	QFRemove(&List);
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