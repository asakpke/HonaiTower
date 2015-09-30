#include <iostream.h>
#include <conio.h>

const int sz = 6;
int v, x;

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
void from2temp();
void temp2to();
int move( Bag*, Bag*);
int ordered( Bag* );

void main() {
//////////////////////////////////////////
	clrscr();
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

	from = &a;
	temp = &b;
	to   = &c;
	showBags();
	getch();
	honTower();
//honTower(int n, Bag *from, Bag *to, Bag *temp) {
} // end of main

void showBags() {
//////////////////////////////////////////
	clrscr();
	cout << "\n\n From bag " << from->name << " = ";
	for( v=0; v <= from->n; v++ )
	 cout << from->bag[v] << ", ";
	//cout << from->bag[from->n];

	cout << "\n\n Temp bag " << temp->name << " = ";
	for( v=0; v <= temp->n; v++ )
	 cout << temp->bag[v] << ", ";
	//cout << temp->bag[temp->n];

	cout << "\n\n To bag   " << to->name << " = ";
	for( v=0; v <= to->n; v++ )
	 cout << to->bag[v] << ", ";
	//cout << to->bag[to->n];

} // end of showBags

void honTower() {
//////////////////////////////////////////
	from = &a;
	temp = &c;
	to   = &b;
	from2temp(); // move n-1 element from a to b
	// move the nth element from a to c
	/*
	from = &a;
	temp = &b;
	to   = &c;
	move( from, to);
	showBags();
	getch();

	from = &b;
	temp = &a;
	to   = &c;
	from2temp(); // move all element from b to c
	*/
	showBags();
	getch();
} // end of honTower

void from2temp()
///////////////////////////////////////////
{
	if( from->n == 0 )
	{
		move( from, to);
		showBags();
		getch();
		return;
	}
	while( from->n > 0 || ordered(to) != 1 || temp->n != -1 )
	{
		//if( ordered(to) )

		if( temp->n > -1 && from->back == 0)
			if( !move( temp, to ) )
			{
				move( to, from );
				showBags();
				getch();

				from->back++;
				move( temp, to );
				showBags();
				getch();
				continue;
			}
			else
			{
				showBags();
				getch();
				continue;
			}
		if( from->back > 0 )
			if( move( from, temp ) )
				from->back--;
		if( move( from, to) )
		{
			//cout << "\n\n\tMoved f-t moved";
			//getch();
		}
		else
		{
			cout << "\n\n\tnot Moved f-t";
			getch();
			//while( to->n != -1 )
			//////////////////////////////////////////////////
			//////////////////////////////////////////////////
			//////////////////////////////////////////////////

			if( temp->n == -1 )
			{
				move( to, temp);
				if( !move( from, to) )
				{
					move( temp, from);
					from->back++;
					move( to, temp);
				}
			}
			else
			{
				move( temp, from);
				from->back++;
				move( to, temp);
			}
		}
		showBags();
		getch();
	}
}

void temp2to() {
//////////////////////////////////////////

}

int move( Bag *f, Bag *t) {
/////////////////////////////////////////
	if( f->n == -1 ) return 0;
	if( t->bag[t->n] > f->bag[f->n] ) {
		t->n++;
		t->bag[t->n] = f->bag[f->n];
		f->n--;
		showBags();
		return 1;
	}
	else
		return 0;
}

int ordered( Bag *bag )
//////////////////////////////////////////
{
	if( bag->n == -1 ) return 0;
	//if( bag->n == 0 ) return 1;
	for( v=0; v < bag->n; v++ )
	{
		if( bag->bag[v] != bag->bag[v+1]+1 )
			return 0;
	}
	return 1;
}