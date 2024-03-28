#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;               // 存储的字符
    int count;               // 记录出现次数
    struct Node *pre, *next; // 指向前驱节点和后继节点的指针
} Node;

// 初始化双向链表
Node *initializeList(int n)
{
    Node *head, *p, *q;
    char ch;
    head = (Node *)malloc(sizeof(Node));
    if (!head)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    head->pre = NULL;
    q = head;
    // printf("请输入 %d 个字符：\n", n);
    while (n--)
    {
        p = (Node *)malloc(sizeof(Node));
        if (!p)
        {
            printf("内存分配失败\n");
            exit(1);
        }
        while ((ch = getchar()) == ' ' || ch == '\n')
            ; // 忽略空格和换行符
        p->data = ch;
        p->count = 0;
        p->pre = q;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return head;
}

// 在链表中定位字符并重新排序
Node *locateAndSort(Node *head, int x, int y)
{
    Node *p, *q;
    char ch;
    int i;
    p = head->next;
    while (x--)
    {
        while ((ch = getchar()) == ' ' || ch == '\n')
            ; // 忽略空格和换行符
        while (p)
        {
            if (p->data == ch)
            {
                (p->count)++;
            }
            p = p->next;
        }
        p = head->next;
    }

    for (i = 0; i < y; i++)
    {
        p = head->next;
        q = p;
        while (p)
        {
            if (q->count < p->count)
            {
                q = p;
            }
            p = p->next;
        }
        if (i < y - 1)
        {
            printf("%c ", q->data);
        }
        else
        {
            printf("%c\n", q->data);
        }
        if (q->pre == NULL)
        {
            head->next = q->next;
            q->next->pre = head;
        }
        else if (q->next == NULL)
        {
            q->pre->next = NULL;
        }
        else
        {
            q->pre->next = q->next;
            q->next->pre = q->pre;
        }
        free(q);
    }
    return head;
}

// 输出双向链表中的字符
void output(Node *head)
{
    Node *p = head->next;
    // printf("输出双向链表中的字符：\n");
    while (p)
    {
        if (p->next == NULL)
        {
            printf("%c\n", p->data);
        }
        else
        {
            printf("%c ", p->data);
        }
        p = p->next;
    }
}

int main()
{
    int m, n;
    Node *head;
    // printf("请输入节点数 m 和被访问的节点数 n：\n");
    scanf("%d %d", &m, &n);
    getchar(); // 吸收换行符

    head = initializeList(m);         // 初始化双向链表
    head = locateAndSort(head, n, m); // 在链表中定位并重新排序
    output(head);                     // 输出链表中的字符
    return 0;
}
