// NOJ T007
#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b;
    scanf("%f", &a);
    a = ceil(a);
    if (a <= 2)
        b = 7;
    else if (a <= 15)
        b = 7 + (a - 2) * 1.5;
    else
        b = 14 + 13 * 1.5 + (a - 15) * 2, 1;
    printf("%.6f", b);
    return 0;
}