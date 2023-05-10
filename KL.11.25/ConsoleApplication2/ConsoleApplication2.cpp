// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int h = 0, z, p;

	do {
		cout << "Основание = ";
		cin >> h;
	} while (h % 2 == 0);
	z = 1;
	p = h / 2;

	for (int i = 0; i < h / 2 + 1; i++) {
		for (int j = 0; j < p; j++) {
			cout << " ";
		}
		for (int j = 0; j < z; j++) {
			cout << "*";
		}
		z += 2;
		p -= 1;
		cout << endl;
	}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < h; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}

