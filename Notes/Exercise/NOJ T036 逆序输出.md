> 西北工业大学C程序设计基础NOJ T036

## description 

用递归法将一个长整型数 n 逆序输出。例如输入 483，输出 384。n 的位数不确定，可以是有效范围内的任意位数。

#### input 

输入为整数

#### output 

输出为整数

#### sample_input 

```c
4325879 
```

#### sample_output 

```c
9785234
```

## solution

#### solution a

使用动态数组依次存储字符，并逆序输出。

**源代码**

```cpp
// UOJ W2-B
// NOJ T036-a
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string num;
    cin >> num;
    vector<char> vnum;
    for (auto i : num)
    {
        vnum.push_back(i);
    }
    for (auto it = vnum.end() - 1; it >= vnum.begin(); it--)
    {
        cout << *it;
    }
    return 0;
}
```

（可以看到，其实是UOJ W2-B稍加修改得到的答案。0.0）

#### solution b

使用函数递归读取字符，并输出。终止递归的条件为：读取的字符为换行符(`\n`)。

**源代码**

```c
// NOJ T036-b
//函数递归方法
#include <stdio.h>
void get_num(void);

int main(void)
{
    get_num();
    return 0;
}

void get_num()
{
    char ch = getchar();
    if (ch != '\n')
        get_num();
    if (ch != '\n')
        printf("%c", ch);
}
```

=EOF=
