#ifndef SHIP_1
#define SHIP_1

int Move(int** pDepthTab, int nRow, int nCol, int nDepth,
	int nextMove, int x, int y, int* px, int* py, int** pRoot);

/* pDepthTab - tablica okreslajaca glebokosc w kazdym polu prostokatnego obszaru
   nRow, nCol - rozmiary pTab,
   nDepth - glebokosc zanurzenia statku
   nextMove - kierunek ruchu
   x, y - indeksy w tablicy skad wykonujemy kolejny ruch np. zaczynamy od 0,0
   px, py - parametry WYJSCIWE - nowe wspolrzedne
   pRoot - tablica pamietajaca ruchy o rozm nRow, nCol
*/

int Root(int** pDepthTab, int nRow, int nCol, int nDepth,
	int x, int y, int** pRoot, int x_dest, int y_dest);
/* pDepthTab tablica glebokosci morza o romiarze nRow  i nCol
	dDepth - glebokosc zanurzenia ststku
	x, y - wspol skad robimy kolejny ruch
	pRoot tablica kolejnych ruchow
	x_dest, y_dest - wsporzedne portu
*/

void ReadDepthTab(char* sFile, int** pTab, int nRow, int nCol);
// wczytuje dane z pliku
// sFile -  nazwa pliku wejsciowego - parametr main()
// pTab  - tablica glebokosci morza
// nRow, nCol wymiary tej tablicy

int** CreateTab(int nRow, int nCol);
// funkcja kreuje tablice dynamicznie dwuwymiarowa o nRow wierszach i nCol kolumnach
// zgodnie z DRUGA (materialy) metoda kreowania tablic dwuwymiarowych
// i zwraca wskaznik na ta tablice (ma byc wyzerowana oczywiscie)

void PrintTab(int** pRoot, int nRow, int nCol);
// drukuje tablice dwuwymiarowa  o nRow wierszach i nCol kolumnach

void FreeTab(int*** pTab); // nie potrebne rozmiary
#endif
