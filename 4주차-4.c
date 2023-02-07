#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    int front;
    int rear;
    char data[SIZE];
}QueueType;

void init_queue(QueueType *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(QueueType *q) {
    return (q->front==q->rear);
}

int isFull(QueueType *q) {
    return q->rear == SIZE-1;
}

void enqueue(QueueType *q, char e) {
    if(isFull(q)) printf("FULL\n");
    else {
        q->rear++;
        q->data[q->rear] = e;
    }
}

void print(QueueType *q) {
    printf("Front Pos : %d Rear Pos : %d\n", q->front, q->rear);
    for(int i=q->front+1; i==q->rear; i++) {
        printf("[%c]", q->data[i]);
    }
    printf("\n\n");
}

char dequeue(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        q->front++;
        return q->data[q->front];
    }
}

char peek(QueueType *q) {
    if(isEmpty(q)) return 0;
    else {
        return q->data[q->front+1];
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
        dequeue(&Q);
    }
    print(&Q);
    // 2번째 반복
    for(int i=0; i<5; i++) {
        enqueue(&Q, rand()%26+'A'); // A~Z 난수 발생
    }
    print(&Q);

    for(int i=0; i<3; i++) {
        dequeue(&Q);
    }
    print(&Q);


    return 0;
}


