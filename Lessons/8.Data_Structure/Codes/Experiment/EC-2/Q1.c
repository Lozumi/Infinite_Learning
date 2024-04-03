#include <stdio.h>
#include <stdbool.h>

// 检查数组是否按升序排列
bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// 检查数组大小是否有效
bool isValidSize(int size) {
    return (size >= 1 && size <= 50);
}

void mergeSortedArrays(int arr1[], int n, int arr2[], int m) {
    int mergedArray[100]; // 创建新数组来存储合并后的结果
    int i = 0, j = 0, k = 0;

    // 从两个数组中逐个比较元素，将较小的放入合并数组中
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // 将剩余元素复制到合并数组中
    while (i < n) {
        mergedArray[k++] = arr1[i++];
    }
    while (j < m) {
        mergedArray[k++] = arr2[j++];
    }

    // 输出合并后的数组
    for (i = 0; i < n + m; i++) {
        printf("%d\n", mergedArray[i]);
    }
}

int main() {
    int n, m;

    // printf("请输入第一个数组的大小：");
    scanf("%d", &n);

    if (!isValidSize(n)) {
        printf("数组大小无效, 大小应在1到50之间。\n");
        return 1; // 返回非零表示程序异常退出
    }

    int arr1[50];
    // printf("请输入升序排列的第一个数组的元素：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    if (!isSorted(arr1, n)) {
        printf("第一个数组未按升序排列。\n");
        return 1; // 返回非零表示程序异常退出
    }

    // printf("请输入第二个数组的大小：");
    scanf("%d", &m);

    if (!isValidSize(m)) {
        printf("数组大小无效, 大小应在1到50之间。\n");
        return 1; // 返回非零表示程序异常退出
    }

    int arr2[50];
    // printf("请输入升序排列的第二个数组的元素：\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    if (!isSorted(arr2, m)) {
        printf("第二个数组未按升序排列。\n");
        return 1; // 返回非零表示程序异常退出
    }

    // 调用合并函数
    mergeSortedArrays(arr1, n, arr2, m);

    return 0;
}
