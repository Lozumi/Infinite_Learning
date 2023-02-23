// UOJ W1-O
#include <iostream>
#include <cmath>
using namespace std;

bool angle1(int x, int y, int z)
{
    if (pow(x, 2) + pow(y, 2) == pow(z, 2) || pow(x, 2) + pow(z, 2) == pow(y, 2) || pow(z, 2) + pow(y, 2) == pow(x, 2))
        return true;
    return false;
}
bool angle2(int x, int y, int z)
{
    if (pow(x, 2) + pow(y, 2) > pow(z, 2) && pow(x, 2) + pow(z, 2) > pow(y, 2) && pow(z, 2) + pow(y, 2) > pow(x, 2))
        return true;
    return false;
}
bool angle3(int x, int y, int z)
{
    if (pow(x, 2) + pow(y, 2) < pow(z, 2) || pow(x, 2) + pow(z, 2) < pow(y, 2) || pow(z, 2) + pow(y, 2) < pow(x, 2))
        return true;
    return false;
}
bool isTri(int x, int y, int z)
{
    if (x + y > z && x + z > y && y + z > x)
        return true;
    return false;
}
int isDy(int x, int y, int z)
{
    if (x == y || x == z || y == z)
    {
        if (x == y && y == z && x == z)
            return 2;
        return 1;
    }
    return 0;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (isTri(a, b, c) == 0)
        cout << "BAD INPUT\n";
    else
    {
        if (angle1(a, b, c))
            printf("TRIANGULO RETANGULO\n");
        else if (angle2(a, b, c))
            printf("TRIANGULO ACUTANGULO\n");
        else if (angle3(a, b, c))
            printf("TRIANGULO OBTUSANGULO\n");
        if (isDy(a, b, c) == 1)
            cout << "TRIANGULO ISOSCELES\n";
        else if (isDy(a, b, c) == 2)
            cout << "TRIANGULO EQUILATERO\n";
    }
    return 0;
}