// EOJ T1-9
#include <stdio.h>

int main(void)
{
    float a, b, c, d, m, n;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    m = a + b + c + d;
    n = (a + b + c + d) / 4.0;
    printf("Total: %.2f\n", m);
    printf("Average: %.2f\n", n);
    return 0;
}