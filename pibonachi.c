// 과제 2 2번 큐로 피보나치 수열 계산하기

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

typedef struct
{
    int front;
    int rear;
    int data[SIZE];
}QueueType;

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(QueueType *q) {
    return (q->front==q->rear);
}

int isFull(QueueType *q) {
    return (q->rear + 1)%SIZE == q->front;
}

void enqueue(QueueType *q, int e) {
    if(isFull(q)) printf("FULL\n");
    else {
        q->rear = (q->rear+1)%SIZE;
        q->data[q->rear] = e;
    }
}

void print(QueueType *q) {
    printf("Front Pos : %d Rear Pos : %d\n", q->front, q->rear);
    int i=q->front;
    while (i!=q->rear)
    {
        i = (i+1)%SIZE;
        printf("[%d]", q->data[i]);
    }
    
    printf("\n\n");
}

int dequeue(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        q->front = (q->front+1)%SIZE;
        return q->data[q->front];
    }
}

int peek(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        return q->data[(q->front+1)%SIZE];
    }
}

int Fibonacci(QueueType *q, int num) {
    enqueue(q, 0); enqueue(q, 1);
    int cn = 1;
    for(int i=0; i<num-1; i++) {
        cn = cn + dequeue(q);
        enqueue(q, cn);
    }
    return cn;


}


int main() {
    QueueType Q;
    init_queue(&Q);
    int num;
    printf("구하고 싶은 항의 값(0번째 항의 값은 0, 1번쨰 항의 값은 1) : ");
    scanf("%d", &num);

    printf("[%d]항의 계산된 값 : %d", num, Fibonacci(&Q, num));



    return 0;
}