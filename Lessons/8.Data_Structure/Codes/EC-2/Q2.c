#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 初始化单链表
Node *initList(int *arr, int n)
{
    Node *head = NULL, *p;
    int i;
    for (i = 0; i < n; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = arr[i];
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            p = head;
        }
        else
        {
            p->next = node;
            p = p->next;
        }
    }
    return head;
}

// 就地逆置单链表
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
    return prev; // 返回逆置后的头节点
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
    int elenum, i;
    // 输入线性表元素个数
    // printf("请输入线性表元素个数: ");
    scanf("%d", &elenum);
    int arr[elenum];

    // 输入线性表元素
    // printf("请输入线性表元素: ");
    for (i = 0; i < elenum; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 使用数组存储结构逆置
    // printf("使用数组存储结构逆置结果为: ");
    for (i = elenum - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
        if (i != 0)
        {
            printf(" ");
        }
    }
    printf("\n");

    // 使用单链表存储结构逆置
    // printf("使用单链表存储结构逆置结果为: ");
    Node *head = initList(arr, elenum);
    head = reverseList(head);
    printList(head);

    return 0;
}
