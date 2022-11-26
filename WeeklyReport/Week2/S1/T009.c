// NOJ T009
#include <stdio.h>

int main(void)
{
    int a = 0;
    scanf("%d", &a);
    switch (a / 10)
    {
    case 9:
        printf("A");
        break;
    case 8:
        printf("B");
        break;
    case 7:
        printf("C");
        break;
    case 6:
        printf("D");
        break;
    default:
        printf("E");
        break;
    }
    return 0;
}