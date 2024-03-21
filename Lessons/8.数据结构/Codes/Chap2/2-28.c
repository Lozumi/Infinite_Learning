//
// Created by Lozumi on 2024/3/20.
//
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

void removeCommonElements(SeqList *A, SeqList *B, SeqList *C) {
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length && k < C->length) {
        if (A->data[i] < B->data[j]) {
            i++;
        } else if (A->data[i] > B->data[j]) {
            j++;
        } else {
            if (A->data[i] < C->data[k]) {
                i++;
            } else if (A->data[i] > C->data[k]) {
                k++;
            } else {
                // A[i] == B[j] == C[k]
                // Remove the common element from A
                for (int x = i; x < A->length - 1; x++) {
                    A->data[x] = A->data[x + 1];
                }
                A->length--;
            }
        }
    }
}

int main() {
    SeqList A = {{2, 4, 6, 8, 10}, 5};
    SeqList B = {{4, 6, 8}, 3};
    SeqList C = {{3, 6, 9}, 3};

    printf("Original list A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    printf("\n");

    removeCommonElements(&A, &B, &C);

    printf("Modified list A: ");
    for (int i = 0; i < A.length; i++) {
        printf("%d ", A.data[i]);
    }
    printf("\n");

    return 0;
}
