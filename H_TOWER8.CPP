#include <iostream.h>
#include <conio.h>
#include <process.h>

const int sz = 10;
int v, x;

struct Bag {
	char name;
//	int *bag;
	int bag[sz];
	int n;
	int back;
	//int si;	//starting index
};

Bag a, b, c;
//Bag *from, *to, *temp;

void showBags();
void honTower( Bag *from, Bag *temp, Bag *to, int fromsi, int tempsi, int tosi, int lowest );
int move( Bag *from, Bag *to);
int ordered( Bag *bag, int topElement, int lowest, int bagsi );

void main() {
/////////////////////////////////////////////////////
	clrscr();
	//a.si = b.si = c.si = 0;
	/*cout << "\nEnter the number of plates in Tower of Honia = ";
	cin >> sz;
	while( sz <= 0 )
	{
		cout << "\nEnter a value > 0 : ";
		cin >> sz;
	}
	a.bag = new int(sz);
	b.bag = new int(sz);
	c.bag = new int(sz);
	if( !a.bag || b.bag || c.bag )
	{
		cout << "\nMemory not allocated";
		getch();
		exit(1);
	}*/
	a.back = b.back = c.back = 0;
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
	//getch();
	if( (sz % 2) == 0 )
		honTower( &a, &c, &b, 0, 0, 0, 1 );
		//honTower( n, from, temp, to );
	else
		honTower( &a, &b, &c, 0, 0, 0, 1 );

	/*delete[] a.bag;
	delete[] b.bag;
	delete[] c.bag;*/

	//move( &a, &c );
	/*b.si = 1;
	if( (b.n % 2) == 0 )
		honTower( &b, &c, &a );
		//honTower( n, from, temp, to );
	else
		honTower( &b, &a, &c );*/
	cout << "\n\n\tWell-done";
	//getch();
//honTower(int n, Bag *from, Bag *to, Bag *temp) {
} // end of main

void showBags() {
//***************************************
	clrscr();
	cout << "\n\n\n " << a.name << " = ";
	for( v=0; v <= a.n; v++ )
	 cout << a.bag[v] << ", ";
	//cout << from->bag[from->n];

	cout << "\n\n\n " << b.name << " = ";
	for( v=0; v <= b.n; v++ )
	 cout << b.bag[v] << ", ";
	//cout << temp->bag[temp->n];

	cout << "\n\n\n " << c.name << " = ";
	for( v=0; v <= c.n; v++ )
	 cout << c.bag[v] << ", ";
	//cout << to->bag[to->n];

} // end of showBags

void honTower( Bag *from, Bag *temp, Bag *to, int fromsi, int tempsi, int tosi, int lowest )
/////////////////////////////////////////////////////
{
	while( from->n >= fromsi )
	{
		int top = from->bag[from->n];
		move( from, to );
		while( !ordered(to, top, lowest, tosi ) )
		{
			if( temp->n >= tempsi )
			{
				//while( temp->n >= tempsi )
					if( ( (temp->n+1-tempsi) % 2) == 0 )
					{
						honTower( temp, to, from, tempsi, (to->n == -1)?tosi:to->n+1, (from->n == -1)?fromsi:from->n+1, temp->bag[temp->n] );
						/*if( from->n >= fromsi )
							from->back++;*/
					}
					else
					{
						honTower( temp, from, to, tempsi, (from->n == -1)?fromsi:from->n+1, (to->n == -1)?tosi:to->n+1, temp->bag[temp->n] );
						/*if( to->n >= tosi )
							to->back++;*/
					}
			}
			else if( from->n >= fromsi );
				/*if( from->back > fromsi )
				{
					if( (from->back % 2) == 0 )
						honTower( from, to, temp, fromsi, to->n+1, temp->n+1, from->bag[from->n] );
					else
						honTower( from, temp, to, fromsi, temp->n+1, to->n+1, from->bag[from->n] );
					from->back--;
				}*/
			else if( to->n >= tosi );
				/*if( to->back > tosi )
				{
					if( (to->back % 2) == 0 )
						honTower( to, temp, from, to->n, temp->n+1, from->n+1, to->bag[from->n] );
					else
						honTower( to, from, temp, to->n, from->n+1, temp->n+1, to->bag[from->n] );
					to->back++;
				}*/
			//else if( to->
		}
		if( from == &a )
			if( to == &b )
				to = &c, temp = &b, x = tosi, tosi = tempsi, tempsi = x;
			else
				to = &b, temp = &c, x = tosi, tosi = tempsi, tempsi = x;
		else if( from == &c )
			if( to == &b )
				to = &a, temp = &b, x = tosi, tosi = tempsi, tempsi = x;
			else
				to = &b, temp = &a, x = tosi, tosi = tempsi, tempsi = x;
		else if( from == &b )
			if( to == &c )
				to = &a, temp = &c, x = tosi, tosi = tempsi, tempsi = x;
			else
				to = &c, temp = &a, x = tosi, tosi = tempsi, tempsi = x;
	}
} // end of honTower

int move( Bag *f, Bag *t) {
/////////////////////////////////////////
	if( f->n == -1 ) return 0;
	if( t->n == -1 || t->bag[t->n] > f->bag[f->n] ) {
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

int ordered( Bag *bag, int tp, int lw, int bagsi )
//////////////////////////////////////////
{
	if( bag->bag[bagsi] != tp || bag->bag[bag->n] != lw ) return 0;
	if( bag->n == -1 ) return 0;
	for( v=bagsi; v < bag->n; v++ )
	{
		if( bag->bag[v] != bag->bag[v+1]+1 )
			return 0;
	}
	return 1;
}