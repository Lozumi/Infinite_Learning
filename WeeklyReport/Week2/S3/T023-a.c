// unsolved
#include <stdio.h>

int judge(int n) //判断n~n+99有没有素数
{
    for (int i = n + 1; i < n + 100; i += 2) //省去偶数，节约时间
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int begin = 0, n = 0;
    scanf("%d", &n);
    for (int i = 0;; i += 100) //这里取了一个巧，i从1671700开始，i从0开始也是没问题的
    {
        if (judge(i) == 1)
        {
            begin++;
        }
        if (n == begin)
        {
            int i2 = i + 99;
            printf("%d %d", i, i2);
            break;
        }
    }
    return 0;
}