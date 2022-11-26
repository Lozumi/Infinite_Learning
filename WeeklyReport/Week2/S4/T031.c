// NOJ T031
#include <stdio.h>

int main(void)
{
    int n = 0, n1, n2, n3, n4;
    scanf("%d", &n);
    n1 = n % 10;
    n2 = n % 100 / 10;
    n3 = n % 1000 / 100;
    n4 = n / 1000;
    n1 = (n1 + 5) % 10;
    n2 = (n2 + 5) % 10;
    n3 = (n3 + 5) % 10;
    n4 = (n4 + 5) % 10;
    printf("%d%d%d%d", n1, n2, n3, n4);
    return 0;
}