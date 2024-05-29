#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 定义数据域类型
typedef char ElemType;

// 定义二叉树节点
typedef struct BinTreeNode {
    ElemType data;              // 数据域
    struct BinTreeNode *left;   // 左节点
    struct BinTreeNode *right;  // 右节点
} BinTreeNode, *PBinTreeNode;

// 函数声明
void createBinTree(PBinTreeNode node, char *str_pre, char *str_in); // 创建二叉树
void postOrderOutput(PBinTreeNode node);                            // 后序输出

// 程序入口
int main() {
    char str_pre[1000];
    char str_in[1000];

    scanf("%s", str_pre);
    scanf("%s", str_in);

    PBinTreeNode root = (PBinTreeNode)malloc(sizeof(BinTreeNode));
    createBinTree(root, str_pre, str_in);
    postOrderOutput(root);
    printf("\n");
    free(root);

    return 0;
}

/* 创建二叉树
 * node: 一个二叉树节点指针
 * str_pre: 该树的前序序列
 * str_in: 中序序列
 * 通过前序确定节点，再在中序中分割
 * 通过递归方式创建
 */
void createBinTree(PBinTreeNode node, char *str_pre, char *str_in) {
    int i = 0, j = 0, len = strlen(str_in);

    while (str_pre[j] != str_in[i]) {
        if (i == len) {
            j++;
            i = 0;
            continue;
        }
        i++;
    }

    node->data = str_pre[j];

    if (i == 0) {
        node->left = NULL;
    }
    if (i == len - 1) {
        node->right = NULL;
    }
    if (i > 0) {
        node->left = (PBinTreeNode)malloc(sizeof(BinTreeNode));
        char *str_left = (char *)malloc(sizeof(char) * (i + 1)); // 多开一个空间用于填放'\0'
        strncpy(str_left, str_in, i);
        str_left[i] = '\0';
        createBinTree(node->left, str_pre + 1, str_left);
        free(str_left);
    }
    if (i < len - 1) {
        node->right = (PBinTreeNode)malloc(sizeof(BinTreeNode));
        char *str_right = (char *)malloc(sizeof(char) * (len - i)); // 存放右子树序列
        strncpy(str_right, str_in + i + 1, len - i - 1);
        str_right[len - i - 1] = '\0';
        createBinTree(node->right, str_pre + i + 1, str_right);
        free(str_right);
    }
}

/* 后序输出
 * ptr_node: 一个二叉树结节点指针
 * 通过后序方式递归输出
 */
void postOrderOutput(PBinTreeNode ptr_node) {
    if (ptr_node->left) {
        postOrderOutput(ptr_node->left);
    }
    if (ptr_node->right) {
        postOrderOutput(ptr_node->right);
    }
    printf("%c", ptr_node->data);
}

/*
测试样例：
输入：
ABDFGCEH
BFDGACEH
输出：
BFDGHECA
*/
