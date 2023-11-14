#include <iostream>
using namespace std;
int main()
{
    int i, j;
    double mul;
    for (i = 1010;; i++)
    {
        mul = i;
        for (j = 0; j < 5; j++)
            mul = mul * 5 / 4 + 1;
        if (mul == int(mul))
            break;
    }
    cout << int(mul) << ' ' << i << endl;
    return 0;
}