#ifndef SHIP_1
#define SHIP_1

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

typedef enum{UP = 1, RIGHT, DOWN, LEFT}Directions;

int Move(int** pDepthTab, int nRow, int nCol, int nDepth,int nextMove, int x, int y, int* px, int* py, int** pRoot);//makes moves
int Root(int** pDepthTab, int nRow, int nCol, int nDepth,int x, int y, int** pRoot, int x_dest, int y_dest);		//recursiveley finds route
int ReadDepthTab(const char* sFile, int** pTab, int nRow, int nCol);			//reads depth from file and fills tab with them
int** CreateTab(int nRow, int nCol);											//creates tab and return pointer to it
void PrintTab(int** pRoot, int nRow, int nCol);
void FreeTab(int*** pTab);
#endif