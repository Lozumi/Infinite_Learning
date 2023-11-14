> 本文转载自CSDN博主「J先生的编程笔记」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
> 原文链接：https://blog.csdn.net/qq_38943651/article/details/108302229

## 1 strcmp()

在 C 语言中，我们可以使用 strcmp() 函数比较 char* 类型字符串的字典序。

当字符串 s1 的字典序小于字符串 s2 的字典序时，返回值 < 0。
当字符串 s2 的字典序大于字符串 s1 的字典序时，返回值 > 0。
当字符串 s1 的字典序等于字符串 s2 的字典序时，返回值 = 0。

```cpp
#include <iostream>
using namespace std;

int main() {
	char s1[2] = "a";
	char s2[2] = "b";
	cout << strcmp(s1, s2) << endl;	//-1
	cout << strcmp(s2, s1) << endl;	//1
	cout << strcmp(s1, s1) << endl;	//0
	return 0;
}
```

## 2 string.compare()

在 C++ 中，我们可以使用 compare() 函数比较 char* 类型和 string 类型字符串的字典序。compare() 函数和 strcmp() 函数的返回值相同。

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "a";
	string s2 = "b";
	cout << s1.compare(s2) << endl;	//-1
	cout << s2.compare(s1) << endl;	//1
	cout << s1.compare(s1) << endl;	//0
	return 0;
}
```

## 3 比较运算符

在 C++ 中，我们还可以使用比较运算符比较 char* 类型和 string 类型字符串的字典序，注意使用比较运算符比较 char* 类型字符串时，需要将 char* 类型强制转换为 string 类型，否则比较的则是字符串的起始地址。

```cpp
#include <iostream>
using namespace std;

int main() {
	char s1[2] = "a";
	char s2[2] = "b";
	cout << (s1 < s2) << endl;	//0
	cout << &s1 << endl;		//00BDFE74
	cout << &s2 << endl;		//00BDFE68
	cout << (string(s1) < string(s2)) << endl;	//1
	cout << (string(s2) < string(s1)) << endl;	//0
	cout << (string(s1) == string(s1)) << endl;	//1
	return 0;
}
```

=EOF=