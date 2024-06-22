# 第五章 上机作业

## 第1关 稀疏矩阵的转置矩阵

### 任务描述

输出稀疏矩阵的转置矩阵。（行列均不大于20）

### 测试说明

**输入说明：** 第一行输入两个正整数 `n` 和 `m` ,分别表示矩阵的行数和列数, 然后输入矩阵三元组， 最后输入（`0 0 0`）表示结束输入。

**输出说明：** 转置后的矩阵。

平台会对你编写的代码进行测试：

测试输入：

```
4 4
1 1 1
2 1 2
3 2 3
0 0 0
```

预期输出：

```
1 1 1
1 2 2
2 3 3
```

### 源代码

```C
#include <stdio.h>
#define MAX 1000

// 定义三元组结构体，表示矩阵的非零元素
typedef struct {
    int row, col, value; // 行号、列号和该位置的值
} Triple;

// 定义稀疏矩阵的结构体
typedef struct {
    Triple data[MAX]; // 存储非零元素的数组
    int rows, cols, nonZeroCount; // 矩阵的行数、列数和非零元素的个数
} TSMatrix;

// 稀疏矩阵的转置函数
void Transpose(TSMatrix A, TSMatrix *B, int nonZeroCount) {
    int currentIndex, i, j;

    // 将原矩阵的行数赋给转置矩阵的列数，将原矩阵的列数赋给转置矩阵的行数
    B->rows = A.cols;
    B->cols = A.rows;

    // 如果矩阵A有非零元素
    if (nonZeroCount) {
        currentIndex = 0;
        // 遍历A矩阵的每一列
        for (i = 0; i < A.cols; i++) {
            // 遍历A矩阵的每一个非零元素
            for (j = 0; j < nonZeroCount; j++) {
                // 如果非零元素在第i列
                if (A.data[j].col == i) {
                    // 交换行和列并赋值给转置矩阵
                    B->data[currentIndex].row = A.data[j].col;
                    B->data[currentIndex].col = A.data[j].row;
                    B->data[currentIndex].value = A.data[j].value;
                    currentIndex++;
                }
            }
        }
    }
}

int main() {
    int rows, cols, nonZeroCount = 0;

    // 读取矩阵的行数和列数
    scanf("%d %d", &rows, &cols);
    TSMatrix A, B;
    A.rows = rows;
    A.cols = cols;

    // 获取初始矩阵A的非零元素
    while (1) {
        int row, col, value;
        // 读取非零元素的行、列和值
        scanf("%d %d %d", &row, &col, &value);
        // 输入0 0 0表示结束
        if (row == 0 && col == 0 && value == 0) // (0 0 0)结束
            break;
        A.data[nonZeroCount].row = row;
        A.data[nonZeroCount].col = col;
        A.data[nonZeroCount].value = value;
        nonZeroCount++;
    }

    // 转置矩阵A到矩阵B
    Transpose(A, &B, nonZeroCount);

    // 输出转置后的矩阵B的非零元素
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d %d %d\n", B.data[i].row, B.data[i].col, B.data[i].value);
    }

    return 0;
}

```

## 第2关 稀疏矩阵加法

### 任务描述

输入两个稀疏矩阵，输出它们相加的结果。

### 编程要求

根据提示，在右侧编辑器补充代码，完成稀疏矩阵加法,实现C=A+B。

### 测试说明

**输入说明：** 第一行输入四个正整数，分别是两个矩阵的行`m`、列`n`、第一个矩阵的非零元素的个数`t1`和第二个矩阵的非零元素的个数`t2`。 接下来的`t1+t2`行是三元组，分别是第一个矩阵的数据和第二个矩阵的数据。三元组的第一个元素表示行号，第二个元素表示列号，第三个元素是该项的值。

**输出说明：** 输出相加后的矩阵三元组。

平台会对你编写的代码进行测试：

测试输入：

```
3 4 3 2
1 1 1
1 3 1
2 2 2
1 2 1
2 2 3
```

预期输出：

```
1 1 1
1 2 1
1 3 1
2 2 5
```

### 解决思路

