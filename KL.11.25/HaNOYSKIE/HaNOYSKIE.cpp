#include <iostream>
using namespace std;

int HB(int n, int start, int end, int help)
{
	if (n > 0)
	{
		HB(n - 1, start, help, end);
		cout << start << " => " << end << endl;
		HB(n - 1, help, end, start);
	}
	return 0;
}

int main()
{
	setlocale(0, "");
	int k;
	cout << "Введите кол-во дисков : ";
	cin >> k;
	cout << HB(k, 1, 2, 3);
}