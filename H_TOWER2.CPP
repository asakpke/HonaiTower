#include <iostream.h>
#include <conio.h>

const int sz = 5;
int v, x, nA=sz-1, nB=-1, nC=-1;
int bagA[sz], bagB[sz], bagC[sz];
//int *from=bagA, *to=bagC, *temp=bagB;

struct Bag {
  char name;
  int bag[sz];
  int n;
};

Bag a, b, c;
Bag *f, *t, *r;

void showBags();
void honTower();

void main() {
//***************************************
  clrscr();
  a.name = 'A';
  a.n = sz-1;
  f = &a;

  b.name = 'B';
  b.n = -1;
  t = &b;

  c.name = 'C';
  c.n = -1;
  r = &c;

  x = sz;
  for( v=0; v < sz; v++ )
	 f->bag[v] = x--;
  showBags();
  honTower();
} // end of main

void showBags() {
//***************************************
  clrscr();
  cout << "\n\n From bag " << f->name << " = ";
  for( v=0; v <= f->n; v++ )
	 cout << f->bag[v] << ", ";
  //cout << from->bag[from->n];

  cout << "\n\n Ruff bag " << r->name << " = ";
  for( v=0; v <= r->n; v++ )
	 cout << r->bag[v] << ", ";
  //cout << r->bag[temp->n];

  cout << "\n\n To bag   " << t->name << " = ";
  for( v=0; v <= t->n; v++ )
	 cout << t->bag[v] << ", ";
  //cout << t->bag[to->n];

  getch();
} // end of showBags

void honTower() {
//***************************************
  int num;
  while( f->n != -1 ) {
	 if( t->n == -1 ) {
		t->n++;
		t->bag[t->n] = f->bag[f->n];
		f->n--;
		showBags();
	 }
	 else
		if( r->n == -1 ) {
		  r->n++;
		  r->bag[r->n] = f->bag[f->n];
		  f->n--;
		  showBags();

		  r->n++;
		  r->bag[r->n] = t->bag[t->n];
		  t->n--;
		  showBags();
		}
		else {
		  t->n++;
		  t->bag[t->n] = r->bag[r->n];
		  r->n--;
		  showBags();

		  f->n++;
		  f->bag[f->n] = r->bag[r->n];
		  r->n--;
		  showBags();

		  f->n++;
		  f->bag[f->n] = t->bag[t->n];
		  t->n--;
		  showBags();

		  r->n++;
		  r->bag[r->n] = t->bag[r->n];
		  t->n--;
		  showBags();

		  t->n++;
		  t->bag[t->n] = f->bag[f->n];
		  f->n--;
		  showBags();
		}
  }
} // end of honTower