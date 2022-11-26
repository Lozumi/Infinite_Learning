// NOJ T019
#include <stdio.h>

double add(void);
double x = 0, y = 0;

int main(void)
{
    double sum = 0;
    x = 1;
    y = 2;
    for (int i = 1; i <= 20; i++)
    {
        sum = sum + add();
    }
    printf("%.6lf", sum);
    return 0;
}

double add(void)
{
    double result = 0, temp = 0; // x 1 y 2
    result = y / x;
    x += y; // x 3 y 2
    temp = y;
    y = x;
    x = temp; // x 2 y 3
    return result;
}