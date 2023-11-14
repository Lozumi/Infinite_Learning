// UOJ W2-B
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string num;
    cin >> num;
    vector<char> vnum;
    for (auto i : num)
    {
        vnum.push_back(i);
    }
    for (auto it = vnum.end() - 1; it >= vnum.begin(); it--)
        if (it == vnum.end() - 1)
            cout << *it;
        else
            cout << " " << *it;
    return 0;
}