// 기수 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define D 3

void printPass(int A[], int i)
{
    printf(" %d Pass >> ", i);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

typedef struct
{
    int data[N];
    int front, rear;
}QueueType;

void init(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
	return Q->front == Q->rear;
}

int isFull(QueueType* Q)
{
	return ((Q->rear + 1) % N == Q->front);
}

void enqueue(QueueType* Q, int item)
{
	if (isFull(Q))
		printf("Full\n");
	else
	{
	    Q->rear = (Q->rear + 1) % N;
	    Q->data[Q->rear] = item;
	}
}

int dequeue(QueueType* Q)
{
	if (isEmpty(Q))
	{
		printf("Empty\n");
		return -1;
	}
	
	Q->front = (Q->front + 1) % N;
	return Q->data[Q->front];
}

void radixSort(int A[]) {
    int i, b, d, factor = 1;
    QueueType Q[N];
    for(b=0; b<N; b++) {
        init(&Q[b]);
    }
    for(d=0; d<D; d++) {
        for(i=0; i<N; i++) {
            enqueue(&Q[(A[i]/factor)%10], A[i]);
        }
        for(b=i=0; b<N; b++) {
            while (!isEmpty(&Q[b]))
            {
                A[i++] = dequeue(&Q[b]);
            }
        }
        factor *= 10;
        printPass(A, d+1);
    }
}

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand() % 1000;
    
    for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
	
	radixSort(A);

    return 0;
}
