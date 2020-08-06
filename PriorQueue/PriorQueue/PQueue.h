#pragma once

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "global.h"
#include <float.h>

#define POS_ERROR INT_MIN
#define PRIOR_ERROR -1


typedef struct
{
	PQINFO* pInfo;
	int nPrior;	
} PQItem;		


typedef struct
{
	PQItem* pPQueue;
	int nPQSize;
	int nPQCurrSize;
} PQueue;

PQueue* PQInit( int nSize );
PQINFO* PQDequeue(PQueue* q);
int PQisEmpty( PQueue* q );
int PQSize( PQueue* q );
int PGMaxPrior( PQueue* q );
int PQgetPrior( PQueue* q, int index );
int PQsetPrior( PQueue*, int pos, int nNewPrior );
int PQEnqueue( PQueue* q, int prior, PQINFO* item );
int PQFind(PQueue* q, PQINFO* prior, int( __cdecl* comp )( const void*, const void* ) );
int PQGetPrior( PQueue* q, PQINFO* item, int( __cdecl* comp )( const void*, const void* ) );
int PQSetPrior( PQueue* q, PQINFO* item, int prior, int( __cdecl* comp )( const void*, const void* ) );
void PQPrint( PQueue* q, int idx, void fun ( const void* item ) );
void PQClear( PQueue* q, void( __cdecl* fun )( const void*) );
void PQRelease( PQueue** q, void( __cdecl* delItem )( const void* ) );