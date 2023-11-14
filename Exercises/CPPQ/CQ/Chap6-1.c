// PSD1-Chap.6-1
#include <stdio.h>

void count_dup(int c[], int len_c);

int main(void)
{
    int c[] = {1, 1, 2, 3, 2, 4};
    int len_c = sizeof(c) / sizeof(c[0]);
    count_dup(c, len_c);
    return 0;
}

void count_dup(int c[], int len_c)
{
    int cnt[11] = {0};
    for (int i = 0; i < len_c; i++)
    {
        cnt[c[i]]++;
    }
    for (int j = 0; j < 10; j++)
    {
        if (cnt[j] > 1)
        {
            printf("%d: %d times\n", j, cnt[j]);
        }
    }
}