#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Initsize 500

typedef int Elemtype;

typedef struct {
    Elemtype *base;
    int Front;
    int rear;
    int length;
} Quene, *PQuene;

PQuene Init_quene() {
    PQuene p;
    p = (PQuene)malloc(sizeof(Quene));
    p->base = (Elemtype *)malloc(sizeof(Elemtype) * Initsize);
    if (p == NULL) {
        printf("Error Init");
        return p;
    }
    p->length = p->Front = 0;
    p->rear = 0;
    return p;
}

void enQuene(PQuene p, Elemtype x, int Size) {
    if ((p->rear) % Size == p->Front && p->length != 0) {
        printf("Error enQuene");
        return;
    }
    if (p->rear == -1) p->rear = 0;
    p->base[p->rear] = x;
    p->rear = (p->rear + 1) % Size;
    p->length++;
}

Elemtype deQuene(PQuene p, int Size) {
    Elemtype x;
    x = p->base[p->Front];
    p->Front = (p->Front + 1) % Size;
    p->length--;
    return x;
}

int isfull(PQuene p, int Size) {
    return (p->length == Size);
}

int isnull(PQuene p) {
    return (p->length == 0);
}

int show(PQuene p, int Size) {
    int i;
    if (isnull(p)) return -1;
    i = p->Front;
    printf("%d ", p->base[i]);
    i = (i + 1) % Size;
    while (i != (p->rear) % Size) {
        printf("%d ", p->base[i]);
        i = (i + 1) % Size;
    }
    printf("\n");
    return 0;
}

int showtop(PQuene p) {
    if (isnull(p)) return -1;
    printf("%d\n", p->base[p->Front]);
    return 0;
}

int main() {
    int i = 0, out, flag = 0, Size;
    int data = 0;
    char s[100], c;

    PQuene pquene;
    scanf("%d", &Size);
    pquene = Init_quene();
    getchar();
    gets(s);
    while (s[i] != '\0') {
        if (s[i] == ' ' && flag == 1) {
            enQuene(pquene, data, Size);
            data = 0;
            i++;
            flag = 0;
            continue;
        }
        flag = 1;
        c = s[i++];
        data = data * 10 + (c - 48);
    }
    enQuene(pquene, data, Size);
    char zf[50];
    gets(zf);
    scanf("%d", &out);

    while (deQuene(pquene, Size) != out);
    show(pquene, Size);
    showtop(pquene);
    return 0;
}
