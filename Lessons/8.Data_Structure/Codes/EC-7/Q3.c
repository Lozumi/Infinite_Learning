#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char data;
    struct Stack *next;
} Stack;

typedef struct {
    Stack *top;
    Stack *bottom;
} StackHead;

StackHead* create() {
    StackHead *stackHead = (StackHead *)malloc(sizeof(StackHead));
    Stack *bottomNode = (Stack *)malloc(sizeof(Stack));
    bottomNode->next = NULL;
    stackHead->bottom = bottomNode;
    stackHead->top = bottomNode;
    return stackHead;
}

char getTop(StackHead *s) {
    return s->top->data;
}

void pop(StackHead *s) {
    if (s->top != s->bottom) {
        Stack *q = s->top;
        s->top = s->top->next;
        free(q);
    }
}

void push(StackHead *s, char b) {
    Stack *q = (Stack *)malloc(sizeof(Stack));
    q->data = b;
    q->next = s->top;
    s->top = q;
}

int precedence(char a) {
    switch(a) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    char str[205];
    scanf("%s", str);
    int length = strlen(str);
    
    StackHead *s = create();
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i]);
        } else if (str[i] == '(') {
            push(s, str[i]);
        } else if (str[i] == ')') {
            while (getTop(s) != '(') {
                printf("%c", getTop(s));
                pop(s);
            }
            pop(s); // Pop the '(' from stack
        } else if (isOperator(str[i])) {
            while (s->top != s->bottom && precedence(getTop(s)) >= precedence(str[i])) {
                printf("%c", getTop(s));
                pop(s);
            }
            push(s, str[i]);
        }
    }
    
    while (s->top != s->bottom) {
        printf("%c", getTop(s));
        pop(s);
    }
    printf("\n");
    return 0;
}
