#include<iostream>
using namespace std;
int main()
{
	int n, c = 1, z;
	cin >> n;
	if (n % 2 == 0)
		return 0;
	int p = n;
	z = n / 2;
	n = n * 2;
	for (int i = 1; i <= n / 2 + 1; i++);
	{
		for (int j = 1; j <= z; j++)
			cout << " ";
		for (int k = 1; k <= c; k++)
		cout << "*";
		z -= 1;
		n -= 2;
		c += 2;
		cout << endl;
	}
}