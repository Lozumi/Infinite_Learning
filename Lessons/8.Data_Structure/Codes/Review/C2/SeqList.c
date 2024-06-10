// 线性表
#include <stdio.h>
#define ElemType int
#define MAXSIZE 100

typedef struct SeqList
{
    ElemType elem[MAXSIZE];
    int last;
} SeqList;

// 定位操作
int Locate(SeqList L, ElemType e)
{
    int i = 0;
    while ((i <= L.last) && (L.elem != e))
        i++;
    if (i <= L.last)
        return i + 1;
    else
        return -1;
}

// 插入操作
int InsList(SeqList *L, int i, ElemType *e) /*i为序号，不是下标号*/
{
    int k;
    if ((i < 1) || (i > L->last + 2)) /* 判定插入位置是否合法 */
    {
        printf("插入位置i值不合法");
        return ("Error");
    }

    if (L->last >= MAXSIZE - 1)
    {
        printf("表已满 无法插入");
        return ("Error");
    }

    for (k = L->last; k >= i - 1; k--) /*为插入元素而移动位置*/
        L->elem[k + 1] = L->elem[k];

    L->elem[i - 1] = e; /*在C语言中，第i个元素的下标为i-1 */
    L->last++;
    return 0;
}

int DelList(SeqList *L, int i, ElemType *e)
{
    int k;
    if ((i < 1) || (i > L->last + 1)) /* i的合法取值范围 1≤i≤L− >last+1*/
    {
        printf("删除位置i值不合法");
        return ("Error");
    }

    *e = L->elem[i - 1]; /* 将删除的元素存放到e所指向的变量中*/

    for (k = i; k <= L->last; k++) /*将后面的元素依次前移*/
        L->elem[k - 1] = L->elem[k];

    L->last--;
    return e;
}

void merge(SeqList *LA, SeqList *LB, SeqList *LC)
{
    int i = 0, j = 0, k = 0;
    while (i <= LA->last && j <= LB->last)
    {
        if (LA->elem[i] <= LB->elem[j])
        {
            LC->elem[k] = LA->elem[i];
            i++;
            k++;
        }
        else
        {
            LC->elem[k] = LB->elem[i];
            j++;
            k++;
        }
    }
    while (i <= LA->last) /*当表LA有剩余元素时，将表LA余下的元素赋给表LC*/
    {
        LC->elem[k] = LA->elem[i];
        i++;
        k++;
    }
    while (j <= LB->last) /*当表LB有剩余元素时，将表LB余下的元素赋给表LC*/
    {
        LC->elem[k] = LB->elem[i];
        j++;
        k++;
    }
    LC->last = LA->last + LB->last;
}

int main()
{
    SeqList L;
}
