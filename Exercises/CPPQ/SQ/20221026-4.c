#include <stdio.h>

int main()

{

    char i = 127;

    unsigned char b = 4;

    unsigned int c = 4;

    ++i;

    if (i < b)

        printf("0:");

    else if (i == b)

        printf("1:");

    else

        printf("-1:");

    if (i < c)

        printf("0");

    else if (i == c)

        printf("1");

    else

        printf("-1");

    return 0;
}