
#include <iostream>

using namespace std;

int main()
{
    float a, b, v;
    cin >> a >> b;
    float *ua = &a;
    float *ub = &b;
    
    if (*ua >* ub)
    {
        *ua = *ua * 2;
    }
    else
    {
        *ub = *ub / 2;
    }
    cout << a << endl;
    cout << b;

}


