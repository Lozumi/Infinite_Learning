// NOJ T033
//利用移位操作符 <<
#include <stdio.h>

int main(void)
{
    int n = 0, bit = 0;
    scanf("%d %d", &n, &bit);
    if (n & (1 << (bit - 1)))
        printf("1");
    else
        printf("0");
    return 0;
}