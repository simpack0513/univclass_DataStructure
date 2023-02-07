#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct
{
    int front;
    int rear;
    char data[SIZE];
}DequeType;

void init_queue(DequeType *d) {
    d->front = 0;
    d->rear = 0;
}

int isEmpty(DequeType *d) {
    return (d->front==d->rear);
}

int isFull(DequeType *d) {
    return (d->rear + 1)%SIZE == d->front;
}

void addRear(DequeType *d, char e) {  //enqueue
    if(isFull(d)) printf("FULL\n");
    else {
        d->rear = (d->rear+1)%SIZE;
        d->data[d->rear] = e;
    }
}

void addFront(DequeType *d, char e) {  //enqueue
    if(isFull(d)) printf("FULL\n");
    else {
        d->data[d->front] = e;
        d->front = (d->front-1 + SIZE)%SIZE;
    }
}

void print(DequeType *d) {
    printf("Front Pos : %d Rear Pos : %d\n", d->front, d->rear);
    int i=d->front;
    while (i!=d->rear)
    {
        i = (i+1)%SIZE;
        printf("[%c]", d->data[i]);
    }
    
    printf("\n\n");
}

char deleteFront(DequeType *d) {  //dequeue
    if(isEmpty(d)) return 0;
    else {
        d->front = (d->front+1)%SIZE;
        return d->data[d->front];
    }
}

char deleteRear(DequeType *d) {  //dequeue
    if(isEmpty(d)) return 0;
    else {
        char e = d->data[d->rear];
        d->rear = (d->rear-1+SIZE)%SIZE;
        return e;
    }
}

char getFront(DequeType *d) { //peek
    if(isEmpty(d)) return 0;
    else {
        return d->data[(d->front+1)%SIZE];
    }
}

char getRear(DequeType *d) { //peek
    if(isEmpty(d)) return 0;
    else {
        return d->data[(d->rear)%SIZE];
    }
}

int dequeSize(DequeType *d) {
    int count = 0;
    count = d->rear - d->front;
    if(count < 0) count +=SIZE;
    return count;
}



int main() {
    DequeType D;
    init_queue(&D);

    char str[100];
    scanf("%s", str);

    for(int i=0; i<strlen(str); i++) {
        addRear(&D, str[i]);
    }


    

    return 0;
}