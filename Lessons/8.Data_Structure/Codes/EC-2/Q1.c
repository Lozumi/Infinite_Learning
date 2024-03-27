#include <stdio.h>

#define MAX_SIZE 1000

// 定义顺序表结构体
typedef struct
{
    int data[MAX_SIZE];
    int length;
} SeqList;

// 初始化顺序表
void init(SeqList *L)
{
    L->length = 0;
}

// 插入元素到有序表中
void insert(SeqList *L, int x)
{
    int i, j;
    // 寻找插入位置
    for (i = 0; i < L->length && L->data[i] < x; i++)
        ;
    // 将插入位置后的元素都后移一位
    for (j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    // 插入元素
    L->data[i] = x;
    L->length++;
}

int main()
{
    SeqList L;
    int elenum, i, x;

    // 输入顺序表元素个数
    // printf("请输入顺序表元素个数: ");
    scanf("%d", &elenum);

    // 输入顺序表元素
    // printf("请输入顺序表: ");
    for (i = 0; i < elenum; i++)
    {
        scanf("%d", &L.data[i]);
    }
    L.length = elenum;

    // 输入要插入的值
    // printf("请输入要插入的值: ");
    scanf("%d", &x);

    // 插入值到有序表中
    insert(&L, x);

    // 输出有序表
    // printf("插入后的有序顺序表为: ");
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}