1. **输入矩阵信息**：首先读取两个矩阵的行数、列数以及每个矩阵的非零元素个数。
2. **读取矩阵数据**：将两个矩阵的非零元素读入各自的三元组数组中。
3. **初始化结果矩阵**：初始化结果矩阵，行数和列数与输入矩阵相同。
4. **矩阵相加**：遍历两个矩阵的三元组数组，按照行、列顺序比较并相加。
   - 若第一个矩阵的三元组行号小于第二个矩阵的行号，或行号相同时列号小，则将第一个矩阵的三元组添加到结果矩阵中。
   - 若第二个矩阵的三元组行号小于第一个矩阵的行号，或行号相同时列号小，则将第二个矩阵的三元组添加到结果矩阵中。
   - 若行号和列号相同，则将对应的值相加，若结果不为零，则添加到结果矩阵中。
5. **输出结果矩阵**：输出结果矩阵的所有非零元素。

### 源代码

```c
#include <stdio.h>
#define MAX 1000


//定义三元组结构体
typedef struct {
	int r, c;
	//所在行数和列数
	int d;
	//所表示的值
} Triple;


//存储矩阵的三元组顺序表
typedef struct {
	Triple data[MAX];
	int m, n, t;
	//存储这个矩阵当中信息，m行，n列，t个非0元素
} TsMatrix;


//稀疏矩阵的加法，返回值为新矩阵
TsMatrix PlusMatrix(TsMatrix a, TsMatrix b) {
	int i = 0, k = 0, j = 0;
	TsMatrix c;
	c.t = 0;
	c.m = a.m;
	c.n = a.n;
//初始化返回的新矩阵

	while (i <= a.t && j <= b.t && (!(i == a.t && j == b.t))) {
		//判断条件
		//按照从上到下从左到右的顺序依次遍历，先比较同行，再比较同列
		if (a.data[i].r < b.data[j].r || (a.data[i].r == b.data[j].r && a.data[i].c < b.data[j].c)) {
			c.data[k++] = a.data[i++];
			c.t++;
		} else if (a.data[i].r > b.data[j].r || (a.data[i].r == b.data[j].r && a.data[i].c > b.data[j].c)) {
			c.data[k++] = b.data[j++];
			c.t++;
		}
		//考虑相加和为0的情况，如果不为零则保留
		else {
			if (a.data[i].d + b.data[j].d != 0) {
				c.data[k] = a.data[i]; //初始化！
				c.data[k++].d = a.data[i++].d + b.data[j++].d;
				c.t++;
			}
		}
	}
	return c;
}



int main() {
	int m, n, t1, t2;
	scanf("%d %d %d %d", &m, &n, &t1, &t2);
	TsMatrix a, b, c;
	a.m = b.m = m;
	a.n = b.n = n;
	a.t = t1, b.t = t2;

	for (int i = 0; i < t1; i++) {
		scanf("%d %d %d", &a.data[i].r, &a.data[i].c, &a.data[i].d);
	}

	for (int i = 0; i < t2; i++) {
		scanf("%d %d %d", &b.data[i].r, &b.data[i].c, &b.data[i].d);
	}
	//获取要相加的两个矩阵a,b

	c = PlusMatrix(a, b);

	//逐个输出相加后的矩阵元素
	for (int i = 0; i < c.t ; i++) {
		printf("%d %d %d\n", c.data[i].r, c.data[i].c, c.data[i].d);
	}
	return 0;
}
```

## 第3关 

## 第4关 稀疏矩阵的乘法

### 任务描述

计算两个稀疏矩阵的乘法。

### 编程要求

根据提示，在右侧编辑器补充代码，完成两个稀疏矩阵的乘法运算。

### 测试说明

**输入说明**： 首先输入第一个矩阵的行数和列数，再输入该矩阵的三元组形式，以`0 0 0`结束。 然后输入第二个矩阵的行数和列数，再输入该矩阵的三元组形式，以`0 0 0`结束。

**输出说明**： 输出相加后的矩阵三元组。

### 解决思路

1. **定义数据结构**：我们将使用三元组表示稀疏矩阵，即每个非零元素用一个结构体记录其行号、列号和值。
2. **输入矩阵数据**：首先读取矩阵的维度，然后依次读取所有非零元素的三元组表示。
3. **矩阵乘法**：对于稀疏矩阵的乘法，我们需要确保列数与行数匹配。计算结果矩阵的每个非零元素时，通过两个输入矩阵的非零元素相乘并累加。
4. **输出结果**：将结果矩阵中的非零元素以三元组形式输出。

