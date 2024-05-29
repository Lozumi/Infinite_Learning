#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BTNode {
    char data; // 节点数据
    struct BTNode *lchild; // 左子节点
    struct BTNode *rchild; // 右子节点
} BTNode;

// 创建二叉树
BTNode *CreateTree() {
    char s1, s2;
    BTNode *q = (BTNode*)malloc(sizeof(BTNode));
    q->lchild = NULL;
    q->rchild = NULL;

    s1 = getchar();
    s2 = getchar();

    // 处理输入数据
    if (s1 == ',') {
        q->data = s2;
        s1 = getchar();
        if (s1 == '(') {
            q->lchild = CreateTree();
            q->rchild = CreateTree();
        }
    } else {
        q->data = s1;
        if (s2 == '(') {
            q->lchild = CreateTree();
            q->rchild = CreateTree();
        }
    }

    return q;
}

// 递归打印二叉树
void PrintTree(BTNode *q) {
    if (q == NULL) {
        return;
    }

    printf("%c", q->data);
    if (q->lchild) {
        PrintTree(q->lchild);
    }
    if (q->rchild) {
        PrintTree(q->rchild);
    }
}

int main() {
    BTNode *q = CreateTree();
    PrintTree(q);
    return 0;
}
