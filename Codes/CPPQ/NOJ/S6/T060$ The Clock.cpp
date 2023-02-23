// NOJ T070 Clock
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string clock[12] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"}, no;
    cin >> no;
    for (int i = 0; i <= 11; i++)
    {
        if (no == clock[i])
            cout << i + 1 << endl;
    }
    return 0;
}