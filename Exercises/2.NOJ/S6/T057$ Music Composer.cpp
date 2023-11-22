// NOJ T057 Music Composer
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char S[10];
    scanf("%[^\n]%*c", S);
    if (S[0] == 'A' && S[1] == '#')
    {
        S[0] = 'B', S[1] = 'b';
        cout << S << endl;
    }
    else if (S[0] == 'C' && S[1] == '#')
    {
        S[0] = 'D', S[1] = 'b';
        cout << S << endl;
    }
    else if (S[0] == 'D' && S[1] == '#')
    {
        S[0] = 'E', S[1] = 'b';
        cout << S << endl;
    }
    else if (S[0] == 'F' && S[1] == '#')
    {
        S[0] = 'G', S[1] = 'b';
        cout << S << endl;
    }
    else if (S[0] == 'G' && S[1] == '#')
    {
        S[0] = 'A', S[1] = 'b';
        cout << S << endl;
    }
    else if (S[0] == 'B' && S[1] == 'b')
    {
        S[0] = 'A', S[1] = '#';
        cout << S << endl;
    }
    else if (S[0] == 'D' && S[1] == 'b')
    {
        S[0] = 'C', S[1] = '#';
        cout << S << endl;
    }
    else if (S[0] == 'E' && S[1] == 'b')
    {
        S[0] = 'D', S[1] = '#';
        cout << S << endl;
    }
    else if (S[0] == 'G' && S[1] == 'b')
    {
        S[0] = 'F', S[1] = '#';
        cout << S << endl;
    }
    else if (S[0] == 'A' && S[1] == 'b')
    {
        S[0] = 'G', S[1] = '#';
        cout << S << endl;
    }
    else
        cout << "unique" << endl;
    return 0;
}