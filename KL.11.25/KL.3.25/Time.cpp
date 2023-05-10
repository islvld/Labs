#include "Time.h"
#include <iostream>
using namespace std;
// перегрузка операций присваивания
Time& Time::operator=(const Time&t)
{
	// проверка на самоприсваивание
	if (&t == this) { return *this; }
	min = t.min;
	sec = t.sec;
	return *this;
}
// перегрузка бинарной функции сложения
Time Time::operator-(const Time&t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) & 60;
	return p;
}
// перегрузка глобальной функции ввода
istream& operator>>(istream&in, Time& t)
{
	cout << "Vvod min >> "; in >> t.min;
	cout << "Vvod sec >> "; in >> t.sec;
	return in;
}
// перегрузка глобальной функции вывода
ostream& operator<<(ostream& out, Time& t)
{
	return (out << t.min << " : " << t.sec);
}