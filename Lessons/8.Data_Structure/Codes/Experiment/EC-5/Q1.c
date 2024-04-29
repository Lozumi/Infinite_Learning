#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 400

typedef struct {
    int row, col;
    int e;
} Triple;

typedef struct {
    Triple data[MAXSIZE];
    int n, m, len;
} TSMatrix;

TSMatrix* CreateTSMatrix() {
    int n, m;
    scanf("%d %d", &n, &m);
    TSMatrix* tsMatrix = (TSMatrix *)malloc(sizeof(TSMatrix));
    tsMatrix->n = n;
    tsMatrix->m = m;
    tsMatrix->len = 0;
    return tsMatrix; // 添加返回值
}

void AddTriple(TSMatrix* ts, int row, int col, int e) {
    if (ts->len >= MAXSIZE) {
        printf("Error: Too many elements\n");
        exit(EXIT_FAILURE);
    }
    if (row < 0 || row >= ts->n || col < 0 || col >= ts->m) {
        printf("Error: Invalid position\n");
        exit(EXIT_FAILURE);
    }
    Triple* triple = (Triple *)malloc(sizeof(Triple));
    triple->row = row;
    triple->col = col;
    triple->e = e;
    ts->data[ts->len] = *triple;
    ts->len++;
}

void SetTSMatrix(TSMatrix* tsMatrix) {
    int row, col, e;
    while (1) {
        scanf("%d %d %d", &row, &col, &e);
        if (row == 0 && col == 0 && e == 0) {
            break;
        } else {
            AddTriple(tsMatrix, row, col, e);
        }
    }
}

void TransPoseMatrix(TSMatrix* tsMatrix) {
    int temp;
    for (int i = 0; i < tsMatrix->len; i++) {
        temp = tsMatrix->data[i].col;
        tsMatrix->data[i].col = tsMatrix->data[i].row;
        tsMatrix->data[i].row = temp;
    }
    temp = tsMatrix->m;
    tsMatrix->m = tsMatrix->n;
    tsMatrix->n = temp;
}

void PrintTSMatrix(TSMatrix* tsMatrix) {
    for (int i = 0; i < tsMatrix->len; i++) {
        printf("%d %d %d\n", tsMatrix->data[i].row, tsMatrix->data[i].col, tsMatrix->data[i].e);
    }
}

int main() {
    TSMatrix* tsMatrix = CreateTSMatrix();
    SetTSMatrix(tsMatrix);

    TransPoseMatrix(tsMatrix);
    PrintTSMatrix(tsMatrix);

    free(tsMatrix); // 释放内存
    return 0;
}
