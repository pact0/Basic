#pragma once

#include "global.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>



typedef int( __cdecl* pointer_to_compare )( const void*, const void* ); //wskaźnik na funkcje typu int przyjmujący dwa wskaźniki stałe const void
typedef void(__cdecl* release_memory)( const void* );
typedef struct tagListItem
{
	LISTINFO* pInfo; // int nKey;
	tagListItem* pNext;
} ListItem;


ListItem* CreateList(); // funkcja tworząca liste
ListItem* Front(ListItem* p); // funckja zwraca pierwszy element listy
ListItem* Find(ListItem* p, const void* value, ListItem** previous, pointer_to_compare compare); // funkcja znajduje element oraz zwraca wskaźnik na element który go poprzedza
void RemoveFront(ListItem* p); // funkcja usuwa pierwszy element
void Remove(ListItem* pAfter); // funkcja usuwa element po wybranym
void Insert(ListItem* pAfter, LISTINFO* pInfo); // funkcja wstawia element po wybranym
void FreeList(ListItem* p); // funkcja czyści liste ( po za głową )
void DelList(ListItem** p); // funckja czyści liste wraz z głową
void InsertFront(ListItem* p, LISTINFO* pInfo); // funkcja wstawia element na początek listy
void SortList(ListItem* p, pointer_to_compare compare); // funkcja sortująca listy
int compare(const void* p, const void* v); // funkcja porównuje dwie wartości
int isEmpty(ListItem* p); // funckja sprawdza czy lista jest pusta
void ClearList(ListItem* p, const void* v);
void RemoveList(ListItem* p, const void* v);