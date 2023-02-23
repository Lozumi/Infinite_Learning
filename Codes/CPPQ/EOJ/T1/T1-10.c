// EOJ T1-10
#include <stdio.h>

int main(void)
{
    float a, b, c, d, e, f, s;
    scanf("%f:%f, %f:%f, %f:%f", &a, &b, &c, &d, &e, &f);
    s = a * b + c * d + e * f;
    printf("Total: %.2f\n", s);
    return 0;
}