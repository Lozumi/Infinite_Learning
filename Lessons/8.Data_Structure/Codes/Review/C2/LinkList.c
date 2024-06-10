// 单链表
#include <stdio.h>
#define ElemType int
#define MAXSIZE 100

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

int ListLength(LinkList L) /*求带头节点的单链表L的单链表长度*/
{
    Node *p;
    p = L->next;
    int j = 0; /*用来存放单链表的长度*/
    while (p != NULL)
    {
        j++;
        p = p->next;
    }
    return j;
}

LinkList CreateFromHead(LinkList L)
{
    Node *s;
    char c;
    int flag = 1; /*设置一个标志，初值为1，当输入“$”时，flag为0，建表结束*/
    while (flag)
    {
        c = getchar();
        if (c != '$')
        {
            s = (Node *)malloc(sizeof(Node));
            /*为读入的字符分配存储空间*/
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else
        {
            flag = 0;
        }
    }
}

Node *GetNode(LinkList L, int i)
{ /*在带头结点的单链表L中查找第i个结点，若找到(1<=i<=n)，则返回该结点的存储位置，否则返回NULL*/
    int j;
    Node *p;
    p = L;
    j = 0;
    while ((p->next != NULL) && (j < i))
    {
        p = p->next; /*扫描下一结点*/
        j++;         /*已扫描结点计数器*/
    }
    if (i == j) /*找到了第i个结点*/
        return p;
    else /*找不到，i<=0或i>n*/
        return NULL;
}

Node *LocateNode(LinkList L, ElemType W)
{ /*在带头结点的单链表L中查找结点值等于W的结点，若找到则返回该结点的位置p，否则返回NULL*/
    Node *p;
    p = L->next; /*从表中第一个结点比较*/
    while ((p->next != NULL))
    {
        if (p->data != W)
            p = p->next;
        else
            break; /*已找到结点W，退出循环*/
    }
    return p;
}

void InsNode(LinkList L, int i, ElemType W)
{
    Node *pre, *s;
    pre = L;
    int k = 0;
    while (pre != NULL && k < i - 1)
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre == NULL) /*如当前位置pre为空,表示已经找完还未找到第i个,说明插入位置不合理*/
    {
        printf("插入位置不合理");
        return 1;
    }
    s = (Node *)malloc(sizeof(Node)); /*为e申请一个新的结点,并由s指向它*/
    s->data = e;                      /*将待插入结点值e赋给s的数据域*/
    s->next = pre->next;
    pre->next = s;
    return 0;
}

int DelNode(LinkList L, int i, ElemType *e)
/*在带头结点的单链表L中删除第i个元素,并将删除的元素保存到变量*e中*/
{
    Node *pre, *r;
    pre = L;
    int k = 0;
    while (pre->next != NULL && k < i - 1) /*寻找第i个被删除结点的前驱结点,使pre指向它*/
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre->next == NULL) /* while循环是因为pre->next为NULL或i<1而跳出来的,
                                   因为pre->next为空,没有找到合法的前驱位置,说明删除位置不合法*/
    {
        printf("删除结点的位置i不合理");
        return 1;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);
    return 0;
}

void Difference(LinkList LA, LinkList LB)
{    Node *pre, *p, *q, *r;
     pre=LA; p=LA->next;
     while(p!=NULL)  /*遍历链表LA中的元素*/
     {   q=LB->next;
         while(q!=NULL&&q->data!=p->data)  /*对于LA中任何一个元素,都要遍历LB对比*/
                { q= q->next;}
          if(q!=NULL) /*说明p所指元素在表LB中找到了,则删除p所指元素*/
          {      r=p;
                  pre->next=p->next;  /*p的前驱结点指向p的后继结点*/
                  p=p->next; /*p指向下一元素*/
                  free(r);    /*释放LA中的该元素*/
           }else{
                  pre=p;  p=p->next;
            }
     }/*while循环*/
}

LinkList merge_1(LinkList LA,LinkList LB)
{
    Node *p,*q;
    p = LA;
    q = LB;
    while (p->next!=LA)
        p=p->next;
    while (q->next!=LB)
        q=q->next;
    p->next=LB->next;
    free(LB);
    q->next=LA;
    return LA;
}

 LinkList merge_2(LinkList RA, LinkList RB)
{     /*此算法将两个采用尾指针的循环链表首尾连接起来*/
      Node *p,*q;
      p=RA->next;  /*保存链表RA的头结点地址*/
      q=RB->next; /*保存链表RB的头结点地址*/
      RA->next=q->next;
      free(q);   /*释放表RB的表头指针*/
      RB->next=p;
      return (RB);
}
