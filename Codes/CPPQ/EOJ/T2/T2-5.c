// EOJ T2-5
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0, b = 0, w = 0;
    scanf("%f %f", &b, &a);
    if (a < -15)
        a = fabs(a) - 15;
    else if (-15 <= a && a < 0)
        a = 0;
    if (b > 0 && b <= 2160)
        w = a * 0.4983;
    else if (b > 2160 && b <= 4200)
        w = a * 0.5483;
    else if (b > 4200)
        w = a * 0.7983;
    printf("当月电费：%.2f", w);
    return 0;
}