// UOJ W3-H
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n = 0, m = 0, temp = 0, tn = 0; // n人数，m初始位置，temp读取暂存，tn本轮位置
    vector<int> key;
    cin >> n >> m;
    tn = m;

    while (cin >> temp) //读取密码
    {
        key.push_back(temp);
    }

    auto it = key.begin();
    for (int i = 1; i <= n; i++)
    {
        tn = m / n; //确定本轮出线位置
        it = it + tn - 1;
        if (i != 1)
            m = *it; //寻找下一轮密码
        it = key.erase(it);
        cout << tn << " ";
    }
    return 0;
}
