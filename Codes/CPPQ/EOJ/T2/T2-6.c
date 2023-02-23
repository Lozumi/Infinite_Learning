// EOJ T2-6
#include <stdio.h>

int main()
{
    int i;
    scanf("%d", &i);
    switch ((i - 1) % 12)
    {
    case 0:
        printf("%d年是鸡年！", i);
        break;
    case 1:
        printf("%d年是狗年！", i);
        break;
    case 2:
        printf("%d年是猪年！", i);
        break;
    case 3:
        printf("%d年是鼠年！", i);
        break;
    case 4:
        printf("%d年是牛年！", i);
        break;
    case 5:
        printf("%d年是虎年！", i);
        break;
    case 6:
        printf("%d年是兔年！", i);
        break;
    case 7:
        printf("%d年是龙年！", i);
        break;
    case 8:
        printf("%d年是蛇年！", i);
        break;
    case 9:
        printf("%d年是马年！", i);
        break;
    case 10:
        printf("%d年是羊年！", i);
        break;
    case 11:
        printf("%d年是猴年！", i);
        break;
    }
    return 0;
}
