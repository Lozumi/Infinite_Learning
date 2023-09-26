#include "rover_controller.h"
#include <cstdio>
#include <cmath>
#include <vector>
#include <tuple>

#define M_PI = 3.1415926585;

constexpr float F_PI = (float)M_PI;

inline bool approach(float x, float y, float tx, float ty, float r)
{
    return (x - tx) * (x - tx) + (y - ty) * (y - ty) <= r * r;
}

inline float clip(float maxv, float minv, float v)
{
    return (v >= maxv) ? maxv : ((v <= minv) ? minv : v);
}

int main()
{
    float maxLinearVel, maxAngVel, x, y, ang;
    int fullScoreMaxTries, maxTries, goalCount;
    std::vector<std::tuple<float, float, float>> goals;
    printf("输入最大速度和最大角速度，用空格隔开：");
    scanf("%f%f", &maxLinearVel, &maxAngVel);
    printf("输入轮式机器人初始坐标x和y，用空格隔开：");
    scanf("%f%f", &x, &y);
    printf("输入轮式机器人初始朝向：");
    scanf("%f", &ang);
    printf("输入满分最大尝试次数，得分最大尝试次数和目标数量，用空格隔开：");
    scanf("%d%d%d", &fullScoreMaxTries, &maxTries, &goalCount);
    for (int i = 0; i < goalCount; i++)
    {
        printf("输入第%d个目标的坐标和半径（x, y, r三个数字），用空格隔开：", i);
        float x, y, r;
        scanf("%f%f%f", &x, &y, &r);
        goals.push_back(std::make_tuple(x, y, r));
    }

    printf("\n");
    int times = 0, arrived = 0;
    init(maxLinearVel, maxAngVel, fullScoreMaxTries, maxTries);
    for (const auto &goal : goals)
    {
        float tx = std::get<0>(goal), ty = std::get<1>(goal), tr = std::get<2>(goal);
        printf("执行navigateTo(%.2f, %.2f, %.2f)\n", tx, ty, tr);
        navigateTo(tx, ty, tr);
        do
        {
            if (times >= maxTries)
                goto end;
            CmdVel step = update(x, y, ang);
            step.linear = clip(maxLinearVel, -maxLinearVel, step.linear);
            step.angular = clip(maxAngVel, -maxAngVel, step.angular);
            printf("第%d次更新，机器人位置：(%.2f, %.2f)，朝向：%.2f，选手算法计算得到的线速度：%.2f，角速度：%.2f\n", times + 1, x, y, ang, step.linear, step.angular);
            if (step.angular < 0.0001f && step.angular > -0.0001f)
            {
                x += step.linear * cosf(ang);
                y += step.linear * sinf(ang);
            }
            else
            {
                float fx = cosf(ang), fy = sinf(ang);
                float sx = fy * step.linear / step.angular;
                float sy = -fx * step.linear / step.angular;
                float nsx = sx * cosf(step.angular) - sy * sinf(step.angular);
                float nsy = sx * sinf(step.angular) + sy * cosf(step.angular);
                x = x - sx + nsx;
                y = y - sy + nsy;
                ang += step.angular;
            }
            while (ang > F_PI)
                ang -= F_PI * 2.0f;
            while (ang <= -F_PI)
                ang += F_PI * 2.0f;
            times++;
        } while (!approach(x, y, tx, ty, tr));
        arrived++;
        printf("成功抵达第%d个目标点\n", arrived);
        if (times >= maxTries)
            break;
    }

end:
    if (arrived < goalCount)
        printf("\n任务失败，抵达目标点%d个，尝试次数%d次，得分%d\n", arrived, times, 10 * arrived / goalCount);
    else if (times > fullScoreMaxTries)
        printf("\n任务成功，尝试次数%d次，得分%d\n", times, 10 + 10 * (maxTries - times) / (maxTries - fullScoreMaxTries));
    else
        printf("\n任务成功，尝试次数%d次，得分20\n", times);
    fflush(stdout);
    return 0;
}
