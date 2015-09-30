#include <iostream.h>
#include <conio.h>

const int sz = 5;
int v, x, top;

struct Bag {
	char name;
	int bag[sz];
	int n;
	int back;
};

Bag a, b, c;
Bag *from, *to, *temp;

void showBags();
void honTower();
int move( Bag*, Bag*);
int ordered( Bag* );

void main() {
/////////////////////////////////////////////////////
  clrscr();
	a.name = 'A';
	a.n = sz-1;

	b.name = 'B';
	b.n = -1;

	c.name = 'C';
	c.n = -1;

	from = &a;
	if( (sz % 2) == 0 )
		to = &b, temp = &c;
	else
		to = &c, temp = &b;
	x = sz;
	for( v=0; v < sz; v++ )
	 from->bag[v] = x--;
	showBags();
	getch();
	honTower();
	to = &c;
	move( from, to );
	from = &b;

	if( (temp->n % 2) == 0 )
		to = &a, temp = &c;
	else
		to = &c, temp = &a;
	//e
	honTower();
//honTower(int n, Bag *from, Bag *to, Bag *temp) {
} // end of main

void showBags() {
//***************************************
	clrscr();
	cout << "\n\n From bag " << a.name << " = ";
	for( v=0; v <= a.n; v++ )
	 cout << from->bag[v] << ", ";
	//cout << from->bag[from->n];

	cout << "\n\n Temp bag " << b.name << " = ";
	for( v=0; v <= b.n; v++ )
	 cout << b.bag[v] << ", ";
	//cout << temp->bag[temp->n];

	cout << "\n\n To bag   " << c.name << " = ";
	for( v=0; v <= c.n; v++ )
	 cout << c.bag[v] << ", ";
	//cout << to->bag[to->n];

} // end of showBags

void honTower()
/////////////////////////////////////////////////////
{
	while( from->n > 0 )
	{
		top = from->bag[from->n];
		move( from, to );
		while( !ordered( to ) )
		{
			if( from->back > 0 )
			{
				move( from, temp );
				move( from, to );
				from->back -=2;
			}
			if( ((temp->n+1) % 2) == 1 )
			{
				move( temp, to );
				if( temp->n != -1 )
				{
					move( temp, from );
					from->back++;
					move( to, from );
					from->back++;
					move( temp, to );
				}
			}
			else
			{
				move( temp, from );
				move( temp, to );
				move( from, to );
			}
		}
		if( to == &b )
			to = &c, temp = &b;
		else
			to = &b, temp = &c;
		if(	from == &b && to == &c )
			if( (temp->n % 2) == 0 )
				to = &a, temp = &c;
			else
				to = &c, temp = &a;
	}
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

int ordered( Bag *bag )
//////////////////////////////////////////
{
	if( to->bag[0] != top || to->bag[to->n] != 1 ) return 0;
	if( bag->n == -1 ) return 0;
	for( v=0; v < bag->n; v++ )
	{
		if( bag->bag[v] != bag->bag[v+1]+1 )
			return 0;
	}
	return 1;
}