#include <stdio.h>
#include <stdlib.h>

typedef int element;

#define SIZE 20

typedef struct HeapType
{
    int size;
    element data[SIZE];
}HeapType;

void init(HeapType *H) {
    H->size = 0;
}

void insert(HeapType *H, element key) {
    if(H->size == 0) {
        H->size++;
        H->data[H->size] = key;
        return;
    }
    else {
        H->size++;
        H->data[H->size] = key;

        int myIndex = H->size;

        while (myIndex > 1)
        {
            if(key > H->data[myIndex/2]) {
                H->data[myIndex] = H->data[myIndex/2];
                myIndex /= 2;
            }
            else break;
        }
        H->data[myIndex] = key;
    }
}

int deleteHeap(HeapType *H) {
    int result = H->data[1];
    int key = H->data[H->size];
    H->data[1] = H->data[H->size];
    H->size--;

    int myIndex = 1;

    if(H->size == 2) {
        if(myIndex*2 == H->size) {
            if(key < H->data[myIndex*2]){
                H->data[myIndex] = H->data[myIndex*2];
                myIndex *= 2;
            }
        }
    }

    while (myIndex*2+1 <= H->size && H->size > 1) 
    {
        if(myIndex*2 == H->size) {
            if(key < H->data[myIndex*2]){
                H->data[myIndex] = H->data[myIndex*2];
                myIndex *= 2;
                break;
            }
        }
        else if(key > H->data[myIndex*2] && key > H->data[myIndex*2+1]) break;
        else if(H->data[myIndex*2] > H->data[myIndex*2+1]) {
            H->data[myIndex] = H->data[myIndex*2];
            myIndex *= 2;
        }
        else {
            H->data[myIndex] = H->data[myIndex*2+1];
            myIndex = myIndex*2+1;
        }
    }
    H->data[myIndex] = key;
    return result;
}

void heapSort(HeapType H) {
    int max = H.size;
    for(int i=0; i<max; i++) {
        printf("(%d) ", deleteHeap(&H));
    }
    printf("\n\n");
}

void printHeap(HeapType *H) {
    for(int i=1; i<=H->size; i++) {
        printf("[%d] ", H->data[i]);
    }
    printf("\n");
}

int main() {
    HeapType H;
    init(&H);

    insert(&H, 9); insert(&H, 7); insert(&H, 6);
    insert(&H, 5); insert(&H, 4); insert(&H, 3);
    insert(&H, 2); insert(&H, 2); insert(&H, 1);
    insert(&H, 3);

    printHeap(&H);

    insert(&H, 8); printHeap(&H);
    deleteHeap(&H); printHeap(&H);

    heapSort(H);

    return 0;

}
