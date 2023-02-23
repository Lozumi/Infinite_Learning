// EOJ T2-10
#include <stdio.h>

int isRun(int fyy);
int getddM(int fmm, int fisRun);

int main()
{

    int yy = 0, mm = 0, dd = 0, h = 0, m = 0, s = 0;
    int mmM = 12, ddM = 0, hM = 24, mM = 60, sM = 60;
    scanf("%d-%d-%d %d:%d:%d", &yy, &mm, &dd, &h, &m, &s);
    ddM = getddM(mm, isRun(yy));
    if (s == 59)
    {
        s = 0;
        m += 1;
    }
    else
        s += 1;
    if (m == 60)
    {
        m = 0;
        h += 1;
    }
    if (h == 24)
    {
        h = 0;
        dd += 1;
    }
    if (dd == ddM + 1)
    {
        dd = 1;
        mm += 1;
    }
    if (mm == 13)
    {
        mm = 1;
        yy += 1;
    }
    printf("Next second: %04d-%02d-%02d %02d:%02d:%02d", yy, mm, dd, h, m, s);
    return 0;
}

int isRun(int fyy)
{
    if ((fyy % 4 == 0 && fyy % 100 != 0) || fyy % 400 == 0)
        return 1;
    return 0;
}

int getddM(int fmm, int fisRun)
{
    if (fisRun == 1 && fmm == 2)
        return 29;
    switch (fmm)
    {
    case (2):
        return 28;
        break;
    case (1):
    case (3):
    case (5):
    case (7):
    case (8):
    case (10):
    case (12):
        return 31;
        break;
    }
    return 30;
}
