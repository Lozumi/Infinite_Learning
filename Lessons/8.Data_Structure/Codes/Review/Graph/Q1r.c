#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS (int graph[MAX][MAX],int visited[MAX],int v,int n){
    visited[v]=1;
    for (int i=0;i<n;i++){
        if (graph[v][i]==1&&(!visited[i])){
            DFS(graph,visited,i,n);
        }
    }
}

int countConnectedNodes(int graph[MAX][MAX],int n){
    int visited[MAX]={0};
    DFS(graph,visited,0,n);

    int count=0;
    for(int i=0;i<n;i++){
        if (visited[i]==1)
            count++;
    }
    return count;
}

int main(){
    int n,count;
    int graph[MAX][MAX]={0};

    scanf("%d", &n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
    }

    count = countConnectedNodes(graph,n)-1;
    printf("%d",count);
}