// UOJ W1-K
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(string str, char del);

int main()
{
    string time;
    cin >> time;
    vector<string> ans = split(time, ':');
    int s, m, h;
    h = atoi(ans[0].c_str());
    m = atoi(ans[1].c_str());
    s = atoi(ans[2].c_str());
    cout << h * 3600 + m * 60 + s << endl;
    return 0;
}

vector<string> split(string str, char del)
{
    stringstream ss(str);
    string tmp;
    vector<string> res;
    while (getline(ss, tmp, del))
    {
        res.push_back(tmp);
    }
    return res;
}