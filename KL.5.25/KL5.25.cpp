#include "Object.h"
#include "Pair.h"
#include "Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector(3);

	Vector v(5);//������ �� 5 ���������
	Pair a;//������ ������ Car
	cin >> a;
	Money b;// ������ ������ Lorry
	cin >> b;
	Object* p = &a;//������ ��������� �� ������ ������ Pair
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Money
	v.Add(p); //��������� ������ � ������
	cout << v;//����� �������

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