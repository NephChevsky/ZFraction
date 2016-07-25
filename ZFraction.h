#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED

#include <iostream>

using namespace std;

class ZFraction
{
	public:
	ZFraction(int a, int b);
	ZFraction(int a);
	ZFraction();
	friend ostream &operator<<( ostream &flux, ZFraction const& a);

	int num;
	int denum;
};

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction result;
	result.num = a.num*b.denum + b.num*a.denum;
	result.denum = a.denum*b.denum;
	return result;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction result;
	result.num = a.num*b.num;
	result.denum = a.denum*b.denum;
	return result;
}

ostream &operator<<( ostream &flux, ZFraction const& a)
{
    flux << a.num << "/" << a.denum;
    return flux;
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
	if ((double)a.num/(double)a.denum > (double)b.num/(double)b.denum)
		return 1;
	else
		return 0;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
	if ((double)a.num/(double)a.denum == (double)b.num/(double)b.denum)
		return 1;
	else
		return 0;
}






ZFraction::ZFraction(int a, int b)
{
    num = a;
    denum = b;
}

ZFraction::ZFraction(int a)
{
    num = a;
    denum = 1;
}

ZFraction::ZFraction()
{
    num = 0;
    denum = 1;
}

#endif // ZFRACTION_H_INCLUDED
