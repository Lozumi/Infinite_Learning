// UOJ W4-D
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    char c;
    vector<char> cv;
    bool flag = 1;
    while (c = getchar()) //读取字符串
    {
        if (c == '\0')
            break;
        else
            cv.push_back(c);
    }

    for (int i = 0; i <= (cv.size() + 1) / 2; i++)
    {
        if (cv[i] != cv[cv.size() - 1 - i])
            flag = 0;
    }
    if (flag == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}