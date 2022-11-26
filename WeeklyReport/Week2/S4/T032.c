// NOJ T032
#include <stdio.h>

int main()
{
    int AH, AM, AS, BH, BM, BS, CH, CM, CS;
    scanf("%d %d %d %d %d %d", &AH, &AM, &AS, &BH, &BM, &BS);
    CH = AH + BH;
    CM = AM + BM;
    CS = AS + BS;
    if (CS > 59)
    {
        CS = CS - 60;
        CM = CM + 1;
    }
    if (CM > 59)
    {
        CM = CM - 60;
        CH = CH + 1;
    }
    printf("%d %d %d", CH, CM, CS);
    return 0;
}
