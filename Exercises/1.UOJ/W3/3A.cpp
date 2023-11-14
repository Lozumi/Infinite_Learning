// UOJ W3-A
#include <iostream>
using namespace std;

int pf(int n);

int main(void)
{
    int n = 0, result = 0;
    cin >> n;
    cout << pf(n) << endl;
    return 0;
}

int pf(int n)
{
    int ans = 0;
    if (n == 0)
        ans = 1;
    else if (n == 1)
        ans = 3;
    else if (n > 1)
        ans = 6 * pf(n - 1) + 7 * pf(n - 2);
    return ans;
}