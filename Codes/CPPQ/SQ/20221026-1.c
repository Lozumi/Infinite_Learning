// C-6-1
#include <stdio.h>
int main()
{
    int x = 0, y = 0, z = 0;

    do
    {

        switch (y++)
        {

        case 1:

            x++;

            break;

        case 1 + 2:

            x += 3;

            break;

        default:

            x = x % 2;

            continue;
        }

        z++;

    } while (y < 5);
    printf("%d %d", x, z);
    return 0;
}