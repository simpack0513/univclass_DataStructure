//스택 2개로 큐 만들기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 20

typedef struct
{
    char data[SIZE];
    int top;
}StackType;

typedef struct 
{
    StackType *S1;
    StackType *S2;
}QueueType;


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

void printS1(StackType* S)
{
    for(int i = 0; i <= S->top; i++)
        printf("[%c]", S->data[i]);   
}

void printS2(StackType* S)
{
    for(int i = S->top; i >= 0; i--)
        printf("[%c]", S->data[i]);   
}

void initQueue(QueueType *Q) {
    Q->S1 = (StackType *)malloc(sizeof(StackType));
    Q->S2 = (StackType *)malloc(sizeof(StackType));

    init(Q->S1); init(Q->S2);
}

int isEmptyQueue(QueueType *Q) {
    return (isEmpty(Q->S1) && isEmpty(Q->S2) );
}

int isFullQueue(QueueType *Q) {
    return (isFull(Q->S1));
}

void enqueue(QueueType *Q, char e) {
    if(isFullQueue(Q)) printf("FULL\n");
    else {
        push(Q->S1, e);
    }
}

char dequeue(QueueType *Q) {
    if(isEmptyQueue(Q)) return 0;
    if(isEmpty(Q->S2)) {
        while (!isEmpty(Q->S1))
        {
            push(Q->S2, pop(Q->S1));
        }
    }
    return pop(Q->S2);
}

void printQueue(QueueType *Q) {
    printS2(Q->S2);
    printS1(Q->S1);
    printf("\n\n");
}

int main()
{
    QueueType Q;
    initQueue(&Q);

    srand(time(NULL));
    for(int i=0; i<7; i++) {
        enqueue(&Q, rand()%26+'A'); // A~Z 난수 발생
    }
    printQueue(&Q);

    for(int i=0; i<3; i++) {
        dequeue(&Q); // 3개 지우기
    }
    printQueue(&Q);

    for(int i=0; i<5; i++) {
        enqueue(&Q, rand()%26+'A'); // A~Z 난수 발생
    }
    printQueue(&Q);
    


    return 0;
}