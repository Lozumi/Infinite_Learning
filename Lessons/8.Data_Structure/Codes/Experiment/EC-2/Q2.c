/* 限制使用双向链表作存储结构，高精度计算PI值。
 * 作者：刘黎可
 * 版本：1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

// 定义双向链表的节点结构
typedef struct Node {
    int data; // 存储节点的数据
    struct Node *prev; // 指向前一个节点的指针
    struct Node *next; // 指向下一个节点的指针
} Node, *LinkedList;

// 函数声明
LinkedList initializeList(); // 初始化链表
void extendList(LinkedList list, int data); // 扩展链表
void multiplyList(LinkedList list, int factor); // 链表乘法
void divideList(LinkedList list, int divisor); // 链表除法
void addList(LinkedList list1, LinkedList list2); // 链表相加
void printList(LinkedList list, int decimalPlaces); // 打印链表
void destroyList(LinkedList list); // 销毁链表

int main() {
    int decimalPlaces;
    // printf("输入保留小数位数: ");
    scanf("%d", &decimalPlaces);
    
    LinkedList num = initializeList(); // 初始化num链表
    LinkedList sum = initializeList(); // 初始化sum链表
    
    // 扩展num和sum链表以存储足够多的数字
    for (int i = 0; i < 600; i++) {
        extendList(num, 0);
        extendList(sum, 0);
    }
    
    // 计算圆周率Pi
    for (int j = 1, k = 3; j < 2000; j++) {
        multiplyList(num, j);  // 链表乘以j
        divideList(num, k);    // 链表除以k
        addList(num, sum);     // 将num链表和sum链表相加
        k += 2;                // 更新除数
    }
    
    // 打印结果
    // printf("保留%d位小数的估计结果: ", decimalPlaces);
    printList(sum, decimalPlaces); // 打印sum链表，保留decimalPlaces位小数
    
    // 释放内存
    destroyList(num); // 销毁num链表
    destroyList(sum); // 销毁sum链表
    
    return 0;
}

// 初始化链表函数
LinkedList initializeList() {
    // 创建一个只包含一个节点的链表，该节点存储数字2
    LinkedList list = (LinkedList)malloc(sizeof(Node));
    list->data = 2;
    list->prev = list; // 指向自己，表示链表只有这一个节点
    list->next = list; // 指向自己，表示链表只有这一个节点
    return list;
}

// 扩展链表函数
void extendList(LinkedList list, int data) {
    // 在链表末尾添加一个节点
    LinkedList tmp = list;
    if (tmp == NULL) {
        return;
    }
    tmp = tmp->prev; // 移动到最后一个节点
    LinkedList newNode = (LinkedList)malloc(sizeof(Node)); // 创建新节点
    newNode->data = data; // 设置新节点的数据
    newNode->next = tmp->next; // 新节点的下一个节点是原链表的第一个节点
    newNode->prev = tmp; // 新节点的前一个节点是原链表的最后一个节点
    tmp->next->prev = newNode; // 更新原链表第一个节点的前一个节点指针
    tmp->next = newNode; // 更新原链表最后一个节点的下一个节点指针
}

// 链表乘法函数
void multiplyList(LinkedList list, int factor) {
    // 将链表表示的数字与一个整数相乘
    int tmp, carry = 0;
    LinkedList p = list->prev; // 从链表的最后一个节点开始
    while (p != list) { // 遍历整个链表
        tmp = p->data * factor + carry; // 乘法运算加上进位
        p->data = tmp % 10; // 存储当前位的结果
        carry = tmp / 10; // 更新进位
        p = p->prev; // 移动到前一个节点
    }
    p->data += carry; // 处理最后一个节点的进位
}

// 链表除法函数
void divideList(LinkedList list, int divisor) {
    // 将链表表示的数字除以一个整数
    int tmp, remainder = 0;
    LinkedList p = list; // 从链表的第一个节点开始
    while (1) { // 遍历整个链表
        tmp = p->data + remainder * 10; // 除法运算
        remainder = tmp % divisor; // 计算余数
        p->data = tmp / divisor; // 存储商
        p = p->next; // 移动到下一个节点
        if (p == list) break; // 如果到达链表末尾，则结束循环
    }
}

// 链表相加函数
void addList(LinkedList list1, LinkedList list2) {
    // 将两个链表表示的数字相加
    int tmp, carry = 0;
    LinkedList p = list1->prev; // 从链表1的最后一个节点开始
    LinkedList q = list2->prev; // 从链表2的最后一个节点开始
    while (1) { // 遍历两个链表直到结束
        tmp = p->data + q->data + carry; // 加法运算加上进位
        q->data = tmp % 10; // 存储当前位的结果
        carry = tmp / 10; // 更新进位
        p = p->prev; // 移动到链表1的前一个节点
        q = q->prev; // 移动到链表2的前一个节点
        if (p == list1->prev) break; // 如果到达链表1的末尾，则结束循环
    }
}

// 打印链表函数
void printList(LinkedList list, int decimalPlaces) {
    // 打印链表表示的数字，保留指定的小数位数
    LinkedList p = list; // 从链表的第一个节点开始
    if (decimalPlaces == 0)
        printf("%d", p->data); // 打印小数点前的数字
    else{
        printf("%d.", p->data); // 打印小数点前的数字
        p = p->next; // 移动到小数点后的节点
        for (int i = 0; i < decimalPlaces; i++) { // 打印小数点后的数字
            printf("%d", p->data);
            p = p->next; // 移动到下一个节点
        }
        printf("\n"); // 打印换行符
    }
}

// 销毁链表函数
void destroyList(LinkedList list) {
    // 释放链表所占用的内存
    LinkedList tmp = list->next; // 临时指针用于释放内存
    while (tmp != list) { // 遍历链表
        list->next = tmp->next; // 更新链表的下一个节点指针
        free(tmp); // 释放当前节点
        tmp = list->next; // 更新临时指针
    }
    list->prev = list; // 确保链表正确闭合
    free(list); // 释放链表的头节点
    list = NULL; // 确保不会有悬挂指针
}