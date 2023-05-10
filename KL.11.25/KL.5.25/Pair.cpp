#include "Pair.h"
Pair& Pair::operator=(const Pair& c)
{
	if (&c == this)return *this;
	first = c.first;
	second = c.second;
	return *this;
}
Pair Pair::operator+(const Pair& t)
{
	Pair p;
	p.first = first + t.first;
	p.second = second + t.second;
	return p;
}
Pair Pair::operator-(const Pair& t)
{
	Pair p;
	p.first = first - t.first;
	p.second = second - t.second;
	return p;
}
Pair Pair::operator/(const Pair& t)
{
	Pair p;
	p.first = first / t.first;
	p.second = second / t.second;
	return p;
}
istream& operator>>(istream& in, Pair& c)
{
	cout << "\nfirst:"; in >> c.first;
	cout << "\nsecond:"; in >> c.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& c)
{
	out << "\nfirst : " << c.first;
	out << "\nsecond : " << c.second;
	out << "\n";
	return out;
}
void Pair::Show()
{
	cout << "\nfirst : " << first;
	cout << "\nsecond : " << second;
	cout << "\n";
}
