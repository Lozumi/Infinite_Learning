// UOJ W4-B-2
//引入string类函数代替手写轮子
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(void)
{
    int t1 = clock();
    string sMain, sVice, sViceNow;
    int sumNow = 0, sumMax = 0;
    bool flagS = 0;
    //读取总字符串
    cin >> sMain;
    int nMain = sMain.size();        //查询总串长度
    for (int i = 1; i <= nMain; i++) //固定子串长度(步长)i
    {
        for (int j = 0; j <= nMain - i; j++) //确定开始位置j
        {
            sVice = sMain.substr(j, i);

            //已经创建子串，随后计数
            sumNow = 0;
            for (int l = 0; l <= nMain - i; l++) //遍历固定步长的所有子串
            {
                sViceNow = sMain.substr(l, i);
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
    int t2 = clock();
    cout << t2 - t1 << endl;
    return 0;
}