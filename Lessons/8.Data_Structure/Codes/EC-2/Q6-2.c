#include <stdio.h>
#include <stdlib.h>

// 定义双向循环链表节点结构体
typedef struct DoubleNode
{
    char data;               // 节点数据
    int frequency;           // 访问频率
    struct DoubleNode *prev; // 指向前一个节点的指针
    struct DoubleNode *next; // 指向后一个节点的指针
} DoubleNode, *DoubleList;

// 函数声明
void createListFromTail(DoubleList head, int length); // 后插法建表
void locateAndUpdate(DoubleList head, char element);  // 定位并更新频率
void visitNodes(DoubleList head, int num);            // 对节点进行访问

int main()
{
    DoubleList head, current; // 定义头指针和当前节点指针
    int length, num;          // 双链表长度和访问节点次数

    head = (DoubleList)malloc(sizeof(DoubleNode)); // 分配头节点空间
    if (head == NULL)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // 输入双链表长度和访问节点次数
    scanf("%d %d", &length, &num);

    // 创建双链表
    createListFromTail(head, length);

    // 访问节点并更新频率
    visitNodes(head, num);

    // 输出更新后的双链表
    current = head->next; // 当前节点指向第一个数据节点
    for (int i = 0; i < length; i++)
    {
        printf("%c ", current->data);
        current = current->next;
    }

    // 释放动态分配的内存
    current = head->next;
    while (current != head)
    {
        DoubleList temp = current;
        current = current->next;
        free(temp);
    }
    free(head);

    return 0;
}

// 后插法建表
void createListFromTail(DoubleList head, int length)
{
    DoubleList end = head; // 结束节点指针
    DoubleList insert;     // 待插入节点指针

    for (int i = 0; i < length; i++)
    {
        char elem;
        char c;

        // 清空缓冲区
        do
        {
            c = getchar();
        } while (c != EOF && c != '\n');

        scanf("%c", &elem);

        // 创建新节点
        insert = (DoubleList)malloc(sizeof(DoubleNode));
        if (insert == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(-1);
        }

        // 初始化节点数据和频率
        insert->data = elem;
        insert->frequency = 0;

        // 将新节点插入到链表尾部
        end->next = insert;
        insert->prev = end;
        end = insert;
    }

    // 循环链表连接
    end->next = head;
    head->prev = end;
}

// 定位并更新频率
void locateAndUpdate(DoubleList head, char element)
{
    DoubleList current = head->next; // 当前节点指针，从第一个数据节点开始

    // 遍历链表，定位目标节点
    while (current->data != element && current != head)
    {
        current = current->next;
    }

    // 更新频率
    if (current != head)
    {
        current->frequency++;

        // 调整节点位置
        while (current->prev != head && current->frequency > current->prev->frequency)
        {
            // 交换节点位置
            DoubleList prev = current->prev;
            DoubleList beforePrev = prev->prev;
            DoubleList afterCurrent = current->next;

            afterCurrent->prev = prev;
            current->next = prev;
            current->prev = beforePrev;
            prev->next = afterCurrent;
            prev->prev = current;
            beforePrev->next = current;
        }
    }
}

// 对节点进行访问
void visitNodes(DoubleList head, int num)
{
    char element;
    char c;

    // 循环访问节点
    for (int i = 0; i < num; i++)
    {
        // 清空缓冲区
        do
        {
            c = getchar();
        } while (c != EOF && c != '\n');

        // 输入访问的节点值
        scanf("%c", &element);

        // 定位并更新频率
        locateAndUpdate(head, element);
    }
}
