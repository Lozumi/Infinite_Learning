> 西北工业大学C程序设计基础NOJ T024
>
> 本题来自**UVA 580 危险的组合 Critical Mass**

## 题目描述

有一些装有铀(用U表示)和铅(用L表示)的盒子，数量均足够多。要求把n个盒子放成一行，但至少有3个U放在一起，有多少种方法？

#### 输入描述 Input Description

包含一个整数n

#### 输出描述 Output Description

输出一个整数表示方法数。

#### 样例输入 Sample Input

样例1：4
样例2：5

#### 样例输出 Sample Output

样例1：3
样例2：8

#### 数据范围及提示 Data Size & Hint

对于100%的数据（3<=N<=30）

---

## 题解

#### 思路

本题是一个数学问题，需要进行分类讨论。

题目让我们求存在**连续3个以上铀**(危险组合)的个数有几个，假设把n个盒子放成一行，有$cnt \left ( n \right ) $种方法,可分两方面来考虑：

1. 如果把第一个盒子拿掉，剩下的n-1个盒子满足条件有$cnt \left ( n-1 \right ) $种方法，第一个盒子可放铀或铅，因此这种情况共有 $2*cnt \left ( n-1 \right ) $种方法。
2. 如果把第1个盒子拿掉，剩下的n-1个盒子不满足条件，那么只有第一至三个盒子是铀，第四个盒子是铅才可以。*（第四个盒子如果是铀，那么234盒子就满足条件了。）*此后的n-4个盒子共有$2^{n-4}$种情况，需要减去满足条件的$cnt \left ( n-4 \right ) $种方法。

故$cnt \left ( n \right )=2*cnt \left(n-1\right)+2^{n-4}-cnt\left(n-4\right) $。

以上讨论在`n>4`的条件下成立，其他情况需要单独讨论。

#### 源代码

```c
//NOJ T024
//20221024 by Lozumi
#include <stdio.h>
#include <math.h>

int cnt(int n);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",cnt(n));
    return 0;
}

int cnt(int n){
    if(n<3) 
	return 0;
    else if(n==3) 
	return 1;
    else if(n==4) 
	return 3;
    else
    	return 2*cnt(n-1)+pow(2,n-4)-cnt(n-4);
}

```

## 参考资料

[UVA 580 危险的组合 Critical Mass_cq_zry的博客-CSDN博客](https://blog.csdn.net/m0_66603329/article/details/126566260)

=EOF=