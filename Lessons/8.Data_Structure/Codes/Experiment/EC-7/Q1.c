// DS Exp EC-7
// 20240526 刘黎可

#include <stdio.h>
#include <stdlib.h>

#define INF 10000

struct Graph {
    int vexNum;
    int graph[120][120];
};

struct Step {
    int flags[3000];
    int stepN[3000];
};

// 函数声明
void run();
void createGraph(struct Graph *g);
void dijkstra(struct Step *s, struct Graph *g);
void initializeSteps(struct Step *s, struct Graph *g);
int hasUnvisitedNodes(struct Step *s, struct Graph *g);
int findMinStep(struct Step *s, struct Graph *g);
void updateSteps(struct Step *s, struct Graph *g, int minNode);
void printResults(struct Step *s, struct Graph *g);

int main() {
    run();
    return 0;
}

void run() {
    struct Graph g;
    struct Step s;
    createGraph(&g);
    dijkstra(&s, &g);
    printResults(&s, &g);
}

void createGraph(struct Graph *g) {
    int i, j;
    scanf("%d", &(g->vexNum));
    for (i = 0; i < g->vexNum; i++) {
        for (j = 0; j < g->vexNum; j++) {
            scanf("%d", &(g->graph[i][j]));
        }
    }
}

void dijkstra(struct Step *s, struct Graph *g) {
    int minNode;
    initializeSteps(s, g);
    while (hasUnvisitedNodes(s, g)) {
        minNode = findMinStep(s, g);
        updateSteps(s, g, minNode);
    }
}

void initializeSteps(struct Step *s, struct Graph *g) {
    int i;
    for (i = 0; i < g->vexNum; i++) {
        s->flags[i] = -1;
        s->stepN[i] = INF;
        if (g->graph[0][i] != INF) {
            s->flags[i] = 1;
            s->stepN[i] = g->graph[0][i];
        }
    }
    s->flags[0] = 0;
    s->stepN[0] = 0;
}

int hasUnvisitedNodes(struct Step *s, struct Graph *g) {
    for (int i = 1; i < g->vexNum; i++) {
        if (s->flags[i] == 1) {
            return 1;
        }
    }
    return 0;
}

int findMinStep(struct Step *s, struct Graph *g) {
    int i, min = INF, minNode = -1;
    for (i = 1; i < g->vexNum; i++) {
        if (s->flags[i] == 1 && s->stepN[i] < min) {
            min = s->stepN[i];
            minNode = i;
        }
    }
    return minNode;
}

void updateSteps(struct Step *s, struct Graph *g, int minNode) {
    int i;
    int minStepN = s->stepN[minNode];
    s->flags[minNode] = 0;

    for (i = 0; i < g->vexNum; i++) {
        if (g->graph[minNode][i] != INF && s->flags[i] != 0) {
            int newDist = minStepN + g->graph[minNode][i];
            if (s->flags[i] == 1) {
                if (s->stepN[i] > newDist) {
                    s->stepN[i] = newDist;
                }
            } else if (s->flags[i] == -1) {
                s->flags[i] = 1;
                s->stepN[i] = newDist;
            }
        }
    }
}

void printResults(struct Step *s, struct Graph *g) {
    for (int i = 0; i < g->vexNum; i++) {
        printf("%d\n", s->stepN[i]);
    }
}
