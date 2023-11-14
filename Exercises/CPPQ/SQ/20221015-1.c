#include <stdio.h>
int V = 12;
int r1 = 100, r2 = 200, r3 = 300, r4 = 400, r5 = 500, r6 = 600, r7 = 700;
float R1 = 0, R2 = 0, R3 = 0, R = 0, I = 0;
float series(int a1, int a2);
float parallel(int a3, int a4);
float parallel_three(int a5, int a6, int a7);
float Ohm_law(float A1, float A2, float A3, int V);

float series(int a1, int a2)
{
    float ans = 0;
    ans = a1 + a2;
    return ans;
}

float parallel(int a3, int a4)
{
    float ans = 0;
    ans = 1.0 / (1.0 / a3 + 1.0 / a4);
    return ans;
}

float parallel_three(int a5, int a6, int a7)
{
    float ans = 0;
    ans = a5 + 1.0 / (1.0 / a6 + 1.0 / a7);
    return ans;
}

float Ohm_law(float A1, float A2, float A3, int V)
{
    float ans = 0, R = 0;
    R = 1 / (1 / A1 + 1 / A2 + 1 / A3);
    V = V * 1000;
    ans = V / R;
    return ans;
}

int main()
{
    R1 = series(r1, r2);
    R2 = parallel(r3, r4);
    R3 = parallel_three(r5, r6, r7);
    I = Ohm_law(R1, R2, R3, V);
    printf("%.1f", I);
    return 0;
}
