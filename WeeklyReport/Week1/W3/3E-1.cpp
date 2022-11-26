// UOJ W3-E
#include <iostream>
using namespace std;
int gcd(int m, int n);
int gcd_2(int m, int n);
int gcd_3(int m, int n);

int main(void)
{
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n) << endl;
    return 0;
}

int gcd(int m, int n) //辗转相除法
{
    int r = m % n;
    while (r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

int gcd_2(int n1, int n2) //暴力轮询法
{
    int hcf = 0;
    // 如果 n2 大于 n1 交换两个变量
    if (n2 > n1)
    {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for (int i = 1; i <= n2; ++i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
}

int gcd_3(int n1, int n2) //神秘方法
{
    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}