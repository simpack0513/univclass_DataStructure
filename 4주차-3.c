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

int prec(char c) {
    switch (c)
    {
    case '+': case '-':
        return 1;
    case '/': case '*':
        return 2;
    case '(': case ')':
        return 0;
    default:
    return 0;
        break;
    }
}

void convert(char IN_str[], char *POST_str) {
    char c,t;
    StackType S;
    init(&S);
    int n = strlen(IN_str);
    int top = 0;

    for(int i=0; i<n; i++) {
        c = IN_str[i];
        switch (c)
        {
        case '+': case'-': case'/': case'*':
            while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
            {
                POST_str[top++] = pop(&S);
            }
            push(&S, c);
            
            break;
        case '(':
            push(&S, c);
            break;

        case ')':
            t = pop(&S);
            while (t!= '(')
            {
                POST_str[top++] = t;
                t = pop(&S);
            }
            break;

        default:
            POST_str[top++] = c;
            break;
        }

    }
    while (!isEmpty(&S))
    {
        POST_str[top++] = pop(&S);
    }
    printf("\n");
    
    
}

void print_str(char str[]) {
    int n = strlen(str);
    for(int i=0; i<n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}



int main()
{
    char POST_str[SIZE], IN_str[SIZE];

    scanf("%s", IN_str);
    convert(IN_str, POST_str);
    print_str(POST_str);
    printf("%d\n", elvaluate(POST_str));

    return 0;
}