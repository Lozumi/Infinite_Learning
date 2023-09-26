#include <stdio.h>

int isWin(int a)
{
    int dp[a + 1];
    dp[0] = 0;

    for (int i = 1; i <= a; i++)
    {
        if ((i >= 1 && !dp[i - 1]) || (i >= 2 && !dp[i - 2]) || (i >= 3 && !dp[i - 3]))
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    return dp[a];
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