// NOJ T024
#include <stdio.h>
#include <math.h>

int cnt(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", cnt(n));
    return 0;
}

int cnt(int n)
{
    if (n < 3)
        return 0;
    else if (n == 3)
        return 1;
    else if (n == 4)
        return 3;
    else
        return 2 * cnt(n - 1) + pow(2, n - 4) - cnt(n - 4);
}
