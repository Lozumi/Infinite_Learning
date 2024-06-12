#include <stdio.h>
#define MAXSIZE 100
#define ElemType int

typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}SeqStack;

void InitStack(SeqStack *S)
{
    S->top=-1;
}

int Push(SeqStack *S,ElemType x)
{
    if(S->top==MAXSIZE-1)
        return 0;
    S->top++;
    S->elem[S->top]=x;
    return 1;
}

int Pop(SeqStack *S, ElemType *x)
{
    if(S->top==-1)
        return 0;
    *x=S->elem[S->top];
    S->top--;
    return 1;
}

int GetTop(SeqStack *S, ElemType *x)
{
    if(S->top==-1)
        return 0;
    *x = S->elem[S->top];
    return 1;
}
int IsEmpty(SeqStack *S)
{
    if (S->top==-1)
        return 1;
    return 0;
}

void BracketMatch(char* str)
{
    SeqStack S;
    int i;
    char ch;
    InitStack(&S);
    for(i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
            case '(':
            case '[':
            case '{':
                Push(&S,str[i]);
                break;
            case ')':
            case ']':
            case '}':
                if(IsEmpty(&S))
                {
                    printf("右括号多余");
                    return 0;
                }
                else
                {
                    GetTop(&S,&ch);
                    if(match(ch,str[i]))
                        Pop(&S,&ch);
                    else
                    {
                        printf("左右括号不对应");
                        return 0;
                    }
                }
        }
    if(IsEmpty(&S))
        printf("括号匹配");
    else
        printf("左括号多余");
}