# 第二章 上机实验

## 第1关 合并有序数组

### 任务描述

给定两个按照升序排列的有序数组，请把它们合成一个升序数组并输出。

### 编程要求

根据提示，在右侧编辑器补充代码，完成合并有序数组。

### 测试说明

**输入说明：** 第一行为第一个有序数组的长度，正整数 `n`，`n<=20` ； 第二行为第一个有序数组的 `n` 个数字，用空格隔开； 第三行为第二个有序数组的长度，正整数`m`，`m<=20`； 第四行为第二个有序数组的 `m` 个数字，用空格隔开。 **输出说明：** 输出合并后的数组，每个数字占一行。

平台会对你编写的代码进行测试：

测试输入：

```
3
1 3 7
5
2 4 6 8 10
```

预期输出：

```
1
2
3
4
6
7
8
10
```

### 分析思路

我们需要合并两个已经按照升序排列的有序数组，并将结果以升序排列输出。这类问题可以通过“归并排序”的合并过程来高效解决，即通过双指针技术逐一比较两个数组中的元素，并将较小的元素依次放入新数组中。

### 解决方案

1. **输入数据处理**:
   - 读取第一个数组的长度 `n` 和数组元素。
   - 读取第二个数组的长度 `m` 和数组元素。
2. **合并过程**:
   - 使用三个指针 `i`, `j`, `k` 分别指向第一个数组、第二个数组及合并后数组的当前元素位置。
   - **比较两个数组当前元素，将较小的元素放入合并后数组**，并移动相应的指针。
   - 当一个数组的所有元素都放入合并后数组后，**直接将另一个数组剩余元素放入合并后数组**。
3. **输出结果**:
   - 输出合并后的数组中的每个元素。

### 源代码

```c
/* 合并两个有序数组为一个升序数组
 * 作者：Lozumi
 * 版本：1.0.0
 */

#include <stdio.h>

void mergeSortedArrays(int arr1[], int n, int arr2[], int m) {
    int mergedArray[n + m]; // 创建新数组来存储合并后的结果
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
//    printf("合并后的数组为：\n");
    for (i = 0; i < n + m; i++) {
        printf("%d\n", mergedArray[i]);
    }
}

int main() {
    int n, m;
//    printf("请输入第一个有序数组的长度：\n");
    scanf("%d", &n);
    int arr1[n];
//    printf("请输入第一个有序数组的元素：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

//    printf("请输入第二个有序数组的长度：\n");
    scanf("%d", &m);
    int arr2[m];
//    printf("请输入第二个有序数组的元素：\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    // 调用合并函数
    mergeSortedArrays(arr1, n, arr2, m);

    return 0;
}

```



## 第2关 高精度计算PI值

### 任务描述

限制使用双向链表作存储结构，请根据用户输入的一个整数（该整数表示精确到小数点后的位数，可能要求精确到小数点后 500 位），高精度计算PI值。可以利用反三角函数幂级展开式来进行计算。

### 编程要求

根据提示，在右侧编辑器补充代码。

### 测试说明

**输入说明**：输入的一个正整数`n`。 **输出说明**：输出`PI`的值，精确到小数点后`n`位，最后输出一个回车。

平台会对你编写的代码进行测试：

测试输入：`5` 预期输出：`3.14159`

### 分析思路

可以使用反正切函数的幂级数展开来计算 PI 值，公式如下：
$$ \arctan(1) = \frac{\pi}{4} $$
$$ \pi = 4 \cdot \sum_{k=0}^{\infty} \frac{(-1)^k}{2k+1} $$

为了实现高精度计算，将采用双向链表存储大数并进行高精度运算。

### 实现步骤

1. **初始化双向链表**：用于存储计算过程中的大数。
2. **链表的基本操作**：
   - **初始化链表**：创建一个初始链表。
   - **扩展链表**：在链表末尾添加节点。
   - **链表加法**：将两个链表表示的大数相加。
   - **链表乘法**：将链表表示的大数乘以一个整数。
   - **链表除法**：将链表表示的大数除以一个整数。
3. **计算 PI**：
   - 使用反正切函数的幂级数展开来逐项累加计算 PI 的值。
4. **输出结果**：按照指定精度输出 PI 值。

### 源代码

