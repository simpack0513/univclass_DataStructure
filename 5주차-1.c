#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

typedef struct
{
    int front;
    int rear;
    char data[SIZE];
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

void enqueue(QueueType *q, char e) {
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
        printf("[%c]", q->data[i]);
    }
    
    printf("\n\n");
}

char dequeue(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        q->front = (q->front+1)%SIZE;
        return q->data[q->front];
    }
}

char peek(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        return q->data[(q->front+1)%SIZE];
    }
}



int main() {
    QueueType Q;
    init_queue(&Q);

    srand(time(NULL));
    for(int i=0; i<7; i++) {
        enqueue(&Q, rand()%26+'A'); // A~Z 난수 발생
    }
    print(&Q);

    for(int i=0; i<3; i++) {
        dequeue(&Q); // 3개 지우기
    }
    print(&Q);

    for(int i=0; i<5; i++) {
        enqueue(&Q, rand()%26+'A'); // A~Z 난수 발생
    }
    print(&Q);




    return 0;
}