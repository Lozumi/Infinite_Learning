// UOJ W1-K
#include <iostream>
using namespace std;

int main()
{
    int h1, m1, h2, m2, t1, t2, diff;
    cin >> h1 >> m1 >> h2 >> m2;
    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    if (t2 <= t1) //注意带等号，走完一整天（24h）的情况。
        t2 += 1440;
    diff = t2 - t1;
    cout << diff << endl;
    return 0;
}