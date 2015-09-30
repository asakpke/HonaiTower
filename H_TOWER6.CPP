#include <iostream.h>
#include <conio.h>

const int sz = 5;
int v, x;

struct Bag {
	char name;
	int bag[sz];
	int n;
	int back;
	int si;	//starting index
};

Bag a, b, c;
//Bag *from, *to, *temp;

void showBags();
void honTower( Bag *from, Bag *temp, Bag *to );
int move( Bag *from, Bag *to);
int ordered( Bag *bag, int topElement );

void main() {
/////////////////////////////////////////////////////
	clrscr();
	a.si = b.si = c.si = 0;
	a.name = 'A';
	a.n = sz-1;
	b.name = 'B';
	b.n = -1;
	c.name = 'C';
	c.n = -1;
	x = sz;
	for( v=0; v < sz; v++ )
	 a.bag[v] = x--;
	showBags();
	getch();
	if( (sz % 2) == 0 )
		honTower( &a, &c, &b );
		//honTower( n, from, temp, to );
	else
		honTower( &a, &b, &c );
	/*move( &a, &c );
	a.si = 0;
	b.si = 0;
	c.si = 1;
	if( ((b.n+1) % 2) == 0 )
		honTower( &b, &c, &a );
		//honTower( n, from, temp, to );
	else
		honTower( &b, &a, &c );*/
	cout << "\n\n\tWell-done";
	getch();
//honTower(int n, Bag *from, Bag *to, Bag *temp) {
} // end of main

void showBags() {
//***************************************
	clrscr();
	cout << "\n\n " << a.name << " = ";
	for( v=0; v <= a.n; v++ )
	 cout << a.bag[v] << ", ";
	//cout << from->bag[from->n];

	cout << "\n\n " << b.name << " = ";
	for( v=0; v <= b.n; v++ )
	 cout << b.bag[v] << ", ";
	//cout << temp->bag[temp->n];

	cout << "\n\n " << c.name << " = ";
	for( v=0; v <= c.n; v++ )
	 cout << c.bag[v] << ", ";
	//cout << to->bag[to->n];

} // end of showBags

void honTower( Bag *from, Bag *temp, Bag *to )
/////////////////////////////////////////////////////
{
	while( from->n > -1 )
	//it should/may be from->n >= from->si
	// i.e
	{
		if( from != &a && from->n <= from->si )
			return;
		int top = from->bag[from->n];
		move( from, to );
		while( !ordered(to, top ) )
		{
			if( temp->n == temp->si-1 )
			{
				if( from->n == from->si )
					move( from, to );
				else if( from->n == from->si+1 )
				{
					move( from, temp );
					move( from, to );
					move( temp, to );
				}
				else
					while( from->n >= from->si )
					{
						temp->si = temp->n+1;
						//if( to->n > 0 )
						to->si = to->n+1;
						// it may be from->n - from->si +1;
						if( ((from->n - from->si + 1) % 2) == 0 )
							honTower( from, to, temp );
						else
							honTower( from, temp, to );
						from->si  = 0;
						//to->si	= 0;
						//temp->si = 0;
						// all element from a is come to b
						return;
					}
			}
			if( temp->n == temp->si )
				move( temp, to );
			else if( temp->n == temp->si+1 )
			{
				move( temp, from );
				move( temp, to );
				move( from, to );
			}
			else
			{
				while( temp->n > temp->si )
				{
					from->si = from->n+1;
					to->si = to->n+1; // ????????????
					if( (temp->n % 2) == 0 )
						honTower( temp, from, to );
					else
						honTower( temp, to, from );
					//from->si  = 0;
					to->si	= 0;
					// should be
					// to->si = 0;
					move( temp, to );
					continue;
				}
			}
		}
		if( from == &a )
			if( to == &b )
				to = &c, temp = &b;
			else
				to = &b, temp = &c;
		else if( from == &c )
			if( to == &b )
				to = &a, temp = &b;
			else
				to = &b, temp = &a;
		else if( from = &b )
			if( to == &c )
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

int ordered( Bag *bag, int tp )
//////////////////////////////////////////
{
	if( bag->bag[bag->si] != tp || bag->bag[bag->n] != 1 ) return 0;
	if( bag->n == -1 ) return 0;
	for( v=bag->si; v < bag->n; v++ )
	{
		if( bag->bag[v] != bag->bag[v+1]+1 )
			return 0;
	}
	return 1;
}