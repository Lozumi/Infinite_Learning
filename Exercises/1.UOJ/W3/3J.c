// UOJ W3-J
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int a, b, n, s, i, isZ = 1;
    char c[81] = {0};
    scanf("%d %d %d", &a, &b, &n);
    if (a * b < 0)
        isZ = 0;
    a = abs(a);
    b = abs(b);
    s = a / b;              //整数
    a = a % b;              //余数
    for (i = 0; i < n; i++) //确定保留的小数位数
    {
        a *= 10;
        c[i] = (a / b) + '0'; //计算小数位
        a = a % b;            //余数
    }
    if (a >= 5)
        c[i - 1] += 1;
    if (isZ == 0)
        printf("-");
    printf("%d.%s", s, c);
    return 0;
}
