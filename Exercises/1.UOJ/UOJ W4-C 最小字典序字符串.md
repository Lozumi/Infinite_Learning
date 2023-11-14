> 西北工业大学ACM基地2022年大培训试题题解：第四周C题

## 问题描述

问N个字符串中字典序最小的字符串的编号是多少

字符串编号为1到N

#### 输入

第一行输入一个正整数N

接下来的N行每行一个字符串S

1<=N<=100

1<=|S|<=1000

#### 输出

输出字典序最小的字符串的编号，若有多个字符串符合条件，则将编号全部输出并且按照从小到大顺序输出

比如有两个符合条件则输出两行

#### 输入样例 1 

```
4
aa
ab
aa
cb
```

#### 输出样例 1

```
1
3
```

## 题解

利用string类函数compare()比较字典序。

**compare()函数**

>  [String.Compare 方法 (System) | Microsoft Learn](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0)

Basic_string 类模板既提供了 >、<、==、>=、<=、!= 等比较运算符，还提供了 compare() 函数，其中 compare() 函数支持多参数处理，支持用索引值和长度定位子串进行比较。该函数比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象，并返回一个指示二者在排序顺序中的相对位置的整数。

## 重载

| [Compare(String, Int32, String, Int32, Int32, CultureInfo, CompareOptions)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-int32-system-string-system-int32-system-int32-system-globalization-cultureinfo-system-globalization-compareoptions)) | 对两个指定 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象的子字符串进行比较，使用指定的比较选项和区域性特定的信息来影响比较，并返回一个整数，该整数指示这两个子字符串在排序顺序中的关系。 |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Compare(String, Int32, String, Int32, Int32, Boolean, CultureInfo)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-int32-system-string-system-int32-system-int32-system-boolean-system-globalization-cultureinfo)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象（其中忽略或考虑其大小写，并使用区域性特定的信息干预比较），并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, Int32, String, Int32, Int32, StringComparison)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-int32-system-string-system-int32-system-int32-system-stringcomparison)) | 使用指定的规则比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象的子字符串，并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, Int32, String, Int32, Int32, Boolean)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-int32-system-string-system-int32-system-int32-system-boolean)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象的子字符串（忽略或考虑其大小写），并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, Int32, String, Int32, Int32)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-int32-system-string-system-int32-system-int32)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象的子字符串，并返回一个指示二者在排序顺序中的相对位置的整数。 |
| [Compare(String, String)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-string)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象，并返回一个指示二者在排序顺序中的相对位置的整数。 |
| [Compare(String, String, Boolean, CultureInfo)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-string-system-boolean-system-globalization-cultureinfo)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象（其中忽略或考虑其大小写，并使用区域性特定的信息干预比较），并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, String, StringComparison)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-string-system-stringcomparison)) | 使用指定的规则比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象，并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, String, Boolean)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-string-system-boolean)) | 比较两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象（其中忽略或考虑其大小写），并返回一个整数，指示二者在排序顺序中的相对位置。 |
| [Compare(String, String, CultureInfo, CompareOptions)](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0#system-string-compare(system-string-system-string-system-globalization-cultureinfo-system-globalization-compareoptions)) | 对两个指定的 [String](https://learn.microsoft.com/zh-cn/dotnet/api/system.string?view=net-6.0) 对象进行比较，使用指定的比较选项和区域性特定的信息来影响比较，并返回一个整数，该整数指示这两个字符串在排序顺序中的关系。 |

## 注解

[Compare](https://learn.microsoft.com/zh-cn/dotnet/api/system.string.compare?view=net-6.0) 方法的所有重载返回一个 32 位有符号整数，指示两个比较数之间的词法关系。

| “值”   | 条件                                                 |
| :----- | :--------------------------------------------------- |
| 小于零 | 在排序顺序中，第一个子字符串在第二个子字符串之前。   |
| 零     | 子字符串在排序顺序中出现的位置相同或 `length` 为零。 |
| 大于零 | 第一个子字符串在排序顺序中后跟第二个子字符串。       |

**源代码**

```cpp
// UOJ W4-C
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string strc, strm;
    vector<string> sv;
    int n = 0;
    cin >> n;
    for (int i = 0; i <= n - 1; i++) //读取所有字符串
    {
        cin >> strc;
        sv.push_back(strc);
    }
    strm = sv[0];
    for (int i = 0; i <= n - 1; i++)
    {
        strc = sv[i];
        if (strm.compare(strc) > 0)
            strm = strc;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (strm == sv[i])
            cout << i + 1 << endl;
    }
    // cout << strc << endl;
    return 0;
}
```

**分析**

复杂度：空间 $O\left(n\right)$ 时间 $O\left(3n\right)

评测结果：时间 `5ms` 内存 `4MB`

**另解**

比较字符串的字典序有3种常用方法，分别使用`strcmp()` 函数、`compare()` 函数或比较预算符`<`。此处使用了第二种方法，其他方法可见下文。



## 参考资料

[字典序_兰亭落雪的博客-CSDN博客_字典序](https://blog.csdn.net/qq_37050329/article/details/86637183)