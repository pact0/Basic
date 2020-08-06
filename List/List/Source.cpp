#include "List.h"


#include "List.h"

#include <memory.h>
#include <stdlib.h>

ListItem* CreateList()
{
	ListItem* p = ( ListItem* )malloc( sizeof( ListItem ) );
	if( !p ) return NULL;
	memset( p, 0, sizeof( ListItem ) );
	return p;
}

int isEmpty( ListItem* p )
{
	return !( p->pNext );
}

ListItem* Front( ListItem* p )
{
	if( isEmpty(p) ) printf( "The list is empty(Front)." );
	return p->pNext;
}

void RemoveFront( ListItem* p )
{
	Remove( p );
}

void Remove( ListItem* pAfter )
{
	if( pAfter->pNext ) {
		ListItem* temp = pAfter->pNext;  // tworzymy wskaźnik pomocniczy do którego przypisujemy wskaźnik na element który chcemy usunąć
		pAfter->pNext = temp->pNext; // przeczepiamy "obok" danego elementu wskaźniki żeby móc go spokojnie usunąć
		free(temp->pInfo); // usuwanie informacjii
		free(temp);  // usuwamy element
	}
}

void Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	ListItem* temp = ( ListItem* )malloc( sizeof( ListItem ) );
	if( !temp ) {
		printf("Nullptr(Insert).");
		return;
	}
	memset( temp, 0, sizeof( ListItem ) );
	temp->pInfo = pInfo; // przypsuje wskaźnik do wartości do nowego elementu
	temp->pNext = pAfter->pNext; // ustawiam wskaźnik na element za pAfter
	pAfter->pNext = temp; // przepinam wskaźnik pAfter na nasz nowy element
}

void InsertFront( ListItem* p, LISTINFO* pInfo )
{
	Insert(p, pInfo);
}

void FreeList(ListItem* p)
{
	while( !isEmpty(p) )
		RemoveFront(p);
}

void DelList(ListItem** p)
{
	FreeList(*p);
	free(*p);
	*p = NULL;
}


ListItem* Find(ListItem* p, const void* value, ListItem** previous, pointer_to_compare compare)
{
	ListItem* helper = p->pNext; // ustawiamy wskaźnik na pierwszym elemencie do rozpatrzenia bo p wskazuje na wartownika
	*previous = p; // previous jest wy/we więc może być sytuacja że szukany element będzie pierwszy
	while( helper ) // nie możemy helper->pNext bo pominiemy ostatni element
	{
		if( compare((const void*)helper->pInfo, value) == 0 ) // podaje wskaźniki bo do wartości odwołuje się w compare!!!
			return helper; // jeśli helper wskazuje na element listy który zawiera strukture w której jest nasza szukana wartość to go zwracamy
		*previous = helper; // wskaźnikiem previous przechodzimy dalej w razie gdy nie znajdziemy naszego elementu
		helper = helper->pNext; // przechodzimy do kolejnego elementu listy
	}
	return *previous = NULL; // jeśli nie znajdziemy naszej wartości to zwracamy previous który wskazuje na NULLA;
}

void SortList( ListItem* p, pointer_to_compare compare )
{
	ListItem* pFirst = p;
	while( pFirst->pNext )
	{
		ListItem* pMin = pFirst;
		ListItem* pCurr = pMin->pNext;
		while( pCurr->pNext )
		{
			if( compare((const void*)( pMin->pNext->pInfo ), (const void*)( pCurr->pNext->pInfo )) == 1 ) // porównujemy kolejne elementy
				pMin = pCurr; // pMin wskazuje na element o jeden wcześniej niż minimalny
			pCurr = pCurr->pNext;	// przechodzimy dalej w liście
		}
		if( pFirst != pMin )
		{
			pCurr = pMin->pNext->pNext; // podczepiam końcówkę
			pMin->pNext->pNext = pFirst->pNext; // podpinam pNext mojego najmniejszego elementu przed najmniejszy element ( na początku przed wartownika ) do kolejnego elementu który będzie przed nim
			pFirst->pNext = pMin->pNext; // następnie podpinam wskaźnik pNext od najmniejszego elementu ( na początku od wartownika ) do znalezionego minimum
			pMin->pNext = pCurr; // podpinam wskaźnik który wskazywał na znalezione minimum do reszty listy ( tej którą łapałem wskaźnikiem na samym początku )
		}
		pFirst = pFirst->pNext; // przechodze dalej i szukam kolejnego minimum
	}
}