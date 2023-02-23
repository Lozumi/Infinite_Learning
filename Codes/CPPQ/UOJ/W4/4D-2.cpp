// UOJ W4-D
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string c;
    cin >> c;
    vector<char> cv;
    bool flag = 1;
    for (auto i : c)
    {
        cv.push_back(i);
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