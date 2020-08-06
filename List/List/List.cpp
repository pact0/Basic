#include "List.h"

void PrintList(ListItem* p);


int main()
{
	ListItem* List = CreateList();
	if( List == NULL ) return 0;

	for( int i = 0; i < 10; ++i ) {
		LISTINFO* tmp = ( LISTINFO* )malloc( sizeof(LISTINFO) );
		tmp->nKey = i; //random
		InsertFront(List, tmp); 
	}

	for( int i = 20; i > 10; i-- )
	{
		LISTINFO* f = (LISTINFO*)malloc(sizeof(LISTINFO));
		f->nKey = i;
		InsertFront(List, f); // robię drugi raz pętle for żeby sprawdzić czy na pewno sortuje po liczbach nie po adresach pamięci
	}
#ifdef DEBUG
	PrintList(List); 
	printf("\n\n");
#endif
	SortList(List, compare); // sortowanie listy
#ifdef DEBUG
	PrintList(List); 
	printf("\n\n");
#endif
	printf("%d ", List->pNext->pInfo->nKey); // sprawdzam czy dobrze zrozumiałem temat
	ListItem* prev = NULL;
	LISTINFO* x = (LISTINFO*)malloc(sizeof(LISTINFO)); // alokujemy pamięć dla wartości do wyszukania
	x->nKey = 2000; // przypisujemy wartość którą chcemy wyszukać
	
	printf("\n\n");
	ListItem* look = Find(List, x, &prev, compare);

	printf("%d\n", look->pInfo->nKey);
	printf("%d\n", prev->pInfo->nKey);

	LISTINFO* ins = (LISTINFO*)malloc(sizeof(LISTINFO));
	ins->nKey = 3000;
	Insert(List->pNext->pNext->pNext, ins); // w tym przypadku wstawiamy element za trzeci element listy

#ifdef DEBUG
	printf("\n\n");
	PrintList(List);
	printf("\n\n");
#endif

	Remove(List->pNext->pNext->pNext);
#ifdef DEBUG
	PrintList(List);
#endif
	DelList(&List);
	return 0;
}

void PrintList(ListItem* p)
{
	ListItem* iterator = p;
	while( iterator->pNext )
	{
		printf("%d ", iterator->pNext->pInfo->nKey);
		iterator = iterator->pNext;
	}
}

int compare(const void* p, const void* v)
{
	if( ( (LISTINFO*)p )->nKey > ( (LISTINFO*)v )->nKey ) // p i v jest typu void więc musimy zrobić rzutowanie
		return 1;
	if( ( (LISTINFO*)p )->nKey < ( (LISTINFO*)v )->nKey )
		return -1;
	return 0;
}