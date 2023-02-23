// UOJ W1-N
#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year; //键盘中输入一个年份，保存到变量year中

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //指定是否为闰年的判断条件
        cout << "1" << endl;                                   //条件成立则该年份是闰年
    else
        cout << "0" << endl; //否则该年份不是闰年
    return 0;
}
