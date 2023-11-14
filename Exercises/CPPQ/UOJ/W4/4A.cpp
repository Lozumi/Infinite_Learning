// UOJ W4-A
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string sMain, sVice;
    int n = 0;
    bool flagS = 0;
    vector<char> sVMain, sVVice;
    cin >> sMain;
    for (auto i : sMain) //读取总字符串
    {
        sVMain.push_back(i);
    }
    cin >> n; //读取数字
    // cout << "Len of sVec:" << sVMain.size() << endl;
    while (cin >> sVice)
    {
        sVVice.clear(); //清空子动态数组
        // cout << sVice;
        for (auto i : sVice) //读取字符串
        {
            sVVice.push_back(i);
        }
        int nMain = (int)sVMain.size(); //动态数组维度是无符号整型，小心越界！
        int nVice = (int)sVVice.size();
        for (int i = 0; i <= nMain - nVice + 1 - 1; i++) //从sVMain
        {
            flagS = 1; //字符相同性标识
            for (int j = 0; j <= nVice - 1; j++)
            {
                if (sVVice[j] != sVMain[i + j]) //判断单个字符
                    flagS = 0;                  //不相同
            }
            if (flagS == 1) //存在子串就跳出
                break;
        }
        if (flagS == 1) //全部字符相同
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}