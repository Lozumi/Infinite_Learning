#include <stdio.h>

int count4(int num)
{
    int count = 0;

    while (num != 0)
    {
        int digit = num % 10;
        if (digit == 4)
        {
            count++;
        }
        num /= 10;
        }
    return count;
}

int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int allCount = 0;
    for (int i = a; i <= b; i++)
    {
        allCount += count4(i);
    }
    printf("%d", allCount);
    return 0;
}