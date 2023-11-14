// UOJ W3-B
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sf(int n);

int main(void)
{
    int n = 0;
    double result = 0;
    cin >> n;
    result = sf(n);
    cout << fixed << setprecision(3) << result << endl;
    return 0;
}

double sf(int n)
{
    double ans = 0;
    if (n > 1)
        ans = sqrt(n + sf(n - 1));
    else if (n == 1)
        ans = ans + 1;
    return ans;
}