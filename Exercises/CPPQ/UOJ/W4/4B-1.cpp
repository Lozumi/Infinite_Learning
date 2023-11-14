// UOJ W4-B-1
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main(void)
{
    // int t1 = clock();
    string sMain, sVice, sViceNow;
    int sumNow = 0, sumMax = 0;
    bool flagS = 0;
    vector<char> sVMain;
    //读取总字符串
    cin >> sMain;
    for (auto i : sMain)
    {
        sVMain.push_back(i);
    }
    //遍历创建子串
    int nMain = sVMain.size();       //查询总字符串长度
    for (int i = 1; i <= nMain; i++) //固定子串长度(步长)i
    {
        for (int j = 0; j <= nMain - i; j++) //确定开始位置j
        {
            sVice = "";
            for (int k = j; k <= j + i - 1; k++) //从确定位置进行固定长度的遍历  j~j+i-1
            {
                sVice.push_back(sVMain[k]); //字符读入字符串
            }

            //已经创建子串，随后计数
            sumNow = 0;
            for (int l = 0; l <= nMain - i; l++) //遍历固定步长的所有子串
            {
                sViceNow = "";
                for (int m = l; m <= l + i - 1; m++)
                {
                    sViceNow.push_back(sVMain[m]);
                }
                if (sVice == sViceNow)
                {
                    sumNow++;
                }
            }
            if (sumNow >= sumMax)
                sumMax = sumNow;
        }
    }
    cout << sumMax << endl;
    // int t2 = clock();
    // cout << t2 - t1 << endl;
    return 0;
}