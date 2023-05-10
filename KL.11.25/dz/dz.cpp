#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int x1, x2, x3, x4, num; // num нужен чтобы знать номер максимального(эт если надо будет)
	int max = -1;

	cout << "1) ";
	cin >> x1;
	cout << "2) ";
	cin >> x2;
	cout << "3) ";
	cin >> x3;
	cout << "4) ";
	cin >> x4;

	if (x1 > max)
	{
		max = x1;
		num = 1;
	}
	if (x2 > max)
	{
		max = x2;
		num = 2;
	}
	if (x3 > max)
	{
		max = x3;
		num = 3;
	}
	if (x4 > max)
	{
		max = x4;
		num = 4;
	}
	cout << "Максимальный элемент под номером " << num << endl;
	cout << "Его значение равно " << max;
}


