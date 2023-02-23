// NOJ T054 合并字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100], b[100];
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);
    strncat(a, b, 100);
    puts(a);
    return 0;
}