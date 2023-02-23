// NOJ T021-b
#include <stdio.h>

// str是 "abcde / fghij"
char str[12] = {'0', '0', '0', '0', '0', '/', '0', '0', '0', '0', '0', 0};

// 判断两个数是否满足要求 0~9一一对应
int is_vaild()
{
    int varr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 13; i++)
    {
        int cur = str[i] - '0';
        if (cur >= 0 && cur <= 9)
        {
            if (!varr[cur])
                return 0;
            varr[cur] = 0;
        }
    }
    return 1;
}

// 将整数ab转换成字符串
void to_str(int a, int b)
{
    int pos = 4;
    str[0] = str[8] = '0'; // 前导0
    while (pos >= 0 && a != 0)
    {
        str[pos--] = a % 10 + '0';
        a /= 10;
    }
    pos = 10;
    while (pos >= 6 && b != 0)
    {
        str[pos--] = b % 10 + '0';
        b /= 10;
    }
}

int main()
{
    int n = 0;
    int first = 1;
    scanf("%d", &n);
    // 打印恶心的空行
    if (!first)
        printf("\n");
    else
        first = 0;
    int cnt = 0;
    for (int b = 1000; b < 99999; b++)
    {
        int a = b * n;
        // a随b单调递增，所以当a超过了五位就可以退出了
        if (a > 99999)
            break;
        to_str(a, b);
        if (!is_vaild())
            continue;
        cnt++;
        printf("%s=%d\n", str, n);
    }
    if (cnt == 0)
    {
        printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
