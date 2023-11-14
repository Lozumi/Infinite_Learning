// UOJ W2-D
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double func(int i);

int main(void)
{
    double sum = 0;
    int n = 0;
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        sum = sum + func(j);
    }
    cout << fixed << setprecision(6) << sum << endl;
    return 0;
}

double func(int i)
{
    double sum = 0;
    sum = (pow(-1, i) * (2 * i - 3) + 3 * i - 5) / ((2 * i + 1) * (2 * i - 1));
    return sum;
}
