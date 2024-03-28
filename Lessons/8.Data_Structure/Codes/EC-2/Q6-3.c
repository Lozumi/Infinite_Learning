#include <stdio.h>
#include <stdlib.h>

// 定义双向循环链表节点结构体
typedef struct DuLNode
{
    char data;
    int freq;
    struct DuLNode *pre, *next;
} DuLNode, *DuLinkList;

// 初始化双向循环链表
void InitDuLinkList(DuLinkList *L)
{
    *L = (DuLNode *)malloc(sizeof(DuLNode));
    (*L)->pre = *L;
    (*L)->next = *L;
}

// 插入元素到双向循环链表尾部
void InsertDuLinkList(DuLinkList L, char data)
{
    DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
    newNode->data = data;
    newNode->freq = 0;
    newNode->pre = L->pre;
    newNode->next = L;
    L->pre->next = newNode;
    L->pre = newNode;
}

// 在双向循环链表中查找元素并调整节点位置
DuLNode *Locate(DuLinkList L, char x)
{
    DuLNode *p = L->next;
    while (p != L && p->data != x)
    {
        p = p->next;
    }
    if (p == L)
    {
        return NULL; // 没找到元素，返回空指针
    }
    else
    {
        p->freq++; // 找到元素，频度加1

        // 删除结点
        p->pre->next = p->next;
        p->next->pre = p->pre;

        // 插入到合适的位置
        DuLNode *q = L->next;
        while (q != L && q->freq > p->freq)
        {
            q = q->next;
        }
        if (q == L)
        {
            // 在链表末尾插入
            p->next = q->next;
            q->next = p;
            p->pre = q->pre;
            q->pre = p;
        }
        else
        {
            // 在 q 之前插入
            p->next = q->pre->next;
            q->pre->next = p;
            p->pre = q->pre;
            q->pre = p;
        }
        return p;
    }
}

// 打印双向循环链表
void PrintDuLinkList(DuLinkList L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    DuLinkList L;
    InitDuLinkList(&L);

    // 输入双向循环链表的节点数
    int m;
    scanf("%d", &m);

    // 输入双向循环链表各节点的值
    for (int i = 0; i < m; ++i)
    {
        char data;
        scanf(" %c", &data); // 注意空格，避免读入换行符
        InsertDuLinkList(L, data);
    }

    // 输入被访问的节点数
    int n;
    scanf("%d", &n);

    // 输入被访问的节点
    for (int i = 0; i < n; ++i)
    {
        char x;
        scanf(" %c", &x); // 注意空格，避免读入换行符
        Locate(L, x);
    }

    // 输出符合要求的双向循环链表
    PrintDuLinkList(L);

    return 0;
}
