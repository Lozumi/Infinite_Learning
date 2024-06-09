// DS Exp EC-7
// 20240526 刘黎可

#include <stdio.h>
#include <stdlib.h>

#define MAX_VER_NUM 20

typedef struct {
    int vertex[MAX_VER_NUM];
    int weight[MAX_VER_NUM][MAX_VER_NUM];
    int num_vex; // 顶点数
} AdjMatrix;

// 弗洛伊德算法，计算最短路径和前驱顶点
void Floyd(AdjMatrix A, int D[MAX_VER_NUM][MAX_VER_NUM], int P[MAX_VER_NUM][MAX_VER_NUM]);

// 创建邻接矩阵
AdjMatrix* CreateMatrix(int n);

// 打印最短路径
void PrintMinPath(AdjMatrix A, int P[MAX_VER_NUM][MAX_VER_NUM]);

int main() {
    int n;
    scanf("%d", &n);
    AdjMatrix* A = CreateMatrix(n);
    int D[MAX_VER_NUM][MAX_VER_NUM]; // 存储最短路径
    int P[MAX_VER_NUM][MAX_VER_NUM]; // 存储最短路径的前驱顶点
    Floyd(*A, D, P);
    PrintMinPath(*A, P);
    return 0;
}

// 创建邻接矩阵
AdjMatrix* CreateMatrix(int n) {
    AdjMatrix* A = (AdjMatrix*)malloc(sizeof(AdjMatrix));
    if (A == NULL) {
        return NULL;
    }
    A->num_vex = n;
    for (int i = 0; i < A->num_vex; i++) {
        for (int j = 0; j < A->num_vex; j++) {
            scanf("%d", &A->weight[i][j]);
        }
    }
    return A;
}

// 弗洛伊德算法，计算最短路径和前驱顶点
void Floyd(AdjMatrix A, int D[MAX_VER_NUM][MAX_VER_NUM], int P[MAX_VER_NUM][MAX_VER_NUM]) {
    // 初始化最短路径矩阵和前驱顶点矩阵
    for (int i = 0; i < A.num_vex; i++) {
        for (int j = 0; j < A.num_vex; j++) {
            D[i][j] = A.weight[i][j];
            P[i][j] = j; // 默认前驱顶点是终点本身
        }
    }
    // 弗洛伊德算法核心部分，计算最短路径和前驱顶点
    for (int i = 0; i < A.num_vex; i++) {
        for (int j = 0; j < A.num_vex; j++) {
            for (int k = 0; k < A.num_vex; k++) {
                if (D[j][k] > D[j][i] + D[i][k]) {
                    D[j][k] = D[j][i] + D[i][k]; // 更新最短路径
                    P[j][k] = P[j][i]; // 更新最短路径终点的前驱顶点
                }
            }
        }
    }
}

// 打印最短路径
void PrintMinPath(AdjMatrix A, int P[MAX_VER_NUM][MAX_VER_NUM]) {
    int n;
    scanf("%d", &n);
    int j[MAX_VER_NUM][2]; // 存储需要输出的路径
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &j[i][0], &j[i][1]);
    }
    for (int i = 0; i < n; i++) {
        int tmp = j[i][0];
        while (tmp != j[i][1]) {
            printf("%d\n", tmp);
            tmp = P[tmp][j[i][1]]; // 更新当前顶点为下一个顶点的前驱顶点
        }
        printf("%d\n", tmp); // 输出终点
    }
}
