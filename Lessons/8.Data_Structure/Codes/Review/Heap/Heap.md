堆（Heap）是一种特殊的完全二叉树，可以分为最大堆（Max-Heap）和最小堆（Min-Heap）。在最大堆中，任意节点的值总是大于或等于其子节点的值，而在最小堆中，任意节点的值总是小于或等于其子节点的值。

### 堆的数据结构
堆通常使用数组来实现。对于一个索引为 `i` 的节点：
- 父节点的索引为 `(i - 1) / 2`。
- 左子节点的索引为 `2 * i + 1`。
- 右子节点的索引为 `2 * i + 2`。

### 最大堆的构造方法

下面是最大堆的构造方法，包括插入元素、删除最大值和维护堆性质的操作。

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int size;
} MaxHeap;

// 初始化堆
void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

// 向堆中插入一个元素
void insert(MaxHeap *heap, int value) {
    if (heap->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    // 上浮操作
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        int temp = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = heap->data[i];
        heap->data[i] = temp;
        i = (i - 1) / 2;
    }
}

// 删除堆顶元素（最大值）
int deleteMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int max = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    // 下沉操作
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = heap->data[i];
            heap->data[i] = heap->data[largest];
            heap->data[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
    return max;
}

// 打印堆
void printHeap(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
    initHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 25);

    printf("MaxHeap: ");
    printHeap(&heap);

    printf("Deleted max: %d\n", deleteMax(&heap));
    printf("MaxHeap after deletion: ");
    printHeap(&heap);

    return 0;
}
```

### 代码解释

1. **初始化堆**
   - `initHeap` 函数将堆的大小初始化为 0。

2. **插入元素**
   - `insert` 函数在堆中插入一个新元素。
   - 新元素首先被插入到堆的末尾。
   - 通过上浮操作，新元素被调整到正确的位置以维持堆的性质。

3. **删除最大值**
   - `deleteMax` 函数删除并返回堆顶元素（最大值）。
   - 堆顶元素被堆的最后一个元素替换。
   - 通过下沉操作，堆顶元素被调整到正确的位置以维持堆的性质。

4. **打印堆**
   - `printHeap` 函数打印堆中的所有元素。

### 运行示例

输入：
```c
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 25);
```

输出：
```
MaxHeap: 30 25 15 10 20 
Deleted max: 30
MaxHeap after deletion: 25 20 15 10 
```

这段代码展示了一个简单的最大堆的实现和使用示例。类似的方法也可以用于实现最小堆，只需稍微修改比较运算符即可。