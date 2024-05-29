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
	OLNode *node = (OLNode *)malloc(sizeof(OLNode));
	node->row = row;
	node->col = col;
	node->value = value;
	node->right = NULL;
	node->down = NULL;

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


// 十字链表相乘
CrossList *multiplyMatrix(CrossList *A, CrossList *B) {
	CrossList *result = createCrossList(A->m, B->n);
	for (int i = 1; i < A->m + 1; i++) {
		for (int j = 1; j < B->n + 1; j++) {
			OLNode * pa = A->row_head[i];
			OLNode * pb = B->col_head[j];
			int sum = 0;
			while (pa != NULL && pb != NULL) {
				if (pa->col > pb->row) {
					pb = pb->down;
				} else if (pa->col < pb->row) {
					pa = pa->right;
				} else {	// 找到同一位置，相乘，两者都位移
					sum += pa->value * pb->value;
					pa = pa->right;
					pb = pb->down;
				}
			}
			if (sum != 0) {
				insertNode(result, i, j, sum);
			}
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

	// 使用十字链表法，结构和上一题相同，修改了运算部分

	int m, n;
	scanf("%d %d", &m, &n);
	CrossList *A = createCrossList(m, n);

	
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		} else {
			insertNode(A, a, b, c);
		}
	}
	
	
	scanf("%d %d", &m, &n);
	CrossList *B = createCrossList(m, n);
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		} else {
			insertNode(B, a, b, c);
		}
	}
	
	CrossList *C = multiplyMatrix(A, B);

	printMatrix(C);

    // 释放内存
	for (int i = 0; i < A->m + 1; i++) {
		OLink p = A->row_head[i];
		while (p != NULL) {
			OLink temp = p;
			p = p->right;
			free(temp);
		}
	}
	free(A->row_head);
	free(A->col_head);
	free(A);

	for (int i = 0; i < B->m + 1; i++) {
		OLink p = B->row_head[i];
		while (p != NULL) {
			OLink temp = p;
			p = p->right;
			free(temp);
		}
	}
	free(B->row_head);
	free(B->col_head);
	free(B);

	for (int i = 0; i < C->m + 1; i++) {
		OLink p = C->row_head[i];
		while (p != NULL) {
			OLink temp = p;
			p = p->right;
			free(temp);
		}
	}
	free(C->row_head);
	free(C->col_head);
	free(C);

	return 0;
}
