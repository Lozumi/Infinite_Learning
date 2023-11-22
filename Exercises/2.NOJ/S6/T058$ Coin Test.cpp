// NOj T068 Coin
#include <iostream>
#include <cmath>
using namespace std;
int zuidagongyueshu(int a, int b) //求最大公约数
{
    int k;
    while (b % a != 0)
    {
        k = b % a;
        b = a;
        a = k;
    }
    return a;
}
int main()
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, i;
    char A[1000];
    while ((A[cnt3] = cin.get()) != '\n')
        cnt3++;
    for (i = 0; i < cnt3; i++)
    {
        if (A[i] == 'S')
        {
            cnt1 = 1;
            break;
        }
        else if (A[i] == 'U')
            cnt2++;
    }
    int y;
    y = zuidagongyueshu(cnt2, cnt3);
    double z;
    z = (double)cnt2 / cnt3 - 0.5;
    if (cnt1 == 1)
        cout << "WA" << endl;
    else if (fabs(z) <= 0.003)
        cout << cnt2 / y << '/' << cnt3 / y << endl;
    else
        cout << "Fail" << endl;
    return 0;
}