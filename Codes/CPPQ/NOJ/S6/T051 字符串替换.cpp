// NOJ T051 字符串替换
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int vsize = 0;
    string str;
    vector<string> vstr;
    while (cin >> str)
    {
        vstr.push_back(str);
    }
    vsize = vstr.size();
    for (int i = 0; i <= vsize - 1; i++)
    {
        if (vstr[i] == "you")
            vstr[i] = "we";
        cout << vstr[i] << " ";
    }
    return 0;
}