// EOJ T2-7
#include <stdio.h>

int main()
{
    int i = 0, j = 0, k = 0;
    float w = 0, w1 = 0, w2 = 0;
    scanf("%d %d %d", &i, &j, &k);
    if (i >= 4)
    {
        printf("人员类别不正确！");
        return 0;
    }
    switch (i)
    {
    case (1):
        w1 = 800;
        w2 = 1200;
        break;
    case (2):
        w1 = 500;
        w2 = 750;
        break;
    case (3):
        w1 = 400;
        w2 = 600;
        break;
    }
    if (j < 0 || k < 0 || (j + k) <= 0)
    {
        printf("出差天数不能为负数并且总天数不能为零！");
        return 0;
    }
    if (j > 0 && k == 0)
    {
        printf("执行淡季标准：%.2f元/天。\n", w1);
        w = j * w1;
        printf("可报销住宿费用：%d天*%.2f元/天=%.2f元。\n", j, w1, w);
    }
    else if (j == 0 && k > 0)
    {
        printf("执行旺季标准：%.2f元/天。\n", w2);
        w = k * w2;
        printf("可报销住宿费用：%d天*%.2f元/天=%.2f元。\n", k, w2, w);
    }
    else if (j > 0 && k > 0)
    {
        printf("执行标准：%.2f元/天（淡季），%.2f元/天（旺季）。\n", w1, w2);
        w = j * w1 + k * w2;
        printf("可报销住宿费用：%d天*%.2f元/天（淡季）+%d天*%.2f元/天（旺季）=%.2f元。", j, w1, k, w2, w);
    }
    return 0;
}
