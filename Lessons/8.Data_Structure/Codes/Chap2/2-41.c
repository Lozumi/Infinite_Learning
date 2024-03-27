//
// Created by Lozumi on 2024/3/20.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coef;
    int exp;
} PolyTerm;

typedef struct PolyNode {
    PolyTerm data;
    struct PolyNode *next;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly;

// 求稀疏多项式的导函数
LinkedPoly derivative(LinkedPoly poly) {
    PolyNode *p = poly->next;
    PolyNode *q = (PolyNode *)malloc(sizeof(PolyNode)); // 导函数多项式的头结点
    PolyNode *rear = q; // 导函数多项式的尾指针
    q->next = q; // 初始化导函数多项式的循环链表

    while (p != poly) {
        if (p->data.exp != 0) { // 指数不为0时，需要添加到导函数多项式中
            PolyNode *temp = (PolyNode *)malloc(sizeof(PolyNode));
            temp->data.coef = p->data.coef * p->data.exp;
            temp->data.exp = p->data.exp - 1;
            rear->next = temp;
            rear = temp;
        }
        PolyNode *temp = p;
        p = p->next;
        free(temp); // 释放原多项式的结点空间
    }
    rear->next = q; // 形成导函数多项式的循环链表
    return q;
}

// 打印多项式
void printPoly(LinkedPoly poly) {
    PolyNode *p = poly->next;
    printf("Polynomial: ");
    while (p != poly) {
        printf("(%dx^%d) ", p->data.coef, p->data.exp);
        p = p->next;
    }
    printf("\n");
}

int main() {
    // 构造稀疏多项式
    PolyNode *poly = (PolyNode *)malloc(sizeof(PolyNode)); // 头结点
    poly->next = poly; // 构成循环链表
    PolyNode *rear = poly; // 尾指针

    // 添加多项式项
    PolyTerm terms[] = {{2, 3}, {3, 2}, {4, 1}, {5, 0}};
    for (int i = 0; i < sizeof(terms) / sizeof(PolyTerm); i++) {
        PolyNode *temp = (PolyNode *)malloc(sizeof(PolyNode));
        temp->data = terms[i];
        rear->next = temp;
        rear = temp;
    }
    rear->next = poly; // 形成循环链表

    // 打印原多项式
    printf("Original Polynomial:\n");
    printPoly(poly);

    // 求导函数多项式
    LinkedPoly derivativePoly = derivative(poly);

    // 打印导函数多项式
    printf("Derivative Polynomial:\n");
    printPoly(derivativePoly);

    // 释放导函数多项式的结点空间
    PolyNode *p = derivativePoly->next;
    while (p != derivativePoly) {
        PolyNode *temp = p;
        p = p->next;
        free(temp);
    }
    free(derivativePoly); // 释放头结点
    free(poly); // 释放原多项式的头结点

    return 0;
}
