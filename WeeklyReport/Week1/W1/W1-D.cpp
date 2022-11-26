// UOJ W1-D
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c, avg;
    cin >> a >> b >> c;
    avg = (a + b + c) / 3;
    cout << fixed << setprecision(3) << avg;
    return 0;
}