// UOJ W3-D
#include <iostream>
#include <iomanip>
using namespace std;

double df(int n);

int main(void)
{
    int n = 0;
    double result = 0;
    cin >> n;
    result = df(n);
    cout << fixed << setprecision(3) << result << endl;
    return 0;
}

double df(int n)
{
    double ans = 0;
    if (n > 1)
        ans = 3 / (n + df(n - 1));
    else if (n == 1)
        ans = 0.75;
    return ans;
}