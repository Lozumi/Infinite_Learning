// UOJ W4-C-1b
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string strc, strm;
    vector<string> sv;
    int n = 0;
    cin >> n;
    for (int i = 0; i <= n - 1; i++) //读取所有字符串
    {
        cin >> strc;
        sv.push_back(strc);
    }
    strm = sv[0];
    for (int i = 0; i <= n - 1; i++)
    {
        strc = sv[i];
        if (strm.compare(strc) > 0)
            strm = strc;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (strm == sv[i])
            cout << i + 1 << endl;
    }
    // cout << strc << endl;
    return 0;
}