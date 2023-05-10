#include "Uravnenie.h"
#include <iostream>
#include <string>
using namespace std;
// ����������� ��� ����������
Uravnenie::Uravnenie()
{
	A = 0;
	B = 0;
	C = 0;
	cout << "Constructor bez parametrov dlya objecta " << this << endl;

}
// ����������� � �����������
Uravnenie::Uravnenie(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
	cout << "Constructor s parametrami dlya objecta " << this << endl;

}
// ����������� �����������
Uravnenie::Uravnenie(const Uravnenie &t)
{
	A = t.A;
	B = t.B;
	C = t.C;
	cout << "Constructor copirovaniya dlya objecta " << this << endl;
}
// �����������
Uravnenie::~Uravnenie()
{
	cout << "Destructor dlya objecta " << this << endl;
}
// ���������
double Uravnenie::get_A()
{
	return A;
}
double Uravnenie::get_B()
{
	return B;
}
double Uravnenie::get_C()
{
	return C;
}
// ������������
void Uravnenie::set_A(double a)
{
	A = a;
}
void Uravnenie::set_B(double b)
{
	B = b;
}
void Uravnenie::set_C(double c)
{
	C = C;
}
// �������� ���������
void Uravnenie::show()
{
	cout << "A : " << A << endl;
	cout << "B : " << B << endl;
	cout << "C : " << C << endl;
	cout << endl;
}
