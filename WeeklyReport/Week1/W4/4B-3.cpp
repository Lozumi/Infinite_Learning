// UOJ W4-B-3
//简化为字符数量统计
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
void quick_sort(int a[], int l, int r);

int main(void)
{
    int t1 = clock();

    string str;
    getline(cin, str);
    // transform(str.begin(), str.end(), str.begin(), ::tolower); //将所有字母转为小写

    int cnt[26] = {};
    for (int i = 0; i < str.size(); i++)
    {
        cnt[(int)str[i] - 'a']++;
    }
    quick_sort(cnt, 0, 25);
    cout << cnt[25] << endl;

    int t2 = clock();
    cout << t2 - t1 << endl;
    return 0;
}

void quick_sort(int a[], int l, int r)
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