#include <iostream>
using namespace std;

int main()
{
	int n, a1,a2,k = 1, s = 0;
	cout << "Vvedite N >> ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a1 = i;
		a2 = i;
		for (int j = 1; j <= k; j++)
		{
			a2 += 1;
			a1 = a1 * a2;
		}
		cout << i << ") " << a1 << endl;
		s += a1;
		k += 1;
	}
	cout << endl <<"Summa = " << s << endl;
}

