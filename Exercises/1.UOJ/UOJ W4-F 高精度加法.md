> 西北工业大学ACM基地2022年大培训试题题解：第四周F题

## 问题描述

给两个数字 a , b,求出a+b，其中(1&lt;= a,b&lt;=10^{500} )(1<=*a*,*b*<=10500)。（本题请使用C/C++编程，只用py的同学可以忽略本题）

#### 输入

输入为两行，分别为数字 a 和 b

#### 输出

输出为一行，计算后的结果

#### 输入样例 1 

```
10011
20022
```

#### 输出样例 1

```
30033
```

## 题解

#### 题解1

因数据超出数据类型所能储存的最大值，利用整型直接计算会产生数值溢出导致结果错误。常规思路是使用数组，模拟加法对每位的数进行运算。

#### 题解2

开数组时，只能预先确定维度大小。为了使维度和当前运算相适应，节省时空，将数组改为动态数组。

**源代码**

```cpp
// UOJ W4-F-2
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    if (A.size() < B.size())
        return add(B, A);

    int r = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        r += A[i];
        if (i < B.size())
            r += B[i];
        C.push_back(r % 10);
        r /= 10;
    }
    if (r)
        C.push_back(r);

    return C;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> A, B;
    string a, b;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i)
        B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];

    return 0;
}

```

**分析**

复杂度：空间 $O\left(n\right)$，时间 $O\left(4n\right)

评测结果：时间: `4ms` 内存: `4MB`