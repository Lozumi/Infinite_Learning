// NOJ T025
#include <stdio.h>
#include <math.h>

int main(void)
{
    int m = 0, n = 0;
    double sum = 0;
    scanf("%d %d", &m, &n);
    if (m < n)
    {
        for (int i = m; i <= n; i++)
        {
            sum = sum + 1.0 / i / i; // i*i会产生数据溢出。
        }
        printf("%.5lf", sum);
    }
    return 0;
}