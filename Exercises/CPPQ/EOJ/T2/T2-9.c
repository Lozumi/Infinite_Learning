// EOJ T2-9
#include <stdio.h>

int main(void)
{
    int n, a, b, c, m;
    scanf("%d", &n);
    switch (n % 12)
    {
    case (1):
    case (2):
    case (3):
    case (4):
    case (5):
        printf("第%d盏灯是红色。\n", n);
        break;
    case (6):
    case (7):
    case (8):
    case (9):
        printf("第%d盏灯是蓝色。\n", n);
        break;
    case (10):
    case (11):
    case (0):
        printf("第%d盏灯是黄色。\n", n);
        break;
    }
    m = n % 12;
    n = n / 12;
    if (m <= 5)
    {
        a = n * 5 + m;
        b = n * 4;
        c = n * 3;
    }
    else if (m > 5 && m <= 9)
    {
        a = (n + 1) * 5;
        b = n * 4 + (m - 5);
        c = n * 3;
    }
    else if (m > 9)
    {
        a = (n + 1) * 5;
        b = (n + 1) * 4;
        c = n * 3 + (m - 9);
    }
    printf("共有红灯%d盏、蓝灯%d盏、黄灯%d盏。", a, b, c);
    return 0;
}