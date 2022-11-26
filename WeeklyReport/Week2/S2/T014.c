// NOJ T014
#include <stdio.h>
#include <math.h>
int Bit_Int_1(long n);
int Bit_Int_2(long n);

int main(void)
{
    long n = 0, bit = 0;
    scanf("%d", &n);
    n = abs(n);
    bit = Bit_Int_1(n);
    printf("%d", bit);
    return 0;
}

int Bit_Int_1(long n) //法1
{
    int bit = 0;
    if (n / 10 == 0)
        return 0;
    while (n)
    {
        bit++;
        n /= 10;
    }
    return bit;
}

int Bit_Int_2(long n) //法2
{
    if (n == 0)
        return 1;
    else
        return log10(abs(n)) + 1; //求整数的位数
                                  //例如  1234  lgx+1;
}