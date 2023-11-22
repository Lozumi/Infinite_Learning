#include <stdio.h>
#include <string.h>
int Maxlen;
char a[110], b[110];
int an1[110], an2[110];
int Addition(int maxlen, int an1[], int an2[]);
int main()
{
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
    memset(an1, 0, sizeof(an1));
    memset(an2, 0, sizeof(an2));
    int len1 = strlen(a);
    int len2 = strlen(b);
    if (len1 > len2)
        Maxlen = len1;
    Maxlen = len2;
    for (j = 0, i = strlen(a) - 1; i >= 0; i--)
        an1[j++] = a[i] - '0';
    for (j = 0, i = len2 - 1; i >= 0; i--)
        an2[j++] = b[i] - '0';
    Addition(Maxlen, an1, an2);
    for (i = 100; i >= 0; i--)
    {
        if (an1[i] != 0)
            break;
    }
    for (; i >= 0; i--)
        printf("%d", an1[i]);
    printf("\n");
}
int Addition(int maxlen, int an1[], int an2[]) // 大数相加函数
{
    for (int i = 0; i < maxlen; i++)
    {
        an1[i] += an2[i];
        if (an1[i] >= 10)
        {
            an1[i] -= 10;
            an1[i + 1]++;
        }
    }
    return 0;
}