// NOJ T020
#include <stdio.h>
#include <math.h>

int main(void)
{
    int a[5] = {0};
    double w = 1, wm = 1;
    for (int i1 = 0; i1 <= 20; i1++)
    {
        for (int i2 = 0; i2 <= 10; i2++)
        {
            for (int i3 = 0; i3 <= 6; i3++)
            {
                for (int i5 = 0; i5 <= 4; i5++)
                {
                    for (int i8 = 0; i8 <= 2; i8++)
                    {
                        if (i1 * 1 + i2 * 2 + i3 * 3 + i5 * 5 + i8 * 8 == 20)
                        {
                            w = pow(1 + 0.0063 * 12 * 1, i1) * pow(1 + 0.0066 * 12 * 2, i2) * pow(1 + 0.0069 * 12 * 3, i3) * pow(1 + 0.0075 * 12 * 5, i5) * pow(1 + 0.0084 * 12 * 8, i8);
                            if (w > wm)
                            {
                                wm = w;
                                a[0] = i1;
                                a[1] = i2;
                                a[2] = i3;
                                a[3] = i5;
                                a[4] = i8;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d %d\n", a[4], a[3], a[2], a[1], a[0]);
    printf("%.2lf", 2000 * wm);
    return 0;
}