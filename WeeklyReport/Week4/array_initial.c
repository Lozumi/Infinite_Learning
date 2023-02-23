// 测试size of array[]
#include <stdio.h>

int main(void)
{
    int days[] = {1, 2, 3, 4, 5};
    printf("%d %d", sizeof days, sizeof days[1]);
    return 0;
}