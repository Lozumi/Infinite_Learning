// NOJ T30
#include <stdio.h>

int main(void)
{
    int n = 0, na = 1, nb = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int nbc = nb, nac = na;
        nb = nac * 3 + nbc * 2;
        na = nbc;
    }
    printf("%d %d", na, nb);
    return 0;
}