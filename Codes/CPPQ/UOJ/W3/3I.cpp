// UOJ W3-I
#include <iostream>
#include <cmath>
using namespace std;

int m, n, ans, flag;
long long gcd(long long x, long long y) //最大公约数
{
    if (x % y == 0)
    {
        return y;
    }
    return gcd(y, x % y);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= sqrt(1ll * m * n); i++)
    {
        if ((1ll * n * m) % i == 0 && gcd(i, (1ll * n * m) / i) == n) //最大公约数可以产生的个数
        {
            ans++;
            if (1ll * i * i == 1ll * n * m)
                flag = 1;
        }
    }
    cout << ans * 2 - flag; //半遍历变全遍历
    return 0;
}