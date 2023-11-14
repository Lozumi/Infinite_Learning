// EOJ T1-11
#include <stdio.h>

int main(void)
{
    float a, b, c;
    scanf("%f", &a);
    b = 1.8 * a + 32;
    c = a + 273.15;
    printf("F: %.4f\n", b);
    printf("K: %.4f\n", c);
    return 0;
}