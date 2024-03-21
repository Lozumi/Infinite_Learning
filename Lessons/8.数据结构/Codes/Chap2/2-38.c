//
// Created by Lozumi on 2024/3/20.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int freq;
    struct Node *pre;
    struct Node *next;
} Node;

// 初始化双向循环链表
Node *initList() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = -1; // 头结点数据可以任意设置
    head->freq = 0; // 初始频度为0
    head->pre = head;
    head->next = head;
    return head;
}

// 在双向循环链表中查找值为x的结点并返回
Node *locate(Node *head, int x) {
    Node *p = head->next;
    while (p != head) {
        if (p->data == x) {
            p->freq++; // 找到值为x的结点，增加频度
            // 调整链表顺序，使其按访问频度非递增的次序顺序排列
            while (p->pre != head && p->freq > p->pre->freq) {
                // 交换p和p->pre结点的位置
                Node *temp = p->pre;
                p->pre = temp->pre;
                temp->pre->next = p;
                temp->next = p->next;
                if (p->next != head)
                    p->next->pre = temp;
                p->next = temp;
                temp->next = p;
            }
            return p;
        }
        p = p->next;
    }
    return NULL; // 没有找到值为x的结点
}

// 打印双向循环链表
void printList(Node *head) {
    Node *p = head->next;
    printf("List: ");
    while (p != head) {
        printf("(%d, %d) ", p->data, p->freq);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node *head = initList();

    // 插入一些结点
    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->data = 1;
    node1->freq = 0;
    node1->pre = head;
    node1->next = head->next;
    head->next->pre = node1;
    head->next = node1;

    Node *node2 = (Node *)malloc(sizeof(Node));
    node2->data = 2;
    node2->freq = 0;
    node2->pre = node1;
    node2->next = node1->next;
    node1->next->pre = node2;
    node1->next = node2;

    // 执行 Locate 操作
    locate(head, 1);
    locate(head, 1);
    locate(head, 2);
    locate(head, 2);
    locate(head, 2);

    // 打印链表
    printList(head);

    return 0;
}
