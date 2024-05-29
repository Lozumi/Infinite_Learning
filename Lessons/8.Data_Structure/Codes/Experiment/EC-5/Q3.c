#include <stdio.h>
#include <stdlib.h>

// 十字链表表示法
typedef struct OLNode {
    int row, col;						// 行号和列号
    int value;							// 非零元素的值
    struct OLNode * right, * down;		// 行和列上的后继元素
} OLNode, * OLink;

typedef struct {
    OLink * row_head, * col_head;		// 行和列的头指针向量
    int m, n, len;						// 行数、列数和非零元素的数量
} CrossList;


// 创建十字链表
CrossList *createCrossList(int m, int n) {
    CrossList *list = (CrossList *)malloc(sizeof(CrossList));
    list->m = m;
    list->n = n;
    list->len = 0;
    list->row_head = (OLink *)malloc((m + 1) * sizeof(OLink));
    list->col_head = (OLink *)malloc((n + 1) * sizeof(OLink));
    for (int i = 0; i <= m; i++) {
        list->row_head[i] = NULL;
    }
    for (int j = 0; j <= n; j++) {
        list->col_head[j] = NULL;
    }
    return list;
}

// 插入节点到十字链表
void insertNode(CrossList *list, int row, int col, int value) {
    // TODO: 检查行号和列号是否在范围内

    // 创建新节点
    OLNode *node = (OLNode *)malloc(sizeof(OLNode));
    node->row = row;
    node->col = col;
    node->value = value;
    node->right = NULL;
    node->down = NULL;

    // 在行上插入节点
    // TODO: 检查是否存在相同位置的元素
    // ...
    if (list->row_head[row] == NULL || list->row_head[row]->col > col) {
        node->right = list->row_head[row];
        list->row_head[row] = node;
    } else {
        OLNode *p = list->row_head[row];
        while (p->right != NULL && p->right->col < col) {
            p = p->right;
        }
        node->right = p->right;
        p->right = node;
    }

    // 在列上插入节点
    // TODO: 检查是否存在相同位置的元素
    // ...
    if (list->col_head[col] == NULL || list->col_head[col]->row > row) {
        node->down = list->col_head[col];
        list->col_head[col] = node;
    } else {
        OLNode *p = list->col_head[col];
        while (p->down != NULL && p->down->row < row) {
            p = p->down;
        }
        node->down = p->down;
        p->down = node;
    }

    list->len++;
}


// 十字链表相加
CrossList *addCrossList(CrossList *A, CrossList *B) {
    CrossList *result = createCrossList(A->m, A->n);
    for (int i = 1; i < A->m + 1; i++) {
        OLNode *pa = A->row_head[i];
        OLNode *pb = B->row_head[i];

        while (pa != NULL && pb != NULL) {
            if (pa->col > pb->col) {
                insertNode(result, pb->row, pb->col, pb->value);
                pb = pb->right;
            } else if (pa->col < pb->col) {
                insertNode(result, pa->row, pa->col, pa->value);
                pa = pa->right;
            } else {
                insertNode(result, pa->row, pa->col, pa->value + pb->value);
                pa = pa->right;
                pb = pb->right;
            }
        }

        while (pa != NULL) {
            insertNode(result, pa->row, pa->col, pa->value);
            pa = pa->right;
        }
        while (pb != NULL) {
            insertNode(result, pb->row, pb->col, pb->value);
            pb = pb->right;
        }
    }
    return result;
}

// 打印稀疏矩阵，按行打印就好
void printMatrix(CrossList *matrix) {
    for (int i = 1; i < matrix->m + 1; i++) {
        OLNode *p = matrix->row_head[i];
        while (p != NULL) {
            printf("%d %d %d\n", p->row, p->col, p->value);
            p = p->right;
        }
    }
}

int main() {
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);
    CrossList *A = createCrossList(m, n);
    CrossList *B = createCrossList(m, n);
    for (int i = 0; i < t1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b ,&c);
        insertNode(A, a, b, c);
    }
    for (int i = 0; i < t2; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b ,&c);
        insertNode(B, a, b, c);
    }

    CrossList *C = addCrossList(A, B);

    printMatrix(C);

    // 释放内存
    // TODO: 释放 CrossList 结构体中动态分配的内存
    // ...

    return 0;
}
