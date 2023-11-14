// NOJ T013
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += (pow(-1, i - 1) * pow(2, i) / ((pow(2, i) + pow(-1, i)) * (pow(2, i + 1) + pow(-1, i + 1))));
    }
    printf("%.6lf", sum);
    return 0;
}