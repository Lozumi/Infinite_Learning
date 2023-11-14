#include <iostream>
using namespace std;
int ack(int x, int y)
{
    int n;
    if (x == 0)
    {
        n = y + 1;
        return n;
    }
    else if (y == 0)
        n = ack(x - 1, 1);
    else
        n = ack(x - 1, ack(x, y - 1));
    return n;
}
int main()
{
    int m, n, z;
    cin >> m >> n;
    z = ack(m, n);
    cout << z << endl;
    return 0;
}