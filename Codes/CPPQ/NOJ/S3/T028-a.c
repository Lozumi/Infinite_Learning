// NOJ T028

#include <stdio.h>

double polyf(int n)
{
    double sum = 0, deno = 0;
    for (int i = 1; i <= n; i++)
    {
        deno = 0;
        for (int j = 1; j <= i; j++) //分母
        {
            deno += 1.0 / j;
        }
        sum += 1.0 / deno;
    }
    return sum;
}

int main(void)
{
    int a = 0, b = 0, sumn = 0, flag = 0;
    scanf("%d %d", &a, &b);
    for (int n = 1;; n++)
    {
        double poly = polyf(n);
        if ((a < poly) && (poly < b))
        {
            sumn++;
            flag = 1;
        }
        else
        {
            if (flag == 1)
            {
                if (sumn == 1)
                    printf("%d", n - 1);
                else
                {
                    int sol1 = n - sumn;
                    int sol2 = n - 1;
                    printf("%d %d", sol1, n - 1);
                }
                break;
            }
        }
    }
    return 0;
}
