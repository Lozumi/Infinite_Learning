// NOJ T008
#include <stdio.h>
int isRun(int fyy);

int main()
{
    int yy = 0, mm = 0, dd = 0, s = 0;
    scanf("%d-%d-%d", &yy, &mm, &dd);
    if (isRun(yy) == 0)
    {
        switch (mm)
        {
        case (1):
            s = dd;
            break;
        case (2):
            s = 31 + dd;
            break;
        case (3):
            s = 59 + dd;
            break;
        case (4):
            s = 90 + dd;
            break;
        case (5):
            s = 120 + dd;
            break;
        case (6):
            s = 151 + dd;
            break;
        case (7):
            s = 181 + dd;
            break;
        case (8):
            s = 212 + dd;
            break;
        case (9):
            s = 243 + dd;
            break;
        case (10):
            s = 273 + dd;
            break;
        case (11):
            s = 304 + dd;
            break;
        case (12):
            s = 334 + dd;
            break;
        }
    }
    else
    {
        switch (mm)
        {
        case (1):
            s = dd;
            break;
        case (2):
            s = 31 + dd;
            break;
        case (3):
            s = 59 + 1 + dd;
            break;
        case (4):
            s = 90 + 1 + dd;
            break;
        case (5):
            s = 120 + 1 + dd;
            break;
        case (6):
            s = 151 + 1 + dd;
            break;
        case (7):
            s = 181 + 1 + dd;
            break;
        case (8):
            s = 212 + 1 + dd;
            break;
        case (9):
            s = 243 + 1 + dd;
            break;
        case (10):
            s = 273 + 1 + dd;
            break;
        case (11):
            s = 304 + 1 + dd;
            break;
        case (12):
            s = 334 + 1 + dd;
            break;
        }
    }
    printf("%d\n", s);
    return 0;
}

int isRun(int fyy)
{
    if ((fyy % 4 == 0 && fyy % 100 != 0) || fyy % 400 == 0)
        return 1;
    return 0;
}