// EOJ T1-8
#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, c, d, m, n;
    scanf("(%f,%f)(%f,%f)", &a, &b, &c, &d);
    m = sqrt(pow(a - c, 2) + pow(b - d, 2));
    n = fabs(a - c) + fabs(b - d);
    printf("EuclideanDist = %.4f\n", m);
    printf("ManhattanDist = %.4f\n", n);
    return 0;
}