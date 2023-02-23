// EOJ T2-1
#include <stdio.h>

int main(void)
{
    float a, b;
    scanf("%f", &a);
    if (a <= 0)
        b = a * a + 1;
    else
        b = 2 * a - 1;
    printf("%.2f", b);
    return 0;
}