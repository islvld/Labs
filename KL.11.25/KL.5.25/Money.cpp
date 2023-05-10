#include "Money.h"
Money& Money::operator=(const Money& c)
{
	if (&c == this)return *this;
	rub = c.rub;
	kop = c.kop;
	return *this;
}
istream& operator>>(istream& in, Money& c)
{
	cout << "\nrub:"; in >> c.rub;
	cout << "\nkop:"; in >> c.kop;
	return in;
}
ostream& operator<<(ostream& out, const Money& c)
{
	out << "\nrub : " << c.rub;
	out << "\nkop : " << c.kop;
	out << "\n";
	return out;
}
Money Money::operator+(const Money& t)
{
	Money p;
	p.rub = rub + t.rub;
	p.kop = kop + t.kop;
	return p;
}
Money Money::operator-(const Money& t)
{
	Money p;
	p.rub = rub - t.rub;
	p.kop = kop - t.kop;
	return p;
}
Money Money::operator/(const Money& t)
{
	Money p;
	p.rub = rub / t.rub;
	p.kop = kop / t.kop;
	return p;
}
void Money::Show()
{
	cout << "\nrub : " << rub;
	cout << "\nkop : " << kop;
	cout << "\n";
}
