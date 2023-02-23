//输入圆的半径，输出直径、周长和面积
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double r,d,c,s;
    const double pi = acos(-1.0);
    cin>>r;
    d = r * 2;
    c = d * pi;
    s = pi * pow(r,2);
    cout<<d<<" "<<c<<" "<<s<<endl;
    return 0;
}