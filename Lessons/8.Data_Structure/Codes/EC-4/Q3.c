#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
struct Node {
    int judge; // 标志位，判断是子表还是数据
    struct Node *before; // 指向前一个节点
    struct Node *next; // 指向下一个节点
    union {
        struct Node *down; // 指向子表
        char data; // 数据域
    };
};

// 函数声明
void createGeneralNode(struct Node *pre);
void createGeneralList(struct Node *head);
void run();
int getDepth(struct Node *node);

int main() {
    run();
    return 0;
}

// 创建广义表的节点
void createGeneralNode(struct Node *pre) {
    char s, ss = 0;
    struct Node *cur;
    if ((s = getchar()) == ',') {
        ss = s;
        s = getchar();
    }
    if (s >= 'a' && s <= 'z') { // 是数据节点
        cur = (struct Node *)malloc(sizeof(struct Node));
        if (ss == ',') {
            pre->next = cur;
        } else {
            pre->down = cur;
        }
        cur->before = pre;
        cur->data = s;
        cur->next = NULL;
        cur->judge = 1;
        createGeneralNode(cur);
    } else if (s == '(') { // 是子表
        cur = (struct Node *)malloc(sizeof(struct Node));
        if (ss == ',') {
            pre->next = cur;
        } else {
            pre->down = cur;
        }
        cur->before = pre;
        cur->down = NULL;
        cur->next = NULL;
        cur->judge = 0;
        createGeneralNode(cur);
    } else if (s == ')') { // 子表结束
        while (pre->judge || pre->next) {
            pre = pre->before;
        }
        createGeneralNode(pre);
    }
}

// 创建广义表
void createGeneralList(struct Node *head) {
    head->judge = 0;
    head->down = NULL;
    head->next = NULL;
    head->before = NULL;
    createGeneralNode(head);
}

// 运行程序
void run() {
    struct Node head;
    int depth;
    createGeneralList(&head);
    depth = getDepth(head.down);
    printf("%d\n%d", depth, depth);
}

// 获取广义表的深度
int getDepth(struct Node *node) {
    int max = 0, depth;
    struct Node *p;
    for (p = node->next; p; p = p->next) {
        if (p->judge) {
            depth = 0;
        } else {
            if (p->down) {
                depth = getDepth(p->down) + 1;
            } else {
                depth = 1;
            }
        }
        max = depth > max ? depth : max;
    }
    if (node->judge) {
        depth = 0;
    } else {
        if (node->down) {
            depth = getDepth(node->down) + 1;
        } else {
            depth = 1;
        }
    }
    return max = depth > max ? depth : max;
}
