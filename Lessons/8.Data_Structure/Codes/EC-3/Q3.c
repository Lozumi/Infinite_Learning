#include<stdio.h>
#include <stdlib.h>	

#define max 7

typedef int elem;
typedef struct 
{
	elem* base;//数组指针，表示队列
	int rear;
	//表示队尾元素
	int length;
}queue;

queue* initqueue(queue* q) 
{
	q->base = (elem*)malloc(max * sizeof(elem));
	q->rear = 0;
	q->length = 0;
	
	return q;
}

queue* fillqueue(queue* q, int number) 
{
	int i = 0;
	int add;
	int sum=0;

	do
	{
		scanf("%d", &add);
		q->base[q->rear] = add;
		q->rear = (q->rear + 1) % max;
		q->length++;

	} while (getchar() != '\n');
	
	return q;
}

queue* judge(queue* q,int number)
{
	if (q->length == number)
	{
		printf("yes\n");

		return q;
	}

	else
	{
		printf("no\n");
		return q;
	}
}

queue* dequeue(queue* q, int tar) //)报错，说明前面的逗号是中文
{
	elem x;

	if (q->length == 0)
	{
		printf("error");
		return q;
	}

	int i;
	for (i = 0; i < q->length; i++)
	{
		if (q->base[i] == tar)
		{
			break;
		}
	}

	int pr;
	for (pr = i + 1; pr < q->length; pr++)
	{
		if (pr == q->length - 1)
		{
			printf("%d", q->base[pr]);
		}

		else
		{
			printf("%d ", q->base[pr]);
		}
	}
	printf("\n%d", q->base[i+1]);

	return q;
}

int main() 
{
	queue* q;
	q = (queue*)malloc(sizeof(queue));//开空间，不然报错未识别局部变量。

	q= initqueue(q);

	int number;
	scanf("%d", &number);

	q = fillqueue(q, number);

	int target;
	scanf("%d", &target);

	q = judge(q, number);
	q = dequeue(q, target);


}