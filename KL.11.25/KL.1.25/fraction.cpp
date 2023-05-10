#include <iostream>
#include "fraction.h"
using namespace std;

// ����� ������������� ����� ���������
void fraction::Init(int F, int S)
{
	first = F;
	second = S;
}

// ����� ��� ������ �������� �����
void fraction::Read()
{
	cout << endl << "First >> "; cin >> first;
	cout << "Second >> "; cin >> second;
}

// ����� ��� ������ �������� �����
void fraction::Show()
{
	cout << endl << "First = " << first;
	cout << endl << "Second = " << second;
	cout << endl;
}

// ����� ��� ���������� ������� � ������
int fraction::Minutes()
{
	return (60 * first + second);
}
