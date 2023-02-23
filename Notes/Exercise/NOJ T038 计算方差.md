> 西北工业大学C程序设计基础NOJ T038

## description 

编写函数计算方差。请记住：不能使用数组。

#### input 

第 1 行输入 n，为整型

第 2 行输入 x1,x2,……，均为 double 型，用空格隔开。

#### output 

输出 s，double 型，小数点后 6 位。

#### sample_input 

```c
5 

1 2 3 4 5 
```

#### sample_output 

```c
10.000000 
```

## solution

使用数组的主要意义是能有序的记录一组数据，而使用for循环只能让一个变量去[遍历](https://so.csdn.net/so/search?q=遍历&spm=1001.2101.3001.7020)这组数据，并不能记录这组数据。
如果想让for循环能尽可能实现记录数据的作用，可以使用叠加叠乘的方法，通过记录一组数据的和或积，从而间接体现这组数据。

此处使用方差计算公式的变式，$s=\sqrt{\frac{\left(x_{1}^{2}+x_{2}^{2}+x_{3}^{2}+\dots +x_{n}^{2}\right)-n*\bar{x}}{n}}$。

**源代码**

```c
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
```

=EOF=

## reference

[C语言中如何在不使用数组的情况下求方差？使用数组和使用for循环的区别。_圆溜溜的奶黄包的博客-CSDN博客](https://blog.csdn.net/lydia_ke/article/details/78282935)