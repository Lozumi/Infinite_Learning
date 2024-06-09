#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 120
#define FALSE 0
#define TRUE 1

int BeenInQueue[MAX_VERTEX_NUM] = {FALSE};
int flag = FALSE;

typedef struct ArcNode { // 弧
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

typedef struct VNode { // 顶点
    int data; // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode;

typedef struct ALGraph { // 图
    VNode vertices[MAX_VERTEX_NUM]; // 图的各个顶点
    int vexnum, arcnum; // 图的当前结点数和弧数
} ALGraph;

typedef struct NODE { // 队列结点
    int n;
    struct NODE* next;
} NODE;

typedef struct Queue { // 队列
    NODE* front;
    NODE* rear;
} Queue;

void graph_initialize(ALGraph* graph) { // 图的初始化
    graph->vexnum = 0;
    graph->arcnum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        graph->vertices[i].data = 0;
        graph->vertices[i].firstarc = NULL;
    }
}

void arcnode_initialize(ArcNode* arcnode) { // 弧结点的初始化
    arcnode->adjvex = 0;
    arcnode->nextarc = NULL;
}

ArcNode* arcnode_create() { // 弧结点的创建
    ArcNode* arcnode = (ArcNode*)malloc(sizeof(ArcNode));
    arcnode_initialize(arcnode);
    return arcnode;
}

ALGraph* graph_create() { // 图的创建
    ALGraph* graph = (ALGraph*)malloc(sizeof(ALGraph));
    graph_initialize(graph);
    int n, m; // n是顶点数，m是边数
    scanf("%d %d", &n, &m);
    graph->vexnum = n;
    graph->arcnum = m;

    for (int i = 0; i < graph->vexnum; i++) { // 读入顶点信息
        int temp;
        scanf("%d", &temp);
        graph->vertices[i].data = temp;
        graph->vertices[i].firstarc = NULL;
    }

    for (int j = 0; j < graph->arcnum; j++) { // 读入弧信息
        int a, b;
        scanf("%d %d", &a, &b);

        int i = 0;
        while (i < graph->vexnum) {
            if (graph->vertices[i].data == a) break;
            i++;
        }

        ArcNode* arcnode = arcnode_create();
        arcnode->adjvex = b;

        // 头插法插入一个结点
        arcnode->nextarc = graph->vertices[i].firstarc;
        graph->vertices[i].firstarc = arcnode;
    }

    return graph;
}

void queue_initialize(Queue* qptr) { // 队列的初始化
    qptr->front = qptr->rear = NULL;
}

Queue* queue_create() { // 队列的创建
    Queue* qptr = (Queue*)malloc(sizeof(Queue));
    if (qptr != NULL) {
        qptr->front = qptr->rear = NULL;
    } else {
        printf("Out of space!\n");
    }
    return qptr;
}

int IsQueueEmpty(Queue* qptr) { // 队列是否为空
    return qptr->front == NULL;
}

void InQueue(Queue* qptr, int x) { // 入队
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if (p == NULL) {
        printf("Out of space!\n");
    } else {
        p->n = x;
        p->next = NULL;
        if (IsQueueEmpty(qptr)) {
            qptr->front = qptr->rear = p;
        } else {
            qptr->rear->next = p;
            qptr->rear = p;
        }
    }
}

int OutQueue(Queue* qptr) { // 出队
    if (IsQueueEmpty(qptr)) {
        printf("Empty queue.\n");
        return 0;
    } else {
        NODE* p = qptr->front;
        qptr->front = qptr->front->next;
        int x = p->n;
        free(p);
        return x;
    }
}

int GetQueueValue(Queue* queue) { // 获取队头
    return IsQueueEmpty(queue) ? -1 : queue->front->n;
}

void Recursion(ALGraph* graph, int tail, Queue* queue) { // 递归搜索
    if (GetQueueValue(queue) == tail) {
        flag = TRUE;
        return;
    }

    int a = OutQueue(queue);
    int i;
    for (i = 0; i < graph->vexnum; i++) {
        if (graph->vertices[i].data == a) break;
    }

    ArcNode* temp = graph->vertices[i].firstarc;
    while (temp != NULL) {
        if (!BeenInQueue[temp->adjvex]) {
            InQueue(queue, temp->adjvex);
            BeenInQueue[temp->adjvex] = TRUE;
        }
        temp = temp->nextarc;
    }

    if (GetQueueValue(queue) != -1) {
        Recursion(graph, tail, queue);
    }
}

void BFS(ALGraph* graph, int head, int tail) { // 广度优先搜索
    Queue* queue = queue_create();
    InQueue(queue, head);
    BeenInQueue[head] = TRUE;
    Recursion(graph, tail, queue);
}

int main() {
    ALGraph* graph = graph_create();
    int begin, end;
    scanf("%d %d", &begin, &end); // 读入待搜索的弧信息
    BFS(graph, begin, end);
    if (flag == TRUE) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}
