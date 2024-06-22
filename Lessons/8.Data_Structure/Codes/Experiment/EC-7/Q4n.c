// DS Exp EC-7
// 20240526 刘黎可

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// 弗洛伊德算法，计算最短路径和前驱顶点
void Floyd(int vertex_count, int weights[MAX_VERTICES][MAX_VERTICES], int dist[MAX_VERTICES][MAX_VERTICES], int pred[MAX_VERTICES][MAX_VERTICES]);

// 创建邻接矩阵
void CreateMatrix(int vertex_count, int weights[MAX_VERTICES][MAX_VERTICES]);

// 打印最短路径
void PrintMinPath(int vertex_count, int pred[MAX_VERTICES][MAX_VERTICES]);

int main() {
    int vertex_count;
    scanf("%d", &vertex_count);
    int weights[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES][MAX_VERTICES]; // 存储最短路径
    int pred[MAX_VERTICES][MAX_VERTICES]; // 存储最短路径的前驱顶点
    CreateMatrix(vertex_count, weights);
    Floyd(vertex_count, weights, dist, pred);
    PrintMinPath(vertex_count, pred);
    return 0;
}

// 创建邻接矩阵
void CreateMatrix(int vertex_count, int weights[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            scanf("%d", &weights[i][j]);
        }
    }
}

// 弗洛伊德算法，计算最短路径和前驱顶点
void Floyd(int vertex_count, int weights[MAX_VERTICES][MAX_VERTICES], int dist[MAX_VERTICES][MAX_VERTICES], int pred[MAX_VERTICES][MAX_VERTICES]) {
    // 初始化最短路径矩阵和前驱顶点矩阵
    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            dist[i][j] = weights[i][j];
            pred[i][j] = j; // 默认前驱顶点是终点本身
        }
    }
    // 弗洛伊德算法核心部分，计算最短路径和前驱顶点
    for (int k = 0; k < vertex_count; k++) {
        for (int i = 0; i < vertex_count; i++) {
            for (int j = 0; j < vertex_count; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // 更新最短路径
                    pred[i][j] = pred[i][k]; // 更新最短路径终点的前驱顶点
                }
            }
        }
    }
}

// 打印最短路径
void PrintMinPath(int vertex_count, int pred[MAX_VERTICES][MAX_VERTICES]) {
    int path_count;
    scanf("%d", &path_count);
    int paths[MAX_VERTICES][2]; // 存储需要输出的路径
    for (int i = 0; i < path_count; i++) {
        scanf("%d %d", &paths[i][0], &paths[i][1]);
    }
    for (int i = 0; i < path_count; i++) {
        int current_vertex = paths[i][0];
        while (current_vertex != paths[i][1]) {
            printf("%d\n", current_vertex);
            current_vertex = pred[current_vertex][paths[i][1]]; // 更新当前顶点为下一个顶点的前驱顶点
        }
        printf("%d\n", current_vertex); // 输出终点
    }
}
