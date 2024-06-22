有向图（Directed Graph）是一种图，其中的边有方向性。通常可以用邻接矩阵或邻接表来表示有向图。这里我们将使用邻接矩阵来表示有向图，并提供创建方法及一些基本操作。

### 数据结构

使用邻接矩阵表示有向图。邻接矩阵是一个二维数组，其中 `matrix[i][j]` 表示从节点 `i` 到节点 `j` 的边。如果存在边，则该值为 `1`（或权重值），否则为 `0`。

```c
#define MAX 100 // 定义最大节点数

typedef struct {
    int matrix[MAX][MAX]; // 邻接矩阵
    int n; // 图中节点的数量
} DirectedGraph;
```

### 创建有向图

创建有向图的基本步骤包括初始化邻接矩阵和添加边。以下是创建和操作有向图的代码示例：

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 有向图的数据结构
typedef struct {
    int matrix[MAX][MAX]; // 邻接矩阵
    int n; // 图中节点的数量
} DirectedGraph;

// 初始化有向图
void initGraph(DirectedGraph *graph, int n) {
    graph->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->matrix[i][j] = 0; // 初始化为没有边
        }
    }
}

// 添加边
void addEdge(DirectedGraph *graph, int from, int to) {
    if (from >= 0 && from < graph->n && to >= 0 && to < graph->n) {
        graph->matrix[from][to] = 1; // 添加一条从from到to的边
    }
}

// 打印邻接矩阵
void printGraph(DirectedGraph *graph) {
    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    DirectedGraph graph;
    initGraph(&graph, n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (from to):\n");
    for (int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(&graph, from, to);
    }

    printf("Adjacency Matrix of the Directed Graph:\n");
    printGraph(&graph);

    return 0;
}
```

### 示例输入和输出

#### 输入
```
Enter the number of nodes: 4
Enter the number of edges: 4
Enter the edges (from to):
0 1
1 2
2 3
3 0
```

#### 输出
```
Adjacency Matrix of the Directed Graph:
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
```

### 解释
- **数据结构**：`DirectedGraph` 使用邻接矩阵表示有向图。
- **初始化图**：`initGraph` 函数将所有边初始化为 `0`。
- **添加边**：`addEdge` 函数在指定的节点之间添加边。
- **打印图**：`printGraph` 函数打印邻接矩阵，以便可视化图的结构。

这个基本的实现可以扩展来处理更多复杂的操作，例如删除边、计算出度和入度、以及图的遍历（如深度优先搜索和广度优先搜索）。