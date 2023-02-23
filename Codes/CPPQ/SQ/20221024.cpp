#include <stdio.h>

int main()
{
    int i1, i2, i3, i8, i5;
    int i = 0;
    const double l1 = 0.0063, l2 = 0.0066, l3 = 0.0069, l5 = 0.0075, l8 = 0.0084;
    struct bank
    {
        int year[5];
        double w;
    } bank[100];
    struct bank tt;
    for (i8 = 0; i8 <= 2; i8++)
    {
        for (i5 = 0; i5 <= 4; i5++)
        {
            for (i3 = 0; i3 <= 6; i3++)
            {
                for (i2 = 0; i2 <= 10; i2++)
                {
                    for (i1 = 0; i1 <= 20; i1++)
                    {
                        if (8 * i8 + 5 * i5 + 3 * i3 + 2 * i2 + 1 * i1 == 20)
                        {
                            bank[i].w = 96.0 * i8 * l8 + 60.0 * i5 * l5 + 36.0 * i3 * l3 + 24.0 * i2 * l2 + 12.0 * i1 * l1;
                            bank[i].year[0] = i8, bank[i].year[1] = i5, bank[i].year[2] = i3, bank[i].year[3] = i2, bank[i].year[4] = i1;
                            i++;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i <= 99; i++)
    {
        for (int j = 0; j <= 99 - i; j++)
        {
            if (bank[j].w < bank[j + 1].w)
            {

                tt = bank[j];
                bank[j] = bank[j + 1];
                bank[j] = tt;
            }
        }
    }
    printf("%d %d %d %d %d\n", bank[99].year[0], bank[99].year[1], bank[99].year[2], bank[99].year[3], bank[99].year[4]);
    printf("%lf", bank[99].w);

    return 0;
}
