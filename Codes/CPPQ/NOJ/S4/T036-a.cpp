// UOJ W2-B
// NOJ T036-a
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
    {
        cout << *it;
    }
    return 0;
}