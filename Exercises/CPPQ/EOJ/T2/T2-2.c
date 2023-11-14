// EOJ T2-2
#include <stdio.h>

int main(void)
{
    int n;
    float w;
    scanf("%d", &n);
    if (n >= 10)
    {
        if (n >= 50)
            w = n * 99 * 0.8;
        else
            w = n * 99 * 0.9;
    }
    else
        w = n*99;
    printf("Count: %d, Cost: %.2f", n, w);
    return 0;
}