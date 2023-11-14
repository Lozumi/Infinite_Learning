#include <stdio.h>
#include <math.h>
int main()
{
    const float g = 9.8;
    float a, b, c, d;
    scanf("%f %f", &a, &b);
    c = a + g * b;
    d = a * b + g * b * b / 2.0;
    printf("V:%.2f\n", c);
    printf("V:%.2f\n", d);
    return 0;
}