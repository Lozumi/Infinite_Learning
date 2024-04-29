#include<stdio.h>  
#include<stdlib.h>  

typedef struct {  
    int *Data;  
    int front;  
    int rear;  
    int K;  
} Queue;  

Queue* CreateQueue(int k)  
{  
    Queue *Q;  
    Q = (Queue*)malloc(sizeof(Queue));  
    Q->K = k + 1;  
    Q->Data = (int*)malloc(sizeof(int) * Q->K);  
    Q->front = Q->rear = 0;  
    return Q;  
}  

void AddQ(Queue *Q, int item)  
{  
    if ((Q->rear + 1) % Q->K == Q->front)  
    {  
        printf("队列已满，无法添加元素\n");  
        return;  
    }  
    else {  
        Q->rear = (Q->rear + 1) % Q->K;  
        Q->Data[Q->rear] = item;  
    }  
}  

int DeleteQ(Queue *Q)  
{  
    if (Q->rear == Q->front) {  
        printf("队列为空\n");  
        return 0;  
    }  
    else {  
        Q->front = (Q->front + 1) % Q->K;  
        return Q->Data[Q->front];  
    }  
}  

void Fibonacci(int k, int max)  
{  
    if (k <= 0 || max <= 0) {  
        printf("参数错误，请输入大于0的整数\n");  
        return;  
    }  

    Queue *q;  
    int i, item, t = 1, j = 0;  
    q = CreateQueue(k);  
    for (i = 0; i < k; i++)  
        if (i == k - 1)  
            AddQ(q, 1);  
        else  
            AddQ(q, 0);  
    while (t <= max) {  
        j++;  
        DeleteQ(q);  
        AddQ(q, t);  
        t = 0;  
        for (i = 0; i < k; i++) {  
            item = DeleteQ(q);  
            t += item;  
            AddQ(q, item);  
        }  
    }  
    for (i = 0; i < k; i++) {  
        item = DeleteQ(q);  
        printf("%d ", item);  
        AddQ(q, item);  
    }  
    free(q->Data);  
    free(q);  
}  

int main()  
{  
    int k, max;  
    // printf("Enter max number and k: ");  
    scanf("%d %d", &max, &k);  
    Fibonacci(k, max);  
    return 0;  
}  
