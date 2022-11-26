#include <stdio.h>
#include <math.h>

int main(void)
{
    int a = 0, b = 0, isF = 1, isS = 0;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    for (int i = a; i <= b; i++)
    {
        isS = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isS = 0;
                break;
            }
        }
        if (isS == 1)
        {
            if (isF == 1)
            {
                printf("%d", i);
                isF--;
            }
            else
                printf(" %d", i);
        }
    }
    return 0;
}