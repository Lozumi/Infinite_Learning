// NOJ T010
#include <stdio.h>
#include <math.h>
int getDis(double x, double y);

int main(void)
{
    double x = 0, y = 0;
    scanf("%lf,%lf", &x, &y);
    if (getDis(x, y) == 1)
        printf("10\n");
    else
        printf("0\n");
    return 0;
}

int getDis(double x, double y)
{
    if (pow(x - 2, 2) + pow(y - 2, 2) <= 1 || pow(x - 2, 2) + pow(y + 2, 2) <= 1 || pow(x + 2, 2) + pow(y - 2, 2) <= 1 pow(x + 2, 2) + pow(y + 2, 2) <= 1)
        return 1;
    return 0;
}