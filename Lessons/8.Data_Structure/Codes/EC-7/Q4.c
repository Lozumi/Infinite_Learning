#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VEX 100
#define INF INT_MAX

typedef struct {
    int vexs[MAX_VEX]; // 顶点数组
    int arcs[MAX_VEX][MAX_VEX]; // 邻接矩阵
    int vexnum, arcnum; // 顶点数和边数
} ALGraph;

int getVertexIndex(ALGraph *G, int vertex) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vexs[i] == vertex) {
            return i;
        }
    }
    return -1;
}

void createGraph(ALGraph *G, int vexnum, int arcnum) {
    G->vexnum = vexnum;
    G->arcnum = arcnum;

    for (int i = 0; i < G->vexnum; i++) {
        G->vexs[i] = i;
    }

    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < G->arcnum; i++) {
        int v1, v2, weight;
        scanf("%d %d %d", &v1, &v2, &weight);
        int m = getVertexIndex(G, v1);
        int n = getVertexIndex(G, v2);
        G->arcs[m][n] = weight;
        G->arcs[n][m] = weight; // 无向图
    }
}

void dijkstra(ALGraph *G, int start, int *dist) {
    int visited[MAX_VEX] = {0};

    for (int i = 0; i < G->vexnum; i++) {
        dist[i] = G->arcs[start][i];
    }
    dist[start] = 0;
    visited[start] = 1;

    for (int i = 1; i < G->vexnum; i++) {
        int minDist = INF;
        int k = -1;

        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j] && dist[j] < minDist) {
                k = j;
                minDist = dist[j];
            }
        }

        if (k == -1) break;

        visited[k] = 1;

        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j] && G->arcs[k][j] != INF && (minDist + G->arcs[k][j] < dist[j])) {
                dist[j] = minDist + G->arcs[k][j];
            }
        }
    }
}

void printResults(ALGraph *G, int *dist) {
    for (int i = 1; i < G->vexnum; i++) {
        if (dist[i] != INF) {
            printf("0 %d %d\n", G->vexs[0], G->vexs[i], dist[i]);
        } else {
            printf("0 %d -1\n", G->vexs[0], G->vexs[i]);
        }
    }
}

int main() {
    ALGraph G;
    int dist[MAX_VEX];
    int vexnum, arcnum;

    scanf("%d %d", &vexnum, &arcnum);

    createGraph(&G, vexnum, arcnum);
    dijkstra(&G, 0, dist);
    printResults(&G, dist);

    return 0;
}
