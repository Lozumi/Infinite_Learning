// UOJ W1-K
#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a <= 9)
        cout << "1" << endl;
    else if (9 < a && a <= 18)
        cout << "2" << endl;
    else if (18 < a && a <= 27)
        cout << "3" << endl;
    else if (27 < a && a <= 36)
        cout << "4" << endl;
    else
        cout << "-1" << endl;
    return 0;
}