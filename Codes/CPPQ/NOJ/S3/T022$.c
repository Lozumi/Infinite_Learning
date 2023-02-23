// NOJ T022
#include <stdio.h>
#include <math.h>

int present(int n, int m);

int main()
{

    int m, n, g = 0, s = 0, i;

    scanf("%d%d", &m, &n);

    for (i = pow(10, n - 1); i <= pow(10, n); i++)
    {
        if (present(i, m) == 1 && i % m != 0)
        {
            g++;
            s += i;
        }
    }
    printf("%d %d\n", g, s);
    return 0;
}

int present(int n, int m) //检查是否含有m
{
    int temp, flag = 0, i;
    while (n > 0)
    {
        temp = n % 10;
        if (temp == m)
        {
            flag = 1;
            break;
        }
        n /= 10;
    }
    return flag;
}