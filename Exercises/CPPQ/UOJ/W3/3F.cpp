// UOJ W3-F
#include <iostream>
using namespace std;

int pf(int m, int n);

int main(void)
{
    int m = 0, n = 0, result = 0;
    cin >> m >> n;
    cout << pf(m, n) << endl;
    return 0;
}

int pf(int m, int n)
{
    int ans = 0;
    if (m == 0)
        ans = n + 1;
    else if (n == 0)
        ans = pf(m - 1, 1);
    else if (m >= 0 && n >= 0)
        ans = pf(m - 1, pf(m, n - 1));
    return ans;
}