#include <iostream>
using namespace std;

void combinate(int iPos, int iProc, int iTol, int iKey, int data[], int des[])
{
    if (iProc > iTol)
    {
        return;
    }
    if (iPos == iKey)
    {
        for (int i = 0; i < iKey; i++)
        {
            cout << des[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        combinate(iPos, iProc + 1, iTol, iKey, data, des);
        des[iPos] = data[iProc];
        combinate(iPos + 1, iProc + 1, iTol, iKey, data, des);
    }
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k; //输入总数，单组数
    if (n > k > 0)
    {
        int data[1000], temp[1000];
        for (int i = 0; i < n; i++)
        {
            data[i] = i + 1;
        }
        combinate(0, 0, n, k, data, temp);
    }
    return 0;
}