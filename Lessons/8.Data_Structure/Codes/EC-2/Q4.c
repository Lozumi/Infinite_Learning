// 假设两个按元素值非递减有序排列的线性表 A 和 B ，均以单链表作为存储结构，试编写程序，将 A 表和 B 表归并成一个按元素值非递增有序排列的线性表 C ，并要求利用原表（即 A 表和 B 表的）结点空间存放表 C 。

#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 在链表头部插入节点
Node *insert(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 释放链表内存
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 归并操作
Node *mergeLists(Node *A, Node *B)
{
    Node *head = NULL;
    while (A != NULL && B != NULL)
    {
        if (A->data >= B->data)
        {
            head = insert(head, A->data);
            A = A->next;
        }
        else
        {
            head = insert(head, B->data);
            B = B->next;
        }
    }
    while (A != NULL)
    {
        head = insert(head, A->data);
        A = A->next;
    }
    while (B != NULL)
    {
        head = insert(head, B->data);
        B = B->next;
    }
    // 反转链表，使其变为非递增有序排列
    Node *prev = NULL, *current = head, *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 输出单链表
void printList(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d", p->data);
        if (p->next != NULL)
        {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *A = NULL, *B = NULL;
    int m, n, num;

    // 输入线性表 A 的元素个数和元素
    // printf("请输入线性表 A 和 B 中元素个数: ");
    scanf("%d %d", &m, &n);

    // 输入线性表 A 的元素
    // printf("请输入线性表 A 的元素: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        A = insert(A, num);
    }

    // 输入线性表 B 的元素
    // printf("请输入线性表 B 的元素: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        B = insert(B, num);
    }

    // 归并操作
    Node *C = mergeLists(A, B);

    // 输出结果
    // printf("归并后的单链表 C: ");
    printList(C);

    // 释放链表内存
    freeList(C);

    return 0;
}
