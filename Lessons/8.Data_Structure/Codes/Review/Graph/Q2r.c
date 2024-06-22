#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int adj[MAX][MAX];
    int n;
}Graph;

void initGraph(Graph *graph, int n){
    graph->n=n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            graph->adj[i][j]=0;
        }
    }
}

void addEdge(Graph *graph, int x, int y){
    graph->adj[x][y]=1;
}

int BFS(Graph *graph, int start){
    int queue[MAX],front=0,rear=0;
    int visited[MAX]={0};
    int distance[MAX]={0};
    int maxDistance=0;

    queue[rear++]=start;
    visited[start]=1;

    while(front<rear){
        int current=queue[front++];
        for(int i=0;i<graph->n;i++){
            if (graph->adj[current][i]==1&&!visited[i]){
                queue[rear++]=i;
                visited[i]=1;
                distance[i]=distance[current]+1;
                if(distance[i]>maxDistance)
                    maxDistance=distance[i];
            }
        }
    }
    return maxDistance;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    Graph graph;
    initGraph(&graph,n);

    for (int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        addEdge(&graph,&x,&y);
    }

    int result=BFS(&graph,0);
    printf("%d\n",result);

    return 0;
}