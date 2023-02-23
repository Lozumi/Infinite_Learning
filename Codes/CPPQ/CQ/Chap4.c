#include <stdio.h>
int i;
int fact(int n)
{
    int static level = 0;
    if (++level > 2)
        return 1;
    if (n > 1)
        return n * fact(n - 1);
    else
        return 1;
}
int main(void)
{
    int x, y;
    x = fact(4);
    y = fact(4);
    printf("%d,%d,%d", x, y, i);
    return 0;
}