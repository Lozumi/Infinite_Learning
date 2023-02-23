// NOJ T038.c
#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    double x, sum = 0, fangcha = 0, ave = 0; //要被叠加的量记得最初要赋值0！
    for (i = 1; i <= n; i++)
    {
        scanf("%lf", &x); // double型变量用%lf输入
        sum += x;
        fangcha += pow(x, 2);
    }
    ave = sum / n;
    fangcha += n * pow(ave, 2);
    fangcha -= 2 * sum * ave;
    printf("%f\n", fangcha);
}