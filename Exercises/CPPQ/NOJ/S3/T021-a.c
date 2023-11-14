// unsolved
//  NOJ T021
#include <stdio.h>
//#include <time.h>
int main()
{
    int abcde, fghij, n;
    int a, f, r, i, duplicate;
    int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    long beginTime, endTime;
    scanf("%d", &n);
    // beginTime = clock();
    for (abcde = 1234; abcde <= 98765; abcde++)
    {
        n0 = n1 = n2 = n3 = n4 = n5 = n6 = n7 = n8 = n9 = 0;
        a = abcde;
        duplicate = 0;
        for (i = 0; i < 5; i++)
        {
            r = a % 10;
            switch (r)
            {
            case 0:
                if (n0 > 0)
                    duplicate = 1;
                else
                    n0++;
                break;
            case 1:
                if (n1 > 0)
                    duplicate = 1;
                else
                    n1++;
                break;
            case 2:
                if (n2 > 0)
                    duplicate = 1;
                else
                    n2++;
                break;
            case 3:
                if (n3 > 3)
                    duplicate = 1;
                else
                    n3++;
                break;
            case 4:
                if (n4 > 0)
                    duplicate = 1;
                else
                    n4++;
                break;
            case 5:
                if (n5 > 0)
                    duplicate = 1;
                else
                    n5++;
                break;
            case 6:
                if (n6 > 0)
                    duplicate = 1;
                else
                    n6++;
                break;
            case 7:
                if (n7 > 0)
                    duplicate = 1;
                else
                    n7++;
                break;
            case 8:
                if (n8 > 0)
                    duplicate = 1;
                else
                    n8++;
                break;
            case 9:
                if (n9 > 0)
                    duplicate = 1;
                else
                    n9++;
                break;
            }
            if (duplicate == 1)
            {
                break;
            }
            else
            {
                a = a / 10;
            }
        }
        if (duplicate == 1)
        {
            continue;
        }
        fghij = n * abcde;
        if (fghij <= 98765)
        {
            f = fghij;
            for (i = 0; i < 5; i++)
            {
                r = f % 10;
                switch (r)
                {
                case 0:
                    if (n0 > 0)
                        duplicate = 1;
                    else
                        n0++;
                    break;
                case 1:
                    if (n1 > 0)
                        duplicate = 1;
                    else
                        n1++;
                    break;
                case 2:
                    if (n2 > 0)
                        duplicate = 1;
                    else
                        n2++;
                    break;
                case 3:
                    if (n3 > 3)
                        duplicate = 1;
                    else
                        n3++;
                    break;
                case 4:
                    if (n4 > 0)
                        duplicate = 1;
                    else
                        n4++;
                    break;
                case 5:
                    if (n5 > 0)
                        duplicate = 1;
                    else
                        n5++;
                    break;
                case 6:
                    if (n6 > 0)
                        duplicate = 1;
                    else
                        n6++;
                    break;
                case 7:
                    if (n7 > 0)
                        duplicate = 1;
                    else
                        n7++;
                    break;
                case 8:
                    if (n8 > 0)
                        duplicate = 1;
                    else
                        n8++;
                    break;
                case 9:
                    if (n9 > 0)
                        duplicate = 1;
                    else
                        n9++;
                    break;
                }
                if (duplicate == 1)
                {
                    break;
                }
                else
                {
                    f = f / 10;
                }
            }
            if (!duplicate)
            {
                printf("%05d/%05d=%d\n", fghij, abcde, n);
            }
        }
    }
    // endTime = clock();
    //  printf("Elapsed time: %ldms\n", (endTime - beginTime));
    return 0;
}