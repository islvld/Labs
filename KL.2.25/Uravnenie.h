#include <iostream>
#include <string>
using namespace std;
class Uravnenie
{
	double A, B, C;
public:
	Uravnenie(); // ����������� ��� ����������
	Uravnenie(double, double, double); // ����������� � �����������
	Uravnenie(const Uravnenie&); // ������������ �����������
	~Uravnenie(); // ����������
	double get_A(); // ��������
	void set_A(double); // �����������
	double get_B();
	void set_B(double);
	double get_C();
	void set_C(double);
	void show(); // �������� ���������
};