#include <stdio.h>

int judgecompos(int n) //在n~n+99之内进行素数累加
{
    int count = 0;
    for (int i = n + 1; i < n + 100; i += 2) //省去偶数，节约时间
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                count++; //合数累加
                break;
            }
        }
    }
    if (count == 50)
        return 1;
    else
        return 0;
}

int main()
{
    int begin = 0, n = 0;
    scanf("%d", &n);
    for (int i = 0;; i += 100) //这里取了一个巧，i从1671700开始，i从0开始也是没问题的
    {
        if (judgecompos(i) == 1)
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