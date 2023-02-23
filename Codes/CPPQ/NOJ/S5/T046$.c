// NOJ T046 插入排序
#include <stdio.h>
#include <stdlib.h>
void join_sort(int num[], int s, int m)
{
    int i, k, t;
    for (i = s + 1; i <= s + m - 1; i++)
    {
        t = num[i];
        k = i - 1;
        while (t > num[k])
        {
            num[k + 1] = num[k];
            k--;
            if (k == s - 1)
                break;
        }
        num[k + 1] = t;
    }
}
int main()
{
    int num[100], n, i, s, m;
    scanf("%d", &n);
    m = n;
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    scanf("%d%d", &s, &m);
    join_sort(num, s, m);
    for (i = 0; i < n; i++)
        printf("%d ", num[i]);
    return 0;
}