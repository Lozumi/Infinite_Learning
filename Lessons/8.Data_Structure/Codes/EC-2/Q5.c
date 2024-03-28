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

// 删除A表中那些既在B表中出现又在C表中出现的元素
void deleteCommonElements(Node **A, Node *B, Node *C)
{
    Node *prev = NULL, *current = *A;
    while (current != NULL)
    {
        int data = current->data;
        Node *searchB = B, *searchC = C;
        int foundB = 0, foundC = 0;
        // 在B表中查找当前元素
        while (searchB != NULL)
        {
            if (searchB->data == data)
            {
                foundB = 1;
                break;
            }
            searchB = searchB->next;
        }
        // 在C表中查找当前元素
        while (searchC != NULL)
        {
            if (searchC->data == data)
            {
                foundC = 1;
                break;
            }
            searchC = searchC->next;
        }
        // 如果当前元素既在B表中出现又在C表中出现，则删除
        if (foundB && foundC)
        {
            if (prev == NULL)
            {
                *A = current->next;
                free(current);
                current = *A;
            }
            else
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

// 反转单链表
Node *reverseList(Node *head)
{
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
    Node *A = NULL, *B = NULL, *C = NULL;
    int m, n, p, num;

    // 输入线性表 A 的元素个数和元素
    // printf("请输入线性表 A, B, C 中元素个数: ");
    scanf("%d %d %d", &m, &n, &p);

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

    // 输入线性表 C 的元素
    // printf("请输入线性表 C 的元素: ");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &num);
        C = insert(C, num);
    }

    // 删除A表中既在B表中出现又在C表中出现的元素
    deleteCommonElements(&A, B, C);

    // 反转A表，使其按非递减有序排列
    A = reverseList(A);

    // 输出结果
    // printf("修改后的单链表 A: ");
    printList(A);

    // 释放链表内存
    freeList(A);

    return 0;
}
