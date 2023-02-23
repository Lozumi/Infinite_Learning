// NOJ T026
#include <stdio.h>

int main(void)
{
    int n = 0, sum = 1, sum_m = 0;
    int arr[19] = {'\0'};
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            sum = 1;
            for (int k = 0; k <= i; k++)
            {
                sum *= arr[j + k];
            }
            if (sum >= sum_m)
                sum_m = sum;
        }
    }
    if (sum_m < 0)
        printf("-1");
    else
        printf("%d", sum_m);
    return 0;
}