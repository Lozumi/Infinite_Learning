// NOJ T069 字符串排序
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
void sort(char S[10][11])
{
    char t[11];
    int i, j;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9 - i; j++)
        {
            if (strcmp(S[j], S[j + 1]) > 0)
            {
                strcpy(t, S[j]);
                strcpy(S[j], S[j + 1]);
                strcpy(S[j + 1], t);
            }
        }
}
int main()
{
    char S[10][11];
    int k;
    for (k = 0; k <= 9; k++)
        cin >> S[k];
    sort(S);
    for (k = 0; k <= 9; k++)
        cout << S[k] << ' ';
    cout << endl;
    return 0;
}