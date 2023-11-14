#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = '\xFE' + 1;
    printf("%d", a);
}