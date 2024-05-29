#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BinTreeNode {
    char data;
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
} BinTreeNode, *PBinTreeNode;

// 创建二叉树，先序输入，#表示空节点
PBinTreeNode CreateBinTree() {
    char c = getchar();
    if (c == '#') {
        return NULL;
    } else {
        PBinTreeNode node = (PBinTreeNode)malloc(sizeof(BinTreeNode));
        node->data = c;
        node->lchild = CreateBinTree();
        node->rchild = CreateBinTree();
        return node;
    }
}

// 计算二叉树中叶子节点的数目
int CountLeaves(PBinTreeNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL) {
        return 1;
    }
    return CountLeaves(root->lchild) + CountLeaves(root->rchild);
}

int main() {
    PBinTreeNode root = CreateBinTree();
    int leafCount = CountLeaves(root);
    printf("%d\n", leafCount);
    return 0;
}
