#include"Money.h"
#include<iostream>

using namespace std;

int main()
{

	Money a(1,2), b, c, d, f;
	double dr;

	cout << a++ << endl;
	cout << a-- << endl;
	cout << ++a << endl;
	cout << --a << endl;

	Money Read();
	a = Read();
	b = Read();

	c = Add(a, b);
	Display(c);

	d = Div(a, b);
	Display(d);

	cout << "drib ="; cin >> dr;
	f = DivD(a, dr);
	Display(f);

	return 0;
}