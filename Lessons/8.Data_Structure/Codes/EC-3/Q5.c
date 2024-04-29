#include<stdio.h>

#define MAX_SIZE 100

int main() {
    int n, k, i, tmp;
    // printf("Enter the size of the array (n) and the number of rotations (k): ");
    scanf("%d%d", &n, &k);

    if (n <= 0 || k < 0) {
        printf("Invalid input. Size of the array and number of rotations must be non-negative.\n");
        return 1;
    }

    int arr[MAX_SIZE];
    // printf("Enter %d elements for the array: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (k--) {
        tmp = arr[n - 1];
        for (i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = tmp;
    }

    // printf("Array after %d rotations: ", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
