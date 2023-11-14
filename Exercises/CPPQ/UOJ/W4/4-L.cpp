// UOJ W4-M
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int ch;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        cout << (char)ch << endl;
    }
    return 0;
}