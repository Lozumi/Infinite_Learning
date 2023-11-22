#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 功能：实现两个大数减法运算
// 参数：source1--被减数
//       source2--减数
//       result --计算结果
// 返回值：计算结果为正数，返回'+'，否则返回'-'
char Minus(char *source1, char *source2, char *result)
{
    int length1 = strlen(source1); // 被减数的长度
    int length2 = strlen(source2); // 减数的长度
    int i, j, k = 0;
    int temp;    // 临时存放位相减的结果
    int bit = 0; // 借位，1表示需要借位，0表示不需要借位
    char ch;     // 用于交换

    for (i = length1 - 1, j = length2 - 1; i >= 0 && j >= 0; --i, --j)
    {
        // 计算两个位之间的差值，同时要考虑借位
        temp = (source1[i] - '0') - (source2[j] - '0') - bit;

        if (temp < 0) // 需要借位
        {
            bit = 1;
            result[k++] = temp + 10 + '0';
        }
        else // 不需要借位
        {
            bit = 0;
            result[k++] = temp + '0';
        }
    }

    while (i >= 0) // length1 > length2的情况，结果为正数，将剩余数据赋值给计算结果数组
    {
        temp = source1[i--] - '0' - bit;
        if (temp < 0) // 需要借位
        {
            bit = 1;
            result[k++] = temp + 10 + '0';
        }
        else
        {
            bit = 0;
            result[k++] = temp + '0';
        }
    }

    while (j >= 0) // length1 < length2的情况，结果为负数，将剩余数据赋值给计算结果数组
    {
        temp = 10 - bit - (source2[j--] - '0');
        result[k++] = temp + '0';
    }

    // 对仍有进位的情况考虑，主要分两种：一种是strlen(p1)<strlen(p2),另一种是p1-p2<0，这两种情况bit为1
    if (bit == 1)
    {
        // 最低位肯定不会被借位，所以不需要减去借位
        // 只会向高位借位
        result[0] = 10 - (result[0] - '0') + '0';
        for (i = 1; i < k; i++)
        {
            result[i] = 10 - (result[i] - '0') - bit + '0';
        }
    }

    for (i = k - 1, j = 0; i >= j; --i, ++j)
    {
        ch = result[i];
        result[i] = result[j];
        result[j] = ch;
    }
    result[k] = '\0';

    if (bit == 1)
    {
        return '-';
    }
    else
    {
        return '+';
    }
}

int main()
{
    char source1[1000];
    char source2[1000];
    char result[1001];
    char op;

    scanf("%s%s", source1, source2);
    op = Minus(source1, source2, result);
    if (op == '-')
    {
        printf("-");
    }
    printf("%s\n", result);

    return 0;
}