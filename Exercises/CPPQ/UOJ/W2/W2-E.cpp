// UOJ W2-F
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n = 0, sum = 0, sum_fin = 0;
    cin >> n;
    vector<int> num;
    while (cin >> n)
    {
        num.push_back(n);
    }
    for (auto it = num.begin(); it < num.end() - 3; it++)
    {
        sum = 0;
        sum = *it + *(it + 1) + *(it + 2);
        if (sum > sum_fin)
            sum_fin = sum;
    }
    cout << sum_fin << endl;
    return 0;
}