>  西北工业大学C程序设计基础NOJ T021
>
> 本题来自**UVa725 除法 Division**

## description 

输入正整数 n，按从小到大的顺序输出所有形如 abcde/fghij=n 的表达式，其中 a～j 恰好为数字 0～9 的一个排列，2≤n≤79。

#### input 

输入正整数 n 

#### output 

输出形如 abcde/fghij=n 的表达式，每行一个

#### sample_input 

```c
62
```

#### sample_output 

```c
79546/01283=62 

94736/01528=62 
```

## solution

**思路**

首先题目中要求a~j是数字0~9的一个排列，这说明这些数字不能重复出现，0~9恰好都出现且仅出现一次。这是我出错的地方。

还有，不用枚举所有可能的分子和分母，判断是否符合规则并且相除等于n，这样所需要的时间复杂度是$O\left(n2\right)$，要做大概$10^{8}$次循环。简言之就是利用我们已知的n来减少循环次数。

我们可以把等式变形，$abcde=n*fghij$，然后我们只需要枚举fghij就能得到abcde然后判断两个数是否符合规则即可。复杂度降到了线性时间，需要做不到$10^{4}$循环。

##### solA

```c
// NOJ T021-a
#include <stdio.h>
//#include <time.h>
int main()
{
    int abcde, fghij, n;
    int a, f, r, i, duplicate;
    int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    long beginTime, endTime;
    scanf("%d", &n);
    // beginTime = clock();
    for (abcde = 1234; abcde <= 98765; abcde++)
    {
        n0 = n1 = n2 = n3 = n4 = n5 = n6 = n7 = n8 = n9 = 0;
        a = abcde;
        duplicate = 0;
        for (i = 0; i < 5; i++)
        {
            r = a % 10;
            switch (r)
            {
            case 0:
                if (n0 > 0)
                    duplicate = 1;
                else
                    n0++;
                break;
            case 1:
                if (n1 > 0)
                    duplicate = 1;
                else
                    n1++;
                break;
            case 2:
                if (n2 > 0)
                    duplicate = 1;
                else
                    n2++;
                break;
            case 3:
                if (n3 > 3)
                    duplicate = 1;
                else
                    n3++;
                break;
            case 4:
                if (n4 > 0)
                    duplicate = 1;
                else
                    n4++;
                break;
            case 5:
                if (n5 > 0)
                    duplicate = 1;
                else
                    n5++;
                break;
            case 6:
                if (n6 > 0)
                    duplicate = 1;
                else
                    n6++;
                break;
            case 7:
                if (n7 > 0)
                    duplicate = 1;
                else
                    n7++;
                break;
            case 8:
                if (n8 > 0)
                    duplicate = 1;
                else
                    n8++;
                break;
            case 9:
                if (n9 > 0)
                    duplicate = 1;
                else
                    n9++;
                break;
            }
            if (duplicate == 1)
            {
                break;
            }
            else
            {
                a = a / 10;
            }
        }
        if (duplicate == 1)
        {
            continue;
        }
        fghij = n * abcde;
        if (fghij <= 98765)
        {
            f = fghij;
            for (i = 0; i < 5; i++)
            {
                r = f % 10;
                switch (r)
                {
                case 0:
                    if (n0 > 0)
                        duplicate = 1;
                    else
                        n0++;
                    break;
                case 1:
                    if (n1 > 0)
                        duplicate = 1;
                    else
                        n1++;
                    break;
                case 2:
                    if (n2 > 0)
                        duplicate = 1;
                    else
                        n2++;
                    break;
                case 3:
                    if (n3 > 3)
                        duplicate = 1;
                    else
                        n3++;
                    break;
                case 4:
                    if (n4 > 0)
                        duplicate = 1;
                    else
                        n4++;
                    break;
                case 5:
                    if (n5 > 0)
                        duplicate = 1;
                    else
                        n5++;
                    break;
                case 6:
                    if (n6 > 0)
                        duplicate = 1;
                    else
                        n6++;
                    break;
                case 7:
                    if (n7 > 0)
                        duplicate = 1;
                    else
                        n7++;
                    break;
                case 8:
                    if (n8 > 0)
                        duplicate = 1;
                    else
                        n8++;
                    break;
                case 9:
                    if (n9 > 0)
                        duplicate = 1;
                    else
                        n9++;
                    break;
                }
                if (duplicate == 1)
                {
                    break;
                }
                else
                {
                    f = f / 10;
                }
            }
            if (!duplicate)
            {
                printf("%05d/%05d=%d\n", fghij, abcde, n);
            }
        }
    }
    // endTime = clock();
    //  printf("Elapsed time: %ldms\n", (endTime - beginTime));
    return 0;
}
```

无法通过评测，问题未知。

##### solB

```c
//NOJ T021-b
#include <stdio.h>

// str是 "abcde / fghij"
char str[14] = { '0','0','0','0','0',' ','/',' ','0','0','0','0','0',0 };

// 判断两个数是否满足要求
bool is_vaild() {
	int varr[] = { 1,1,1,1,1,1,1,1,1,1 };
    for (int i = 0; i < 13; i++) {
		int cur = str[i]- '0';
        if (cur >= 0 && cur <= 9) {
			if (!varr[cur])return false;
			varr[cur] = 0;
        }
    }
    return true;
}

// 将整数ab转换成字符串
void to_str(int a, int b) {
    int pos = 4;
    str[0] =str[8]= '0'; // 前导0
    while (pos >= 0 && a != 0) {
        str[pos--] = a % 10 + '0'; a /= 10;
    }
    pos = 12;
    while (pos >= 8 && b != 0) {
        str[pos--] = b % 10 + '0'; b /= 10;
    }
}

int main() {
    int n;
    bool first = true;
    while (scanf("%d", &n) != EOF && n!=0) {
        // 打印恶心的空行
        if (!first)printf("\n");
        else first = false;
        int cnt = 0;
        for (int b = 1000; b < 99999; b++) {
            int a = b * n;
            // a随b单调递增，所以当a超过了五位就可以退出了
            if (a > 99999)break;
            to_str(a, b);
            if (!is_vaild()) continue;
            cnt++;
            printf("%s = %d\n", str, n);
        }
        if (cnt == 0) {
            printf("There are no solutions for %d.\n", n);
        }
    }
    return 0;
}

```

测试通过。