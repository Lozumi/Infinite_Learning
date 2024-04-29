#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef struct {
    int row, col;
    int e;
} Triple;

typedef struct {
    Triple data[MAXSIZE*MAXSIZE];
    int n, m, len;
} TSMatrix;

TSMatrix* CreateTSMatrix(int n, int m) {
    TSMatrix* tsMatrix = (TSMatrix *)malloc(sizeof(TSMatrix));
    if (tsMatrix == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tsMatrix->n = n;
    tsMatrix->m = m;
    tsMatrix->len = 0;
    return tsMatrix;
}

void AddTriple(TSMatrix* ts, int row, int col, int e) {
    if (ts->len >= MAXSIZE * MAXSIZE) {
        printf("Error: Too many elements\n");
        exit(EXIT_FAILURE);
    }
    if (row < 0 || row >= ts->n || col < 0 || col >= ts->m) {
        printf("Error: Invalid position\n");
        exit(EXIT_FAILURE);
    }
    Triple* triple = (Triple *)malloc(sizeof(Triple));
    if (triple == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    triple->row = row;
    triple->col = col;
    triple->e = e;
    ts->data[ts->len] = *triple;
    ts->len++;
}

void sparseMatrixToDenseArray(TSMatrix *sparse, int dense[MAXSIZE][MAXSIZE]) {
    // 初始化二维数组
    for (int i = 0; i < sparse->n; ++i) {
        for (int j = 0; j < sparse->m; ++j) {
            dense[i][j] = 0;
        }
    }
    
    // 将非零元素填入二维数组
    for (int k = 0; k < sparse->len; ++k) {
        dense[sparse->data[k].row][sparse->data[k].col] = sparse->data[k].e;
    }
}

void AddMatrix(int A[MAXSIZE][MAXSIZE], int B[MAXSIZE][MAXSIZE], int n, int m, int result[MAXSIZE][MAXSIZE]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printNonZeroElements(int matrix[MAXSIZE][MAXSIZE], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != 0) {
                printf("%d %d %d\n", i, j, matrix[i][j]);
            }
        }
    }
}

int main() {
    int n, m, t1, t2;
    scanf("%d %d %d %d", &n, &m, &t1, &t2);
    TSMatrix* tsMatrix1 = CreateTSMatrix(n, m);
    TSMatrix* tsMatrix2 = CreateTSMatrix(n, m);

    int row, col, e;
    for (int i = 0; i < t1; i++) {
        scanf("%d %d %d", &row, &col, &e);
        AddTriple(tsMatrix1, row, col, e);
    }
    for (int i = 0; i < t2; i++) {
        scanf("%d %d %d", &row, &col, &e);
        AddTriple(tsMatrix2, row, col, e);
    }

    int A[MAXSIZE][MAXSIZE], B[MAXSIZE][MAXSIZE], result[MAXSIZE][MAXSIZE];
    sparseMatrixToDenseArray(tsMatrix1, A);
    sparseMatrixToDenseArray(tsMatrix2, B);
    
    AddMatrix(A, B, n, m, result);
    
    printNonZeroElements(result, n, m);

    // 释放内存
    free(tsMatrix1);
    free(tsMatrix2);

    return 0;
}
