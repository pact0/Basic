#ifndef GLOBAL_H
#define GLOBAL_G
void freeInfo( const void* );

typedef struct
{
	int n_Key; // klucz (informacja)
	int* pTab; // ma byc tablica 2 elementowa - mozna do pTab[0] wstawiac to samo co klucz
} QInfo;

#define QFITEM QInfo
#endif