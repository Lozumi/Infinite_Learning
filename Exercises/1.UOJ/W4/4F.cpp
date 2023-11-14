// UOJ W4-F-2
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    if (A.size() < B.size())
        return add(B, A);

    int r = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        r += A[i];
        if (i < B.size())
            r += B[i];
        C.push_back(r % 10);
        r /= 10;
    }
    if (r)
        C.push_back(r);

    return C;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> A, B;
    string a, b;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i)
        B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];

    return 0;
}
