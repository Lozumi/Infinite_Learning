#include <stdio.h>
int main()
{
    int i, j, a, b, c, d, e;
    scanf("%d %d", &i, &j);
    a = i + j;
    b = i - j;
    c = i * j;
    d = i / j;
    e = i % j;
    printf("%d+%d=%d\n", i, j, a);
    printf("%d-%d=%d\n", i, j, b);
    printf("%d*%d=%d\n", i, j, c);
    printf("%d/%d=%d\n", i, j, d);
    printf("%d%%%d=%d\n", i, j, e);
    return 0;
}