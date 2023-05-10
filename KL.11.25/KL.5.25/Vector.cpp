#include "Vector.h"
//����������� ��� ����������
Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
//����������
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//����������� � �����������
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
//�������� ������
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
	return out;
}
