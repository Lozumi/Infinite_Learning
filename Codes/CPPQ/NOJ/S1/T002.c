// NOJ T002
#include <stdio.h>
#include <math.h>

int main(void)
{
    double r = 0, h = 0;
    double l = 0, s = 0, sq = 0, vq = 0, vz = 0;
    double pi = acos(-1.0);
    scanf("%lf %lf", &r, &h);
    l = 2 * pi * r;
    s = pi * r * r;
    sq = 4 * pi * r * r;
    vq = 4 / 3.0 * pi * r * r * r;
    vz = s * h;
    printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n", l, s, sq, vq, vz);
    return 0;
}