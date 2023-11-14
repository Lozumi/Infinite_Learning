// PSD1-Chap.6-2
#include <stdio.h>

void merge_array(int a[], int len_a, int b[], int len_b, int c[], int len_c);
void quick_sort(int a[], int l, int r);

int main(void)
{
    int a[] = {1, 1, 4, 5, 1, 4}, len_a = 6;
    int b[] = {1, 9, 1, 9, 8, 1, 0}, len_b = 7;
    int c[21] = {0}, len_c = 10;
    merge_array(a, len_a, b, len_b, c, len_c);
    return 0;
}

void merge_array(int a[], int len_a, int b[], int len_b, int c[], int len_c)
{
    for (int i = 0; i < len_a; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < len_b; i++)
    {
        c[len_a + i] = b[i];
    }
    quick_sort(c, 0, len_a + len_b - 1);
    for (int i = len_c; i <= len_a + len_b - 1; i++)
    {
        c[i] = '0';
    }
}

void quick_sort(int a[], int l, int r) //数组，低位，高位
{
    if (l < r)
    {
        int i, j, x;

        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while (i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, l, i - 1); /* 递归调用 */
        quick_sort(a, i + 1, r); /* 递归调用 */
    }
}
