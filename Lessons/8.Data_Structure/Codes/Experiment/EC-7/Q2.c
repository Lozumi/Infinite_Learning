// DS Exp EC-7
// 20240526 刘黎可

#include <stdio.h>
#include <stdlib.h>

#define INF 10000
#define MAX_VEX 120
#define MAX_STEP 3000

struct Graph {
    int vexNum;
    int graph[MAX_VEX][MAX_VEX];
};

struct Step {
    int flags[MAX_STEP];
    int stepN[MAX_STEP];
};

// 函数声明
void createNewGraphList(struct Graph *g);
void Dijkstra(struct Step *s, struct Graph *g);
void clearStep(struct Step *s, struct Graph *g);
void initializeStep(struct Step *s, struct Graph *g);
int hasUnvisitedNodes(struct Step *s, struct Graph *g);
int findMinStep(struct Step *s, struct Graph *g);
void updateSteps(struct Step *s, struct Graph *g, int minNode);

int main() {
    struct Graph g;
    struct Step s;
    createNewGraphList(&g);
    Dijkstra(&s, &g);
    return 0;
}

// 初始化邻接图
void createNewGraphList(struct Graph *g) {
    int i, j;
    scanf("%d", &(g->vexNum));
    for (i = 0; i < g->vexNum; i++) {
        for (j = 0; j < g->vexNum; j++) {
            scanf("%d", &(g->graph[i][j]));
        }
    }
}

// Dijkstra算法实现
void Dijkstra(struct Step *s, struct Graph *g) {
    int end, endStep;
    int minNode;
    clearStep(s, g);
    initializeStep(s, g);
    scanf("%d", &end);
    endStep = s->stepN[end]; // 初始化最终步数
    while (hasUnvisitedNodes(s, g)) {
        minNode = findMinStep(s, g);
        updateSteps(s, g, minNode);
        if (s->flags[end]) { // 若是在可处理环节或未激活
            if (endStep != s->stepN[end]) { // 如果最终步数不一致，则代表最小路径改变
                endStep = s->stepN[end]; // 更新最小路径
                printf("%d\n", minNode); // 输出此处的点
            }
        } else { // 处理过，则输出并退出循环结束程序
            printf("%d\n", minNode);
            break;
        }
    }
}

// 清理步数数据
void clearStep(struct Step *s, struct Graph *g) {
    for (int i = 0; i < g->vexNum; i++) {
        s->flags[i] = -1; // -1为未激活，1为可处理，0为已处理
        s->stepN[i] = 0; // 步数清零
    }
}

// 初始化步数
void initializeStep(struct Step *s, struct Graph *g) {
    int i;
    int start;
    scanf("%d", &start);
    printf("%d\n", start);
    for (i = 0; i < g->vexNum; i++) {
        if (g->graph[start][i] != INF) { // 若联通
            s->flags[i] = 1; // 放入可处理
            s->stepN[i] = g->graph[start][i]; // 初始化和首元素相连节点的步数
        }
    }
    s->flags[start] = 0; // 首元素标记为已处理
    s->stepN[start] = 0;
}

// 判断是否还有未处理节点
int hasUnvisitedNodes(struct Step *s, struct Graph *g) {
    for (int i = 0; i < g->vexNum; i++) {
        if (s->flags[i] == 1) {
            return 1;
        }
    }
    return 0;
}

// 找到步数最小的未处理节点
int findMinStep(struct Step *s, struct Graph *g) {
    int i, min = INF, minNode = -1;
    for (i = 0; i < g->vexNum; i++) {
        if (s->flags[i] == 1 && s->stepN[i] < min) {
            min = s->stepN[i];
            minNode = i;
        }
    }
    return minNode;
}

// 更新步数
void updateSteps(struct Step *s, struct Graph *g, int minNode) {
    int i;
    int minStepN = s->stepN[minNode];
    s->flags[minNode] = 0; // 将此次处理节点标记为已处理

    for (i = 0; i < g->vexNum; i++) {
        if (g->graph[minNode][i] != INF) {
            if (s->flags[i] == 1) { // 若和此次处理节点相连且可处理
                if (s->stepN[i] > g->graph[minNode][i] + minStepN) {
                    s->stepN[i] = g->graph[minNode][i] + minStepN; // 更新步数
                }
            } else if (s->flags[i] == -1) { // 若和此次处理节点相连但未激活
                s->flags[i] = 1; // 激活节点
                s->stepN[i] = g->graph[minNode][i] + minStepN; // 更新步数
            }
        }
    }
}

