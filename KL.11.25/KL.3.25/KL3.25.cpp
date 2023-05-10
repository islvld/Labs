#include "Time.h"
#include <iostream>
using namespace std;
// операция сравнения
void sravn(Time& a, Time& b)
{

	int tempa, tempb, am, as, bm, bs;
	am = a.get_min();
	as = a.get_sec();
	bm = b.get_min();
	bs = b.get_sec();
	tempa = am * 60 + as;
	tempb = bm * 60 + bs;
	if (tempa == tempb)cout << "\na = b\n";
	if (tempa != tempb)
	{
		if (tempa > tempb)cout << "\na > b\n";
		else cout << "\na < b\n";
	}
}
void main()
{
	Time a; // констурктор без параметров
	Time b; // констурктор без параметров
	Time c; // констурктор без параметров
	cin >> a; // ввод
	cin >> b; // ввод
	c = a - b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	sravn(a, b);
}