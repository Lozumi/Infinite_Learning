// NOJ T004
// UOJ W2-B
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string num = "", inum = "";
    cin >> num;
    vector<char> vnum;
    for (auto i : num)
    {
        vnum.push_back(i);
    }
    for (auto it = vnum.end() - 1; it >= vnum.begin(); it--)
        inum += *it;
    if (num == inum)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}