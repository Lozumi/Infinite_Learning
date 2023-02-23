// NOJ T017
#include <stdio.h>
#include <math.h>

double f(double x);      //方程
const double eps = 1e-6; //定义我们计算的精度

int main()
{
    double x0 = 0, x1 = 0, x2 = 0, fx0 = 0; //[x1,x2]为寻找区间，x0为中点,浮点型数据
    scanf("%lf %lf", &x1, &x2);

    if (f(x1) * f(x2) < 0)
    {
        while (fabs(x2 - x1) > eps)
        {
            x0 = (x1 + x2) / 2.0; //取x1,x2的中点
            fx0 = f(x0);
            if (fabs(fx0) < eps) //满足精确度
                break;
            else if (f(x0) * f(x1) < 0)
            {
                x2 = x0; //修正区间，将[x1,x2]换成[x1,x0],这里的x0是中点
            }
            else if (f(x0) * f(x2) < 0)
            {
                x1 = x0; //修正区间，将[x1,x2]换成[x0,x2],这里的x0是中点
            }
        }
    }
    else
    {
        return 1;
    }

    //    printf("最终缩小到区间：%lf  %lf", x1, x2);
    //    x0 = (x1 + x2) / 2;
    printf("%.2lf\n", x0);

    return 0;
}

double f(double x) //定义函数(方程)
{
    return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}
