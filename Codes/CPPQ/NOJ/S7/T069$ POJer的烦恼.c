#include <stdio.h>
int main()
{
    int i = 0, n, a[32];
    scanf("%d", &n);
    while (n > 0)
    {
        a[i] = n % 2;
        i = i + 1;
        n = n / 2;
    }
    for (i--; i >= 0; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}