#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int length;
} SeqList;

void removeCommonElements(SeqList *A, SeqList *B, SeqList *C)
{
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length && k < C->length)
    {
        if (A->data[i] < B->data[j])
        {
            i++;
        }
        else if (A->data[i] > B->data[j])
        {
            j++;
        }
        else
        {
            if (A->data[i] < C->data[k])
            {
                i++;
            }
            else if (A->data[i] > C->data[k])
            {
                k++;
            }
            else
            {
                // A[i] == B[j] == C[k]
                // Remove the common element from A
                for (int x = i; x < A->length - 1; x++)
                {
                    A->data[x] = A->data[x + 1];
                }
                A->length--;
            }
        }
    }
}

int main()
{
    SeqList A, B, C;
    int m, n, p;

    // 输入三个线性表的元素个数
    // printf("请输入三个线性表的元素个数 m, n, p: ");
    scanf("%d %d %d", &m, &n, &p);

    // 输入线性表 A 的元素
    // printf("请输入线性表 A 的元素: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &A.data[i]);
    }
    A.length = m;

    // 输入线性表 B 的元素
    // printf("请输入线性表 B 的元素: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B.data[i]);
    }
    B.length = n;

    // 输入线性表 C 的元素
    // printf("请输入线性表 C 的元素: ");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &C.data[i]);
    }
    C.length = p;

    // // printf("原有线性表A: ");
    // for (int i = 0; i < A.length; i++)
    // {
    //     printf("%d ", A.data[i]);
    // }
    // printf("\n");

    removeCommonElements(&A, &B, &C);

    // printf("修改后线性表A: ");
    for (int i = 0; i < A.length; i++)
    {
        printf("%d ", A.data[i]);
    }
    printf("\n");

    return 0;
}
