// NOJ T037
#include <stdio.h>
#include <math.h>

int getfloor(double x)
{
    int value;
    if (x >= 0) //如果是大于等于0的正数
        value = (int)x;
    else
    { //如果是小于0的负数，则分两种情况：-2.8，取整为-2，实际为-3，判断依据：-2.8减去取整得到的数的值小于0； -2.0，取整得到的数为-2，此时两者相等
        int temp = (int)x;
        if (x - temp * 1.0 < 0)
            value = temp - 1;
        else
            value = temp;
    }
    return value;
}

int main()
{
    double x;
    int value;
    scanf("%lf", &x);
    value = getfloor(x);
    printf("%d", value);
    return 0;
}