// NOJ T003
#include <stdio.h>

int main(void)
{
    float a = 0, b = 0, c = 0, s = 0, avg = 0;
    scanf("%f %f %f", &a, &b, &c);
    s = a + b + c;
    avg = (a + b + c) / 3.0;
    printf("%.6f\n%.6f", s, avg);
    return 0;
}