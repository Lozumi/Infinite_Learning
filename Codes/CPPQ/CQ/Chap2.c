// Chapter 2
#include <stdio.h>

int main(void)
{
    int v1 = 1;
    unsigned int v2 = 1;
    short v3 = 1;
    unsigned short v4 = 1;
    char v5 = 1;
    unsigned char v6 = 1;
    long long n;
    scanf("%i", &n);
    v1 = n;
    v2 = n;
    v3 = n;
    v4 = n;
    v5 = n;
    v6 = n;
    printf("%d %d %d %d %d %d\n", v1, v2, v3, v4, v5, v6);
    printf("%04jX %04jX %04hX %04hX %04hhX %04hhX\n", v1, v2, v3, v4, v5, v6);
    return 0;
}