### 代码实现

```c
#include <stdio.h>

//定义三元组结构体
typedef struct {
	int r, c;
	//所在行数和列数
	int d;
	//所表示的值
} Triple;

//一个矩阵的数据类型
typedef struct {
	Triple list[1000];
	//1000个三元表
	int m, n, t;
	//存储这个矩阵当中信息，m行，n列，t个非0元素
	int rpos[1000];
} Matrix;


void InitMatrix(Matrix *a);//初始化矩阵

void OutputMatrix(Matrix a);//输出函数，将三元组表内矩阵信息以三元组形式输出

void MutiplyMatrix(Matrix a, Matrix b, Matrix *c); //矩阵相乘


int main() {
	Matrix a, b, c;
	InitMatrix(&a);
	InitMatrix(&b);
	MutiplyMatrix(a, b, &c);
	OutputMatrix(c);
	return 0;
}


//初始化矩阵
void InitMatrix(Matrix *A) {
	int i, j, k;
	scanf("%d %d", &A->m, &A->n);
	A->t = 0;
	while (1) {
		scanf("%d %d %d", &i, &j, &k);
		if (i == 0 && j == 0 && k == 0)
			break;
		//当输入0 0 0时结束
		A->t++;
		//从1开始
		A->list[A->t].r = i;
		A->list[A->t].c = j;
		A->list[A->t].d = k;
		A->rpos[i]++;
		//输入时设计rpos前缀和数组，记录第i行中的非0元素个数
	}

	//通过两个for循环，算出第i行中第一个元素在其三元组表中的位置，并将其存储在对应的rpos[i]数组当中
	for (int i = 1; i <= A->m; i++)
		A->rpos[i] += A->rpos[i - 1];
	for (int i = A->m; i >= 1; i--)
		A->rpos[i] = A->rpos[i - 1] + 1;
}

//矩阵相乘
void MutiplyMatrix(Matrix a, Matrix b, Matrix *c) {
	//对c矩阵的基本信息初始化赋值
	c->m = a.m;
	c->n = b.n;
	c->t = 0;
	int t[1000] = {0};
	int x, y, z, s;
	//判断条件是否不等于0
	if (a.t * b.t != 0) {
		for (int i = 1; i <= a.m; i++) {
			for (int j = 1; j <= a.n; j++)
				t[j] = 0;
			c->rpos[i] = c->t + 1;

			if (i < a.m)
				x = a.rpos[i + 1];
			else
				x = a.t + 1;

			for (int p = a.rpos[i]; p < x; p++) {
				int c = a.list[p].c;

				if (c < b.m)
					y = b.rpos[c + 1];
				else
					y = b.t + 1;

				for (int q = b.rpos[c]; q < y; q++) {
					z = b.list[q].c;
					t[z] += (a.list[p].d * b.list[q].d);
				}
			}
			//求a.list[p].d 和 b.list[q].d的乘积

			for (int k = 1; k <= c->n; k++) {
				if (t[k]) {
					c->t++;
					c->list[c->t].r = i;
					c->list[c->t].c = k;
					c->list[c->t].d = t[k];
				}
			}
			//

		}
	}
}

//输出函数，将三元组表内矩阵信息以三元组形式输出
void OutputMatrix(Matrix A) {
	for (int i = 1; i <= A.t; i++) {
		printf("%d %d %d\n", A.list[i].r, A.list[i].c, A.list[i].d);
	}
}

```

### 代码解释

1. **数据结构**：我们定义了一个 `Triple` 结构体表示一个非零元素，以及一个 `SparseMatrix` 结构体存储稀疏矩阵的三元组形式。
2. **输入矩阵**：在 `main` 函数中，我们读取两个矩阵的维度和非零元素，分别存储在 `a` 和 `b` 中。
3. **矩阵乘法**：在 `MultiplyMatrices` 函数中，我们使用嵌套循环遍历 `a` 和 `b` 的非零元素，如果列号和行号匹配，则计算乘积并累加到 `sum` 矩阵中。
4. **输出结果**：我们将结果矩阵中的非零元素按行和列的顺序输出。

这段代码解决了稀疏矩阵的乘法问题，并使用稀疏矩阵的特性优化了计算过程。