#include <iostream>
#include "fraction.h"
using namespace std;

// метод инициализации полей структуры
void fraction::Init(int F, int S)
{
	first = F;
	second = S;
}

// метод для чтения значений полей
void fraction::Read()
{
	cout << endl << "First >> "; cin >> first;
	cout << "Second >> "; cin >> second;
}

// метод для вывода значений полей
void fraction::Show()
{
	cout << endl << "First = " << first;
	cout << endl << "Second = " << second;
	cout << endl;
}

// метод для приведения времени в минуты
int fraction::Minutes()
{
	return (60 * first + second);
}
