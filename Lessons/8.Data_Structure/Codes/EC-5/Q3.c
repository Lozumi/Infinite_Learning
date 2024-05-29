#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

// 创建二叉树，先序输入，'#'表示空节点
BTNode* CreateTree() {
    char c = getchar();
    if (c == '#') {
        return NULL;
    }

    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = c;
    node->lchild = CreateTree();
    node->rchild = CreateTree();
    return node;
}

// 中序遍历二叉树并打印节点
void PrintTree(BTNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->lchild) {
        PrintTree(root->lchild);
    }
    printf("%c", root->data);
    if (root->rchild) {
        PrintTree(root->rchild);
    }
}

int main() {
    BTNode* root = CreateTree();
    PrintTree(root);
    printf("\n"); // 为了美观输出换行
    return 0;
}
