#include <stdio.h>

int isWin(int a)
{
    if (a <= 0)
    {
        return 0;
    }

    if (!isWin(a - 1) || !isWin(a - 2) || !isWin(a - 3))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    if (isWin(a))
        printf("true:水之源启动!");
    else
        printf("false:大输特输");
    return 0;
}