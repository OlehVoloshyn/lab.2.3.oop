#include <sstream>
#include<iostream>
#include "Money.h"
using namespace std;

Money::Money()
{
	uah = 0;
	coin = 0;
}

Money::Money(long u, unsigned int c)
{
	SetUah(u);
	SetCoin(c);
}

Money::Money(const Money& t)
{
	*this = t;
}

Money::~Money()
{
}

Money& Money::operator++()
{
	++uah;
	return *this;

}

Money& Money::operator--()
{
	--uah;
	return *this;

}

Money Money::operator++(int)
{
	Money t(*this);
	coin++;
	return t;
}

Money Money::operator--(int)
{
	Money t(*this);
	coin--;
	return t;
}

void Money::Init(long a, unsigned int b)
{
	SetUah(a);
	SetCoin(b);
}



void Display(Money r)
{
	cout << r.toString();
}

Money Read()
{
	long x;
	unsigned int y;
	Money q;
	cout << "Input suma :" << endl;
	cout << "UAH ="; cin >> x;
	cout << "Coin ="; cin >> y;
	q.Init(x, y);
	return q;
}

string Money::toString() const
{
	string s;
	stringstream sout;
	if (coin < 10)
		sout << uah << " , 0" << coin << endl;
	else 
		sout << uah << " , " << coin << endl;
	return sout.str();

}

Money Add(Money l, Money r)
{
	Money t;

	t.uah = l.uah + r.uah + floor((l.coin + r.coin) / 100);

	t.coin = (l.coin + r.coin) % 100;

	return t;
}

Money Div(Money l, Money r)
{
	Money t;
	if (r.uah != 0 && r.coin != 0)
	{
		t.uah = l.uah / r.uah;

		t.coin = l.coin / r.coin;
	}
	return t;
}

Money DivD(Money l, double dr)
{
	Money t;
	if (dr != 0)
	{
		t.uah = l.uah / dr;

		t.coin = l.coin / dr;
	}
	return t;
}

ostream& operator<<(ostream& out, const Money& a)
{
	out << a.toString() << endl;
	return out;

}
