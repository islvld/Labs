#include "Uravnenie.h"
#include <iostream>
#include <string>
using namespace std;
Uravnenie make_uravnenie()
{
	double a, b, c;
	cout << "Vvod A >> ";
	cin >> a;
	cout << "Vvod B >> ";
	cin >> b;
	cout << "Vvod C >> ";
	cin >> c;
	Uravnenie t(a, b, c);
	return t;
}

void print_uravnenie(Uravnenie t)
{
	t.show();
}

void main()
{
	// конструктор без параметров
	Uravnenie t1;
	// конструктор с параметром
	Uravnenie t2(2.5, 3.2, 4.8);

	Uravnenie t3 = t2;
	t3.set_A(2.0);
	t3.set_B(1.0);
	t3.set_C(4.5);
	// вывод
	print_uravnenie(t1);
	print_uravnenie(t2);
	print_uravnenie(t3);
	t1 = make_uravnenie();
	t1.show();
}