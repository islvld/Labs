#include "Time.h"
#include <iostream>
using namespace std;
void main()
{
	Time a; // констурктор без параметров
	Time b; // констурктор без параметров
	Time c; // констурктор без параметров
	cin >> a; // ввод
	cin >> b; // ввод
	++a; // префиксна€ операци€ инкремент
	cout << a << endl; // вывод
	c = (a++) - b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}