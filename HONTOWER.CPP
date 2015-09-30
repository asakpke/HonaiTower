#include <iostream.h>
#include <conio.h>

const int sz = 5;
int v, x, nA=sz-1, nB=-1, nC=-1;
int bagA[sz], bagB[sz], bagC[sz];
int *from=bagA, *to=bagC, *temp=bagB;

struct Bag {
  int bag[sz];
  int n;
};

Bag a, b, c;
Bag *f, *t, *te;

void showBags();
void honTower();

void main() {
//***************************************
  clrscr();
  f = &a;
  x = sz;
  for( v=0; v < sz; v++ )
	 bagA[v] = x--;
  showBags();
  honTower();
} // end of main

void showBags() {
//***************************************
  clrscr();
  cout << "\n A = ";
  for( v=0; v <= nA; v++ )
	 cout << bagA[v] << ", ";

  cout << "\n B = ";
  for( v=0; v <= nB; v++ )
	 cout << bagB[v] << ", ";

  cout << "\n C = ";
  for( v=0; v <= nC; v++ )
	 cout << bagC[v] << ", ";

  getch();
} // end of showBags

void honTower() {
//***************************************
  int num;
  while( nA != -1 ) {
	 num = bagA[nA];
	 if( bagB[nB] > num || nB == -1 ) {
		nA--;
		nB++;
		bagB[nB] = num;
	 }
	 else if ( bagC[nC] > num || nC == -1 ) {
		nA--;
		nC++;
		bagC[nC] = num;

	 }
	 else if ( bagC[nC] > bagB[nB] ) {
		nC++;
		bagC[nC] = bagB[nB];
		nB--;
	 }
	 else {
		nA++;
		bagA[nA] = bagC[nC];
		nC--;
		if( bagB[nB] > bagC[nC] ) {
		  nB++;
		  bagB[nB] = bagC[nC];
		  nC--;
		}
		else {
		  bagA[++nA] = bagC[nC++];
		  bagC[++nC] = bagB[nB++];
		}
	 }
	 showBags();
  }
} // end of honTower