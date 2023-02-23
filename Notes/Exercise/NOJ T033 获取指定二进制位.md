> 西北工业大学C程序设计基础NOJ T033
>

## description 

编写函数 getbit(n,k)；求出 n 从右边开始的第 k 位。在主函数中输入数据并调用该函

数输出结果。

#### input 

输入整型 n 和 k（1≤k≤16），用空格分隔。

#### output 

输出整型。

#### sample_input 

```c
128 8
```

#### sample_output 

```c
1
```

## solution

思路见下文。

**源代码**

```c
// NOJ T033
//利用移位操作符 <<
#include <stdio.h>

int main(void)
{
    int n = 0, bit = 0;
    scanf("%d %d", &n, &bit);
    if (n & (1 << (bit - 1)))
        printf("1");
    else
        printf("0");
    return 0;
}
```

