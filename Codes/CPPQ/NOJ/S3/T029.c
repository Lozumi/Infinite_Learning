// NOJ T029
#include <stdio.h>

int main(void)
{
    long n = 0, sum = 0, cn = 0;
    scanf("%d", &n);
    for (long i = 1; i <= n; i++)
    {
        cn = i;
        while (cn)
        {
            if (cn % 10 == 1)
                sum++;
            cn /= 10;
        }
    }
    printf("%d\n", sum);
    return 0;
}