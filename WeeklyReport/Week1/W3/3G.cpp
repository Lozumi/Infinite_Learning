// UOJ W3-G
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int a = 0;
    cin >> a;
    string m, n;
    while (cin >> m >> n)
    {
        if (m == "Rock")
        {
            if (n == "Rock")
                cout << "Tie" << endl;
            else if (n == "Scissors")
                cout << "fdw" << endl;
            else if (n == "Paper")
                cout << "wcx" << endl;
        }
        else if (m == "Scissors")
        {
            if (n == "Rock")
                cout << "wcx" << endl;
            else if (n == "Scissors")
                cout << "Tie" << endl;
            else if (n == "Paper")
                cout << "fdw" << endl;
        }
        else if (m == "Paper")
        {
            if (n == "Rock")
                cout << "fdw" << endl;
            else if (n == "Scissors")
                cout << "wcx" << endl;
            else if (n == "Paper")
                cout << "Tie" << endl;
        }
    }
    return 0;
}