// 测试size of array[]
#include <stdio.h>

int main(void)
{
    int days[] = {1, 2, 3, 4, 5};
    printf("%d %d", sizeof days, sizeof days[1]);
    int arr1[4][5] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4}}; // 正确而完整
    return 0;
}