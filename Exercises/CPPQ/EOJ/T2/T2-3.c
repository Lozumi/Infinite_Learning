//EOJ T2-3
#include <stdio.h>

int main(void)
{
    int a,b,c,d;
    float e,f;
    int isOK = 1;
    int sum = 0;
    int sumt = 0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    e = a+b+c+d;
    f = e/4.0;
    printf("总分：%.2f, 平均分：%.2f\n",e,f);
    if (a >=50 && b>=50 && c>= 70 && d>= 70&&e>=315){
        isOK = 1;
        printf("通过！");
    }
    else
        printf("不通过！\n原因：");
    if (a<50)
        sum += 1;
    if (b<50)
        sum += 1;
    if (c<70)
        sum += 1;
    if (d<70)
        sum += 1;
    if (e < 315)
        sum += 1;
    if (a<50){
        sumt += 1;
        (sumt != sum)?printf("政治低于50，"):printf("政治低于50。");
        }
    if (b<50){
        sumt += 1;
        (sumt != sum)?printf("外语低于50，"):printf("外语低于50。");
        }
    if (c<70){
        sumt += 1;
        (sumt != sum)?printf("业务课一低于70，"):printf("业务课一低于70。");
        }
    if (d<70){
        sumt += 1;
        (sumt != sum)?printf("业务课二低于70，"):printf("业务课二低于70。");
        }
    if (e < 315){
        sumt += 1;
        (sumt != sum)?printf("总分低于315，"):printf("总分低于315。");
        }
    return 0;
}