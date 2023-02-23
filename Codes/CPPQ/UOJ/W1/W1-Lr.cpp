// UOJ W1-K
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<string> split(string str, char del);
void s2n(string str, int &num);

int main()
{
    string time;
    cin >> time;
    vector<string> ans = split(time, ':');
    int s, m, h;
    s2n(ans[0], h);
    s2n(ans[1], m);
    s2n(ans[2], s);
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

void s2n(string str, int &num)
{
    stringstream ss;
    ss << str;
    ss >> num;
}