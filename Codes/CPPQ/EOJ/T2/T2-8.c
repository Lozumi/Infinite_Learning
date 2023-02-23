// EOJ T2-7
#include <stdio.h>

int main()
{
    int i = 0, j = 0, k = 0;
    scanf("%d %d", &i, &j);
    k = i % j;
    printf("Card No.%d was assigned to student 2022%03d.", i, k);
    return 0;
}