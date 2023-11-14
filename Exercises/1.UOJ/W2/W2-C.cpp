// UOJ W2-C
#include <iostream>
using namespace std;

int main()
{
    long long m, n, sum;
    cin >> n >> m;
    sum = m;
    for (int i = 1; i <= n - 1; i++)
    {
        m = 2 * m + 10;
        sum += m;
    }
    cout << sum << endl;
    return 0;
}
