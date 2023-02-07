//6장 배열로 List 만들기

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

typedef int element;

typedef struct
{
    element elem[SIZE];
    int size;
}ListType;

void init_queue(ListType *l) {
    l->size = 0;
}

int isEmpty(ListType *l) {
    return (l->size == 0);
}

int isFull(ListType *l) {
    return l->size == SIZE;
}

void insertLast(ListType *l, element e) {
    if(isFull(l)) printf("FULL\n");
    else {
        l->elem[l->size] = e;
        l->size++;
    }
}

void insert(ListType *l, int pos, element e) {
    if(isFull(l)) printf("FULL\n");
    else if(pos < 0 || pos >= l->size) printf("Invaild Posistion.\n");
    else {
        for(int i=l->size-1; i>=pos; i--) {
            l->elem[i+1] = l->elem[i];
        }
        l->elem[pos] = e;
        l->size++;
    }

}

void print(ListType *l) {
    for(int i=0; i<l->size; i++) {
        printf("[%d]", l->elem[i]);
    }
    printf("\n\n");
}

int main() {
    ListType L;
    init_queue(&L);

    insertLast(&L, 10); insertLast(&L, 20); insertLast(&L, 30);
    print(&L);

    insert(&L, 1, 40); insert(&L, 0, 50); insert(&L, 3, 60);
    print(&L);

    return 0;
}


