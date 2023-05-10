#include <iostream>
#include "fraction.h"
#include <Windows.h>
using namespace std;

fraction make_fraction(int F, int S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	// Определение переменных А и В
	cout << endl << "_____Main_____" << endl;
	fraction A;
	fraction B;
	A.Init(3, 40);
	B.Read();
	A.Show();
	B.Show();
	cout << endl;
	// Вывод приведенного времени в минуты
	cout << "Time A : " << A.Minutes() << endl;
	cout << "Time B : " << B.Minutes() <<endl;

	// Указатели
	cout << endl << "___Pointers___" << endl;
	fraction* C = new fraction;
	C->Init(0, 0);
	C->Show();
	C->Read();
	C->Minutes();
	cout << "Time C : " << C->Minutes() << endl;;

	// Массивы
	cout << endl << "____Arrays____" << endl;
	fraction M[2];
	for (int i = 0; i < 2; i++)
	{
		M[i].Read();
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "Time number " << i + 1 << " = " << M[i].Minutes() << endl;
	}

	// Динамические массивы
	cout << endl << "_Dynamic arrays_" << endl;
	int n;
	cout << "N : "; cin >> n;
	fraction* DM = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		DM[i].Read();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Time number " << i + 1 << " = " << DM[i].Minutes() << endl;
	}
	delete DM;

	// Вызов функции make_fraction
	cout << endl << "__make_fraction__" << endl;
	int x, y;
	cout << "First >>"; cin >> x;
	cout << "Second >>"; cin >> y;
	// Формирование переменной(Т) с помощью функции make_fraction
	fraction T = make_fraction(x, y);
	cout <<"Time T = " << T.Minutes();
}