```c
/* 限制使用双向链表作存储结构，高精度计算PI值。
 * 作者：Lozumi
 * 版本：1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

// 定义双向链表的节点结构
typedef struct Node {
    int data; // 存储节点的数据
    struct Node *prev; // 指向前一个节点的指针
    struct Node *next; // 指向下一个节点的指针
} Node, *LinkedList;

// 函数声明
LinkedList initializeList(); // 初始化链表
void extendList(LinkedList list, int data); // 扩展链表
void multiplyList(LinkedList list, int factor); // 链表乘法
void divideList(LinkedList list, int divisor); // 链表除法
void addList(LinkedList list1, LinkedList list2); // 链表相加
void printList(LinkedList list, int decimalPlaces); // 打印链表
void destroyList(LinkedList list); // 销毁链表

int main() {
    int decimalPlaces;
    // printf("输入保留小数位数: ");
    scanf("%d", &decimalPlaces);
    
    LinkedList num = initializeList(); // 初始化num链表
    LinkedList sum = initializeList(); // 初始化sum链表
    
    // 扩展num和sum链表以存储足够多的数字
    for (int i = 0; i < 600; i++) {
        extendList(num, 0);
        extendList(sum, 0);
    }
    
    // 计算圆周率Pi
    for (int j = 1, k = 3; j < 2000; j++) {
        multiplyList(num, j);  // 链表乘以j
        divideList(num, k);    // 链表除以k
        addList(num, sum);     // 将num链表和sum链表相加
        k += 2;                // 更新除数
    }
    
    // 打印结果
    // printf("保留%d位小数的估计结果: ", decimalPlaces);
    printList(sum, decimalPlaces); // 打印sum链表，保留decimalPlaces位小数
    
    // 释放内存
    destroyList(num); // 销毁num链表
    destroyList(sum); // 销毁sum链表
    
    return 0;
}

// 初始化链表函数
LinkedList initializeList() {
    // 创建一个只包含一个节点的链表，该节点存储数字2
    LinkedList list = (LinkedList)malloc(sizeof(Node));
    list->data = 2;
    list->prev = list; // 指向自己，表示链表只有这一个节点
    list->next = list; // 指向自己，表示链表只有这一个节点
    return list;
}

// 扩展链表函数
void extendList(LinkedList list, int data) {
    // 在链表末尾添加一个节点
    LinkedList tmp = list;
    if (tmp == NULL) {
        return;
    }
    tmp = tmp->prev; // 移动到最后一个节点
    LinkedList newNode = (LinkedList)malloc(sizeof(Node)); // 创建新节点
    newNode->data = data; // 设置新节点的数据
    newNode->next = tmp->next; // 新节点的下一个节点是原链表的第一个节点
    newNode->prev = tmp; // 新节点的前一个节点是原链表的最后一个节点
    tmp->next->prev = newNode; // 更新原链表第一个节点的前一个节点指针
    tmp->next = newNode; // 更新原链表最后一个节点的下一个节点指针
}

// 链表乘法函数
void multiplyList(LinkedList list, int factor) {
    // 将链表表示的数字与一个整数相乘
    int tmp, carry = 0;
    LinkedList p = list->prev; // 从链表的最后一个节点开始
    while (p != list) { // 遍历整个链表
        tmp = p->data * factor + carry; // 乘法运算加上进位
        p->data = tmp % 10; // 存储当前位的结果
        carry = tmp / 10; // 更新进位
        p = p->prev; // 移动到前一个节点
    }
    p->data += carry; // 处理最后一个节点的进位
}

// 链表除法函数
void divideList(LinkedList list, int divisor) {
    // 将链表表示的数字除以一个整数
    int tmp, remainder = 0;
    LinkedList p = list; // 从链表的第一个节点开始
    while (1) { // 遍历整个链表
        tmp = p->data + remainder * 10; // 除法运算
        remainder = tmp % divisor; // 计算余数
        p->data = tmp / divisor; // 存储商
        p = p->next; // 移动到下一个节点
        if (p == list) break; // 如果到达链表末尾，则结束循环
    }
}

// 链表相加函数
void addList(LinkedList list1, LinkedList list2) {
    // 将两个链表表示的数字相加
    int tmp, carry = 0;
    LinkedList p = list1->prev; // 从链表1的最后一个节点开始
    LinkedList q = list2->prev; // 从链表2的最后一个节点开始
    while (1) { // 遍历两个链表直到结束
        tmp = p->data + q->data + carry; // 加法运算加上进位
        q->data = tmp % 10; // 存储当前位的结果
        carry = tmp / 10; // 更新进位
        p = p->prev; // 移动到链表1的前一个节点
        q = q->prev; // 移动到链表2的前一个节点
        if (p == list1->prev) break; // 如果到达链表1的末尾，则结束循环
    }
}

// 打印链表函数
void printList(LinkedList list, int decimalPlaces) {
    // 打印链表表示的数字，保留指定的小数位数
    LinkedList p = list; // 从链表的第一个节点开始
    printf("%d.", p->data); // 打印小数点前的数字
    p = p->next; // 移动到小数点后的节点
    for (int i = 0; i < decimalPlaces; i++) { // 打印小数点后的数字
        printf("%d", p->data);
        p = p->next; // 移动到下一个节点
    }
    printf("\n"); // 打印换行符
}

// 销毁链表函数
void destroyList(LinkedList list) {
    // 释放链表所占用的内存
    LinkedList tmp = list->next; // 临时指针用于释放内存
    while (tmp != list) { // 遍历链表
        list->next = tmp->next; // 更新链表的下一个节点指针
        free(tmp); // 释放当前节点
        tmp = list->next; // 更新临时指针
    }
    list->prev = list; // 确保链表正确闭合
    free(list); // 释放链表的头节点
    list = NULL; // 确保不会有悬挂指针
}
```

