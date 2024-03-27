//
// Created by Lozumi on 2024/3/20.
//
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} OrderedArray;

void insertOrderedArray(OrderedArray *va, int x) {
    int i, j;
    if (va->length == 0) {
        va->data[0] = x;
        va->length++;
        return;
    }
    i = 0;
    j = va->length - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (va->data[mid] == x)
            return; // x already exists in the array
        else if (va->data[mid] < x)
            i = mid + 1;
        else
            j = mid - 1;
    }
    int insertPos = (va->data[i] < x) ? i + 1 : i;
    for (int k = va->length - 1; k >= insertPos; k--)
        va->data[k + 1] = va->data[k];
    va->data[insertPos] = x;
    va->length++;
}

int main() {
    OrderedArray va = {{1, 3, 5, 7, 9}, 5}; // Example ordered array
    int x = 4; // Element to be inserted
    printf("Original array: ");
    for (int i = 0; i < va.length; i++)
        printf("%d ", va.data[i]);
    printf("\n");

    insertOrderedArray(&va, x);

    printf("Array after inserting %d: ", x);
    for (int i = 0; i < va.length; i++)
        printf("%d ", va.data[i]);
    printf("\n");

    return 0;
}
