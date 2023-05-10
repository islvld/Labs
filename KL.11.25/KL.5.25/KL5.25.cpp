#include "Object.h"
#include "Pair.h"
#include "Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector(3);

	Vector v(5);//вектор из 5 элементов
	Pair a;//объект класса Car
	cin >> a;
	Money b;// объект класса Lorry
	cin >> b;
	Object* p = &a;//ставим указатель на объект класса Pair
	v.Add(p);//добавляем объект в вектор
	p = &b;//ставим указатель на объект класса Money
	v.Add(p); //добавляем объект в вектор
	cout << v;//вывод вектора

	Pair t1;
	cin >> t1;
	cout << t1;
	Pair t2(4, 6);
	cout << endl;
	cout << t1 + t2 << endl;
	cout << t1 - t2 << endl;
	cout << t1 / t2 << endl;

	Money t3;
	cin >> t3;
	cout << t3;
	cout << endl;
	Money t4(2, 10);
	cout << t3 + t4 << endl;
	cout << t3 - t4 << endl;
	cout << t3 / t4 << endl;
}