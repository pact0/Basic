#include "Source.h"

/*
// Szkic dzialani funkcji z modulu
//
//-------------------------------------------------------------
int move(int** pDepthTab, int nRow, int nCol, int nDepth,
	int move, int x, int y, int* px, int* py, int** pRoot)
{   // x  y - wsporzedne skad robimy nowy ruch
  //  wykonac kolejny ruch w kierunku nextMove obliczajac nowe wspolrzedne *px *py
	   //(switch)
	//sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy
	// a nastepnie sprawdzic warunek czy nie jest a plytko oraz
	// czy nie bylo sie juz w lokalizacji (*px,*py) - wg tabl pRoot

//    jesli wszystkie warunki poprawne to zwracamy 1
  //   jesli nie to 0
}

//----------------------------------------------------------------------------------
int root(int** pDepthTab, int nRow, int nCol, int nDepth,
	int x, int y, int** pRoot, int x_dest, int y_dest)
{
	// tabl pRoot pamieta droge     - liczba<>0 pole przez ktore odwiedzono (plynie statek) 
								  //  tj. kolejny numer ruchu 
	//                                0 pole nie odwiedzone
	// czyli do pozycji x i y wstawic numer kolejnego ruchu - lokalna zmienna pamietajaca kolejny numer ruchu!!

	if( dotarto do portu )
		return 1;
}

// zdefiniowac nowe wspolrzende 
  // sprwadzic wszystkie mozliwosci ruchu (for od UP do LEFT)
	// jesli ruch jest mozliwy w zadanym kierunku - funkcja move()
	  // to jesli rekurencyjnie wolany root() zwroci prawde to  return 1;
	}
	// jesli wracamy to ustawiamy w pRoot ze ruch byl zly  - czyli 0


   }

}


========== = 10 15 14 16 10  6  6
9 14  6 12  6  5  6
6 10  6 11  5  6  4
4 11  5  6 10  4  4
13 12 10 13 15 12 11
5 10 10 12 10  6 10

*/