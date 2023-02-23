// UOJ W1-Q
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, result;
    cin >> a >> b;
    if ((a + b) % 2 == 0)
    {
        cout << "Alice"
             << " "
             << abs(a - b) % 6 << endl;
    }
    else
    {
        cout << "Bob"
             << " "
             << abs(a - b) % 6 - 1 << endl;
    }
    return 0;
}