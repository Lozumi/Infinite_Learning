// UOJ W4-P
//简化为字符数量统计
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
void quick_sort(int a[], int l, int r);

int main(void)
{
    // int t1 = clock();
    string str;
    getline(cin, str);
    // transform(str.begin(), str.end(), str.begin(), ::tolower); //将所有字母转为小写

    int cnt[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        cnt[(int)str[i] - 'a']++;
    }
    // quick_sort(cnt, 0, 25);
    //  cout << cnt[25] << endl;

    cout << cnt['x' - 'a'] << endl;
    int t2 = clock();
    // cout << t2 - t1 << endl;
    return 0;
}
