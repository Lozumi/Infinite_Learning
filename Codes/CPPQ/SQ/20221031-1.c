// PSD1 20221031
#include <stdio.h>

int func(int, int);

int main(void)
{
    int a = 1, b = 2;
    printf("%d", func(a, b));
    return 0;
}

int func(int x, int y)
{
    return x + y;
}