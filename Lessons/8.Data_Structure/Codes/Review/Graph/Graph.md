### 无向图的数据结构、构造及应用

#### 数据结构：邻接矩阵

邻接矩阵是表示图的一种方式。对于一个有 `n` 个顶点的无向图，使用一个 `n x n` 的矩阵 `adj` 来表示，其中 `adj[i][j]` 表示顶点 `i` 和顶点 `j` 之间是否存在边。如果存在边，则 `adj[i][j] = 1`，否则 `adj[i][j] = 0`。

```c
#include <stdio.h>
#include <stdlib.h>

// 定义图的数据结构
typedef struct {
    int n;          // 顶点的数量
    int **adj;      // 邻接矩阵
} Graph;
```

#### 构造无向图

构造无向图包括初始化邻接矩阵、添加边等操作。

##### 初始化图

```c
Graph* createGraph(int n) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->adj = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        graph->adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}
```

##### 添加边

由于是无向图，所以 `adj[i][j] = adj[j][i] = 1`。

```c
void addEdge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph->n && v >= 0 && v < graph->n) {
        graph->adj[u][v] = 1;
        graph->adj[v][u] = 1;
    }
}
```

#### 应用

1. **计算与某个节点连通的节点个数**：

```c
void dfs(Graph *graph, int v, int *visited) {
    visited[v] = 1;
    for (int i = 0; i < graph->n; i++) {
        if (graph->adj[v][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int countConnectedNodes(Graph *graph, int v0) {
    int *visited = (int*)malloc(graph->n * sizeof(int));
    for (int i = 0; i < graph->n; i++) {
        visited[i] = 0;
    }
    
    dfs(graph, v0, visited);
    
    int count = 0;
    for (int i = 0; i < graph->n; i++) {
        if (visited[i] == 1) {
            count++;
        }
    }
    
    free(visited);
    return count;
}
```

#### 主函数和示例

```c
int main() {
    int n, u, v;
    
    printf("请输入顶点数量: ");
    scanf("%d", &n);
    
    Graph *graph = createGraph(n);
    
    printf("请输入边，输入-1 -1结束:\n");
    while (1) {
        scanf("%d %d", &u, &v);
        if (u
```