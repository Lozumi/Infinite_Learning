#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        for (c = 1, d = 0; c < a; c++)
        {
            if (a % c == 0)
            {
                d += c;
            }
        }

        for (c = 1, e = 0; c < b; c++)
        {
            if (b % c == 0)
            {
                e += c;
            }
        }
        if (d == b && e == a)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}