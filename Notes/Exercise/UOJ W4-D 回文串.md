>  西北工业大学ACM基地2022年大培训试题题解：第四周B题

## 问题描述

给定一个字符串S，判断其是否为回文串

（回文串：正着读和反着读一样）

#### 输入

输入为1行，字符串S

1<=|S|<=100000

S均由小写字母组成

#### 输出

输入为1行，若是回文串，则输出YES，否则输出NO

#### 输入样例 1 

```
aabaa
```

#### 输出样例 1

```
YES
```

## 题解

#### **解法１**

利用char c，逐个字符读入字符串，并存入动态数组。正反验证。

**源代码**

```cpp
// UOJ W4-D
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    char c;
    vector<char> cv;
    bool flag = 1;
    while (c = getchar()) //读取字符串
    {
        if (c == '\0')
            break;
        else
            cv.push_back(c);
    }

    for (int i = 0; i <= (cv.size() + 1) / 2; i++)
    {
        if (cv[i] != cv[cv.size() - 1 - i])
            flag = 0;
    }
    if (flag == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
```



**分析**

Windows运行正常。

OJ运行时错误。

#### **解法2**

将char c改为string c，一次性读入字符串，并存入动态数组。正反验证。

**源代码**

```cpp
// UOJ W4-D
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string c;
    cin >> c;
    vector<char> cv;
    bool flag = 1;
    for (auto i : c)
    {
        cv.push_back(i);
    }

    for (int i = 0; i <= (cv.size() + 1) / 2; i++)
    {
        if (cv[i] != cv[cv.size() - 1 - i])
            flag = 0;
    }
    if (flag == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
```

**分析**

Windows运行正常。

OJ运行正常。

## ## 总结

UOJ系统的输入**不包含回车**，无法以'\n'作为结束标志，字符串结尾没有'\0'。

如何利用解法1过OJ待查。