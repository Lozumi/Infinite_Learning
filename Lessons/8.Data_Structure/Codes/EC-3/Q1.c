#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义栈结构
typedef struct {
    char *array; // 存储栈元素的数组
    int top; // 栈顶指针
    int capacity; // 栈的容量
} Stack;

// 初始化栈
Stack* initStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->array = (char *)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// 入栈
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// 出栈
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

// 判断括号是否配对
int isParenthesesMatch(char *expression) {
    Stack *stack = initStack(strlen(expression));
    int i;
    char c;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return 0; // 右括号多余，不匹配
            }
            c = pop(stack);
            if ((c == '(' && expression[i] != ')') ||
                (c == '[' && expression[i] != ']') ||
                (c == '{' && expression[i] != '}')) {
                free(stack->array);
                free(stack);
                return 0; // 括号不匹配
            }
        }
    }

    int result = isEmpty(stack); // 判断是否有左括号未匹配
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expression[100];
    // printf("请输入表达式：");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0'; // 移除末尾的换行符

    if (isParenthesesMatch(expression)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
