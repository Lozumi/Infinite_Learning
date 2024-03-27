//
// Created by Lozumi on 2024/3/20.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *mergeLists(Node *a, Node *b) {
    Node *c = NULL;
    Node *tail = NULL;

    while (a != NULL && b != NULL) {
        Node *temp;
        if (a->data <= b->data) {
            temp = a;
            a = a->next;
        } else {
            temp = b;
            b = b->next;
        }
        temp->next = c;
        c = temp;
        if (tail == NULL)
            tail = c;
    }

    while (a != NULL) {
        Node *temp = a;
        a = a->next;
        temp->next = c;
        c = temp;
        if (tail == NULL)
            tail = c;
    }

    while (b != NULL) {
        Node *temp = b;
        b = b->next;
        temp->next = c;
        c = temp;
        if (tail == NULL)
            tail = c;
    }

    return c;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *a = NULL;
    Node *b = NULL;

    // Constructing list A
    a = (Node *)malloc(sizeof(Node));
    a->data = 2;
    a->next = (Node *)malloc(sizeof(Node));
    a->next->data = 5;
    a->next->next = (Node *)malloc(sizeof(Node));
    a->next->next->data = 7;
    a->next->next->next = NULL;

    // Constructing list B
    b = (Node *)malloc(sizeof(Node));
    b->data = 3;
    b->next = (Node *)malloc(sizeof(Node));
    b->next->data = 6;
    b->next->next = (Node *)malloc(sizeof(Node));
    b->next->next->data = 8;
    b->next->next->next = NULL;

    printf("List A: ");
    printList(a);

    printf("List B: ");
    printList(b);

    Node *c = mergeLists(a, b);

    printf("Merged list C: ");
    printList(c);

    return 0;
}
