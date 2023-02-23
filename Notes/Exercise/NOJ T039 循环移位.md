> 西北工业大学C程序设计基础NOJ T038

## description 

编写函数实现 value 左右循环移位（即移出的位在另一端填入）。函数原型为 int move(int value,int n)；其中 value 为要循环移位的数，n 为移位的位数，n 的绝对值不大于 16，整型为 16 位。如果 n＜0 表示左移，n＞0 表示右移，n=0 表示不移位。在主函数中输入数据并调用该函数输出结果。

#### input 

输入 value 和 n，均为整型，用空格隔开

#### output

移位后的结果

#### sample_input 

```c
134744064 -8 
```

#### sample_output 

```c
134742024 
```

## solution

本题对数字串进行处理，可以使用移位操作符。方法参考NOJ T036。

插入文章。

```c
// NOJ T039.c
#include <stdio.h>
int move(int value, int n)
{
    if (n == 0)
        return value;
    else if (n < 0)
    {
        n = -n;
        value = (value << n) | (value >> (32 - n));
    }
    else
        value = (value >> n) | (value << (32 - n));
    return value;
}

int main()
{
    int value, n;
    scanf("%d %d", &value, &n);
    value = move(value, n);
    printf("%d", value);
    return 0;
}
```

