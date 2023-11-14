#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int sum;
    for (int a = 2; a <= 1000; a++)
    {
        sum = 0;
        bool isFT = 1;
        if (a == 1)
        {
            cout << a << "=" << a << endl;
            continue;
        }
        str = to_string(a) + "=";
        for (int i = 1; i != a; i++)
        {
            if (a % i == 0)
            {
                if (isFT == 1)
                {
                    str = str + to_string(i);
                    sum += i;
                    isFT = 0;
                }
                else
                {
                    str = str + "+" + to_string(i);
                    sum += i;
                }
            }
        }
        if (sum == a)
            cout << str << endl;
    }
    return 0;
}