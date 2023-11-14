// NOJ T027

#include <stdio.h>

int main(void)
{
    int myyPosi, fyyPosi, myySpeed, fyySpeed, len, hour = 1; //美羊羊坐标，沸羊羊坐标，美羊羊速度，沸羊羊速度，纬度线总长
    scanf("%d %d %d %d %d", &myyPosi, &fyyPosi, &myySpeed, &fyySpeed, &len);
    if (myySpeed == fyySpeed)
    {
        printf("impossible");
        return 0;
    }
    while ((myyPosi + myySpeed) % len != (fyyPosi + fyySpeed) % len)
    {
        myyPosi = (myyPosi + myySpeed) % len;
        fyyPosi = (fyyPosi + fyySpeed) % len;
        hour++;
    }
    printf("%d", hour);
    return 0;
}