// UOJ W1-G
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int score;
    cin >> score;
    switch (score / 5)
    {
    case 20:
        cout << "4.1" << endl;
        break;
    case 19:
        cout << "4.1" << endl;
        break;
    case 18:
        cout << "3.9" << endl;
        break;
    case 17:
        cout << "3.7" << endl;
        break;
    case 16:
        cout << "3.3" << endl;
        break;
    default:
        switch (score / 20)
        {
        case 3:
            cout << "3" << endl;
            break;
        default:
            cout << "2" << endl;
            break;
        }
        break;
    }
    return 0;
}