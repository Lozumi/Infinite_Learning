#include <stdio.h>

typedef struct{
    int row,col;
    int value;
}Triple;

typedef struct {
    Triple data[100];
    int m,n,t;
    int rpos[100];
} TSMatrix;

void InitMatrix(TSMatrix *A){
    int i,j,k;
    scanf("%d %d", &A->m,&A->n);
    A->t=0;
    while(1){
        scanf("%d %d", &i,&j,&k);
        if (i==0&&j==0&&k==0)
            break;
        A->t++;
        A->data[A->t].row=i;
        A->data[A->t].col=j;
        A->data[A->t].value=k;
        A->rpos[i]++;
    }

    for (int i=1;i<=A->m;i++)
        A->rpos[i]+=A->rpos[i-1];
    for (int i=1;i<=A->m;i++)
        A->rpos[i]=A->rpos[i-1]+1;
}

TSMatrix MutiplyMatrix(TSMatrix A,TSMatrix B){
    TSMatrix C;
    C.m=A.m;
    C.n=A.n;
    C.t=0;
    int t[1000]={0};
    int x,y,z,s;

    if(A.t*B.t!=0){
        for (int i=1;i<=A.m;i++){
            for (int j=1;j<=A.n;j++)
                t[j]=0;
            C.rpos[i]=C.t+1;
            if (i<A.m)
                x=A.rpos[i+1];
            else
                x=A.t+1;
        }
    }
}