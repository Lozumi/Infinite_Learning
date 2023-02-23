/* UOJ W1-C
 * 输入 给出圆的半径正整数r
 * 输出 输出共有两行。第一行请输出圆的周长，第二行请输出圆的面积。均保留2位小数。
 * 使用数据类型的显示转换和隐式转换。
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double PI = 3.1415926;
    double r, c, s;
    cin >> r;
    c = r * 2 * PI;
    s = PI * r * r;
    cout << fixed << setprecision(2) << c << endl
         << s << endl; //定点表示，精度为2
    return 0;
}