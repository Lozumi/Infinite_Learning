> 西北工业大学ACM基地2022年大培训试题题解：第四周B题

# 子串个数

## 问题描述

给定一个字符串S

问出现次数最多的子串的出现次数是多少

（子串：若干个连续的元素）

#### 输入

输入为一行，字符串S

S均由小写字母组成

1<=|S|<=100000

#### 输出

输出为1个整数

#### 输入样例 1

```
ababc
```

#### 输出样例 1

```
2
```

#### 提示

该字符串的所有子串有：a,b,c,ab,ba,bc,aba,bab,abc,abab,babc,ababc

出现次数分别是2 2 1 2 1 1 1 1 1 1 1 1

## 题解

#### 解法1

遍历总字符串的所有子串，并分别计数。最后取其中最大的次数输出。

读入总字符串并存入动态数组后有两种形式。一是将子串转化为动态数组后，对齐比较；二是将总字符串转化为子串后，字典比较。

A题使用了思路一，故本题使用思路二。

**源代码**

```cpp
// UOJ W4-B-1
#include <iostream>
#include <vector>
#include <string>
//#include <ctime>

using namespace std;

int main(void)
{
    // int t1 = clock();
    string sMain, sVice, sViceNow;
    int sumNow = 0, sumMax = 0;
    bool flagS = 0;
    vector<char> sVMain;
    //读取总字符串
    cin >> sMain;
    for (auto i : sMain)
    {
        sVMain.push_back(i);
    }
    //遍历创建子串
    int nMain = sVMain.size();       //查询总字符串长度
    for (int i = 1; i <= nMain; i++) //固定子串长度(步长)i
    {
        for (int j = 0; j <= nMain - i; j++) //确定开始位置j
        {
            sVice = "";
            for (int k = j; k <= j + i - 1; k++) //从确定位置进行固定长度的遍历  j~j+i-1
            {
                sVice.push_back(sVMain[k]); //字符读入字符串
            }

            //已经创建子串，随后计数
            sumNow = 0;
            for (int l = 0; l <= nMain - i; l++) //遍历固定步长的所有子串
            {
                sViceNow = "";
                for (int m = l; m <= l + i - 1; m++)
                {
                    sViceNow.push_back(sVMain[m]);
                }
                if (sVice == sViceNow)
                {
                    sumNow++;
                }
            }
            if (sumNow >= sumMax)
                sumMax = sumNow;
        }
    }
    cout << sumMax << endl;
    // int t2 = clock();
    // cout << t2 - t1 << endl;
    return 0;
}
```

**分析**

空间复杂度为$O\left(n^{2}\right)$，样例执行时间`1671ms`。太慢了~

#### 解法2

引入string类，使用`substr`函数提取子串。由此不再使用动态数组，直接使用字符串操作。

用法为`int i = string.str(start_place,length)`。

**源代码**

```cpp
// UOJ W4-B-2
//引入string类函数代替手写轮子
#include <iostream>
#include <string>
//#include <ctime>

using namespace std;

int main(void)
{
    //    int t1 = clock();
    string sMain, sVice, sViceNow;
    int sumNow = 0, sumMax = 0;
    bool flagS = 0;
    //读取总字符串
    cin >> sMain;
    int nMain = sMain.size();        //查询总串长度
    for (int i = 1; i <= nMain; i++) //固定子串长度(步长)i
    {
        for (int j = 0; j <= nMain - i; j++) //确定开始位置j
        {
            sVice = sMain.substr(j, i);

            //已经创建子串，随后计数
            sumNow = 0;
            for (int l = 0; l <= nMain - i; l++) //遍历固定步长的所有子串
            {
                sViceNow = sMain.substr(l, i);
                if (sVice == sViceNow)
                {
                    sumNow++;
                }
            }
            if (sumNow >= sumMax)
                sumMax = sumNow;
        }
    }

    cout << sumMax << endl;
    //    int t2 = clock();
    //    cout << t2 - t1 << endl;
    return 0;
}
```

**分析**

空间复杂度为$O\left(n^{2}\right)$，样例执行时间`1085ms`。还是太慢了~

#### 解法3

引理：一个字符串出现的次数不会比他的子串多。

故只需统计字符出现个数，并输出最大者。将26个字母的次数用数组记录，并快速排序得到最大者。

```cpp
// UOJ W4-B-3
//简化为字符数量统计
#include <iostream>
#include <string>
//#include <ctime>

using namespace std;
void quick_sort(int a[], int l, int r);

int main(void)
{
    // int t1 = clock();

    string str;
    getline(cin, str);
    // transform(str.begin(), str.end(), str.begin(), ::tolower); //将所有字母转为小写

    int cnt[26] = {};
    for (int i = 0; i < str.size(); i++)
    {
        cnt[(int)str[i] - 'a']++;
    }
    quick_sort(cnt, 0, 25);
    cout << cnt[25] << endl;

    // int t2 = clock();
    // cout << t2 - t1 << endl;
    return 0;
}

void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int i, j, x;

        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while (i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, l, i - 1); /* 递归调用 */
        quick_sort(a, i + 1, r); /* 递归调用 */
    }
}
```

**分析**

空间复杂度为$O\left(nlogn\right)$，样例执行时间`568ms`。成功辣！