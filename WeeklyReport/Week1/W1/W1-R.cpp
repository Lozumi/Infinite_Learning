#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    double s, avg;
    cin >> a >> b >> c;
    avg = (a + b + c) / 3.0;
    s = (pow(a - avg, 2) + pow(b - avg, 2) + pow(c - avg, 2)) / 3.0;
    s = (int)s;
    cout << s << endl;
    return 0;
}