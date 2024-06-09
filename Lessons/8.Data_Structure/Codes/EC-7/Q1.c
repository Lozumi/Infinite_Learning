#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 105

int visited[MAX_SIZE];

typedef struct EdgeNode {  // 边点
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {  // 顶点
    int data;
    EdgeNode* firstedge;
} VertexNode, AdjList[MAX_SIZE];

typedef struct LGraph {  // 图
    int edgenum, nodenum;
    AdjList adjlist;
} LGraph;

LGraph* createGraph() {  // 创建图
    LGraph* G = (LGraph*)malloc(sizeof(LGraph));
    scanf("%d %d", &(G->nodenum), &(G->edgenum));
    int i, j;
    
    // 初始化顶点表
    for (i = 1; i <= G->nodenum; i++) {
        int temp;
        scanf("%d", &temp);
        G->adjlist[temp].data = temp;  // 顶点表下标是输入的temp而不是i
        G->adjlist[temp].firstedge = NULL;  // 初始化顶点的边表指针
    }
    
    // 初始化边表
    for (j = 1; j <= G->edgenum; j++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);  // 读入有向边的"起点"和"终点"
        EdgeNode* e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = temp2;
        e->next = G->adjlist[temp1].firstedge;  // 头插法
        G->adjlist[temp1].firstedge = e;
    }
    
    return G;
}

int FLAG = 0;  // 判断是否能通过v2的标志，全局变量

void DFS(LGraph* G, int adjvex, int v2) {  // 深度搜索
    visited[adjvex] = 1;  // 标记已经访问过
    EdgeNode* p = G->adjlist[adjvex].firstedge;
    if (visited[v2] == 1) FLAG = 1;
    while (p) {
        if (!visited[p->adjvex]) {  // 访问未被访问的邻接点
            DFS(G, p->adjvex, v2);
        }
        p = p->next;
    }
}

int DFSTraverse(LGraph* G, int v1, int v2) {
    int i;
    for (i = 1; i <= G->nodenum; i++) {  // 初始化访问数组，标记所有顶点未访问
        visited[i] = 0;
    }
    DFS(G, v1, v2);  // 从v1点开始深度搜索
    return FLAG;
}

int main() {
    LGraph* G = createGraph();
    int v1, v2, flag = 0;
    scanf("%d %d", &v1, &v2);  // 要寻找路径的起点和终点
    flag = DFSTraverse(G, v1, v2);
    if (flag == 1)
        printf("yes");
    else
        printf("no");
    return 0;
}
