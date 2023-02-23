// NOJ T005
// UOJ W1-G
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;
    }
    if (a > c)
    {
        c = a ^ c;
        a = a ^ c;
        c = a ^ c;
    }
    if (b > c)
    {
        c = b ^ c;
        b = b ^ c;
        c = b ^ c;
    }
    cout << c << endl;
    return 0;
}