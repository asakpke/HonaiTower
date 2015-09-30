#include <iostream.h>
#include <conio.h>

const int sz = 10;
int v, x;

struct Bag {
  char name;
  int bag[sz];
  int n;
};

Bag a, b, c;
Bag *fromA, *toC, *tempB;

void showBags();
void honTower(int, Bag*, Bag*, Bag*);
int	move( Bag *From, Bag *To );

void main() {
//***************************************
  clrscr();
  a.name = 'A';
  a.n = sz-1;
	fromA = &a;

  b.name = 'B';
  b.n = -1;
  toC = &c;

	c.name = 'C';
	c.n = -1;
	tempB = &b;

	x = sz;
	for( v=0; v < sz; v++ )
	 fromA->bag[v] = x--;
	showBags();
	getch();
	honTower(sz, fromA, toC, tempB );
//honTower(int n, Bag *from, Bag *to, Bag *temp) {
} // end of main

void showBags() {
//***************************************
  clrscr();
  cout << "\n\n From bag " << fromA->name << " = ";
  for( v=0; v <= fromA->n; v++ )
	 cout << fromA->bag[v] << ", ";
  //cout << from->bag[from->n];

  cout << "\n\n Temp bag " << tempB->name << " = ";
  for( v=0; v <= tempB->n; v++ )
	 cout << tempB->bag[v] << ", ";
  //cout << temp->bag[temp->n];

	cout << "\n\n To bag   " << toC->name << " = ";
  for( v=0; v <= toC->n; v++ )
	 cout << toC->bag[v] << ", ";
  //cout << to->bag[to->n];

} // end of showBags

void honTower(int n, Bag *from, Bag *to, Bag *temp) {
//***************************************
	if( n == 0 ) return;

	honTower(n-1, from, temp, to);

	move( from, to );

	honTower(n-1, temp, to,from);
} // end of honTower

int move( Bag *f, Bag *t) {
/////////////////////////////////////////
	if( f->n == -1 ) return 0;

	if( t->bag[t->n] > f->bag[f->n] ) {
		t->n++;
		t->bag[t->n] = f->bag[f->n];
		f->n--;
		showBags();
		getch();
		return 1;
	}
	else
		return 0;
}
