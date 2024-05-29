#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

// 定义三元组结构
typedef struct Triple {
    int e;      // 元素值
    int row;    // 行号
    int col;    // 列号
} Triple;

// 定义稀疏矩阵结构
typedef struct TSMatrix {
    Triple data[MAXSIZE + 1];  // 存储非零元素的三元组数组
    int m, n;                  // 矩阵的行数和列数
    int len;                   // 非零元素的个数
} TSMatrix;

// 矩阵输入函数
void InputMatrix(TSMatrix *t1, TSMatrix *t2) {
    // 输入两个矩阵的非零元素个数
    scanf("%d %d", &t1->len, &t2->len);
    
    // 输入第一个矩阵的非零元素
    for (int i = 1; i <= t1->len; i++) {
        scanf("%d %d %d", &t1->data[i].row, &t1->data[i].col, &t1->data[i].e);
    }

    // 输入第二个矩阵的非零元素
    for (int i = 1; i <= t2->len; i++) {
        scanf("%d %d %d", &t2->data[i].row, &t2->data[i].col, &t2->data[i].e);
    }
}

// 矩阵输出函数
void OutputMatrix(TSMatrix t) {
    // 输出矩阵的非零元素
    for (int i = 1; i <= t.len; i++) {
        printf("%d %d %d\n", t.data[i].row, t.data[i].col, t.data[i].e);
    }
}

// 矩阵相加函数
void AddMatrix(TSMatrix a, TSMatrix b, TSMatrix *c) {
    int i = 1, j = 1, k = 1;
    c->m = a.m;
    c->n = a.n;

    // 合并两个矩阵的非零元素
    while (i <= a.len && j <= b.len) {
        if (a.data[i].row < b.data[j].row) {
            c->data[k++] = a.data[i++];
        } else if (a.data[i].row > b.data[j].row) {
            c->data[k++] = b.data[j++];
        } else {
            if (a.data[i].col < b.data[j].col) {
                c->data[k++] = a.data[i++];
            } else if (a.data[i].col > b.data[j].col) {
                c->data[k++] = b.data[j++];
            } else {
                int sum = a.data[i].e + b.data[j].e;
                if (sum != 0) {
                    c->data[k].row = a.data[i].row;
                    c->data[k].col = a.data[i].col;
                    c->data[k].e = sum;
                    k++;
                }
                i++;
                j++;
            }
        }
    }

    // 处理剩余的非零元素
    while (i <= a.len) {
        c->data[k++] = a.data[i++];
    }
    while (j <= b.len) {
        c->data[k++] = b.data[j++];
    }
    c->len = k - 1;
}

int main() {
    TSMatrix a, b, c;
    InputMatrix(&a, &b);
    AddMatrix(a, b, &c);
    OutputMatrix(c);
    return 0;
}
