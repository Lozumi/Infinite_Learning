// UOJ W1-G
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    string calc;
    cin >> a >> b >> calc;
    if (calc == "+")
        c = a + b;
    else if (calc == "-")
        c = a - b;
    else if (calc == "*")
        c = a * b;
    else if (calc == "/")
        c = a / b;
    else
        cout << "Calc invalid.";
    cout << fixed << setprecision(2) << c << endl;
    return 0;
}