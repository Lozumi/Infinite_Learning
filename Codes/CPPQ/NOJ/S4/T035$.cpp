// NOJ T035
#include <stdio.h>
int fact(int num);

int main()
{
    //从n个元素中取m个组合
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int ret = fact(n) / (fact(m) * fact(n - m));
    printf("%d\n", ret);
}

int fact(int num) //求num的阶乘的函数
// 5=5*4！=5*（4*3*2*1）
// 4=4*3！=4*（3*2*1）
//递归的思想，列出函数，直接对着写
{
    if (num < 0)
    {
        return 0;
    }
    if (num == 1 || num == 0)
    {
        return 1;
    }
    if (num > 1)
    {
        return num * fact(num - 1);
    }
}