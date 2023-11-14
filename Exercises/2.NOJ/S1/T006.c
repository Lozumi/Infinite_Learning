// NOJ T006
#include <stdio.h>

int main(void)
{
    double a = 0, b = 0;
    scanf("%lf", &a);
    if (a <= 10)
        b = a * 0.1; // 1
    else if (a > 10 && a <= 20)
        b = 1 + (a - 10) * 0.075; // 0.75
    else if (a > 20 && a <= 40)
        b = 1 + 0.75 + (a - 20) * 0.05; // 1
    else if (a > 40 && a <= 60)
        b = 1 + 0.75 + 1 + (a - 40) * 0.03; // 0.6
    else if (a > 60 && a <= 100)
        b = 1 + 0.75 + 1 + 0.6 + (a - 60) * 0.015; // 0.6
    else if (a > 100)
        b = 1 + 0.75 + 1 + 0.6 + 0.6 + (a - 100) * 0.01;
    printf("%.6lf", b);
    return 0;
}