//우선순위 큐 - 힙
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef int element;
typedef struct HeapType
{
    element heap[SIZE];
    int heapSize;
}HeapType;

void init(HeapType *H) {
    H->heapSize = 0;
}

void upHeap(HeapType *H) {
    int i = H->heapSize;
    element key = H->heap[i];

    while (i!=1 && H->heap[i/2]<key)
    {
        H->heap[i] = H->heap[i/2];
        i /= 2;
    }
    H->heap[i] = key;
    
}

void insertItem(HeapType *H, element key) {
    H->heapSize++;
    H->heap[H->heapSize] = key;
    upHeap(H);
}

void printHeap(HeapType *H) {
    for(int i=1; i<=H->heapSize; i++) {
        printf("(%d) ", H->heap[i]);
    }
    printf("\n\n");
}


int main() {
    HeapType *H = (HeapType *)malloc(sizeof(HeapType));
    init(H);

    insertItem(H, 9); insertItem(H, 7); insertItem(H, 6);
    insertItem(H, 5); insertItem(H, 4); insertItem(H, 3);
    insertItem(H, 2); insertItem(H, 2); insertItem(H, 1); insertItem(H, 3);

    printHeap(H);

    insertItem(H, 8);  printHeap(H);


    return 0;
}