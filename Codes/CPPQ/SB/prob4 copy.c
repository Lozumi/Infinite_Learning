#include <stdio.h>

#define ROWS 8
#define COLS 8
#define MINES 10

int mineField[ROWS][COLS] = {0}; // 地雷分布
int opened[ROWS][COLS] = {0};    // 记录已经打开的地块

// 检查坐标是否在合法范围内
int isValid(int x, int y)
{
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

// 打印地图
void printMap()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", opened[i][j]);
        }
        printf("\n");
    }
}

// 自动打开相邻地块
void openAdjacent(int x, int y)
{
    if (!isValid(x, y) || opened[x][y] || mineField[x][y])
    {
        return; // 坐标不合法或者已经打开或者是地雷
    }

    opened[x][y] = 1;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int mineCount = 0;
    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && mineField[newX][newY])
        {
            mineCount++;
        }
    }

    if (mineCount == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            openAdjacent(newX, newY);
        }
    }
}

int main()
{
    // 输入地雷坐标
    for (int i = 0; i < MINES; i++)
    {
        int x, y;
        scanf("%d %d", &y, &x); // 反转坐标顺序
        mineField[x][y] = 1;
    }

    // 输入被挖开的地块坐标
    int startY, startX; // 反转坐标顺序
    scanf("%d %d", &startY, &startX);

    openAdjacent(startX, startY);

    // 打印地图
    printMap();

    return 0;
}
