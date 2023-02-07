#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct
{
    char data[SIZE];
    int top;
}StackType;

void init(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, char c)
{
    if(isFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    
    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    
    return S->data[S->top];
}

void print(StackType* S)
{
    for(int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");    
}

int elvaluate(char str[]) {
    StackType S;
    init(&S);

    int op1, op2, value;
    char c;
    int n= strlen(str);

    for(int i =0; i<n; i++) {
        c=str[i];
        if(c=='*' || c=='/' || c=='+' || c=='-') {
            op2 = pop(&S) - '0';
            op1 = pop(&S) - '0';
            switch (c)
            {
            case '*':
            value = op1*op2 + '0';
            push(&S, value);
                break;

            case '/':
            value = op1/op2 + '0';
            push(&S, value);
                break;

            case '+':
            value = op1+op2 + '0';
            push(&S, value);
                break;

            case '-':
            value = op1-op2 + '0';
            push(&S, value);
                break;    
            
            default:
                break;
            }
        }
        else {
            push(&S, c);
        }
    }

    return pop(&S)-'0';

}




int main()
{
    char str[SIZE] = {};

    scanf("%s", str);
    printf("%d\n", elvaluate(str));

    return 0;
}