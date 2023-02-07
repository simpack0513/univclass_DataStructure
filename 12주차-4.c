//쉘 정렬
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 10
#define FALSE 0
#define TRUE 1

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void swap(int A[], int i, int min) {
    int temp = A[min];
    A[min] = A[i];
    A[i] = temp;
}

void printPass(int A[], int i) {
    printf(" %d Pass >> ", i);
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

void shellSort(int A[]) {
    printf("Before Sort : ");
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
    printf("<<<<<<<<<<<<<<<<<< Shell Sorting... >>>>>>>>>>>>>>>>>>>\n");

    for(int gap=5; gap>=1; gap-=2) {
        for(int i = gap; i<N; i++) {
            int key = A[i];
            int j = i - gap;
            while (j>=0 && A[j] > key)
            {
                A[j+gap] = A[j];
                j -= gap;
            }
            A[j+gap] = key;            
        }
        printPass(A, gap);
    }
    
}


int main() {

    int A[N];
    srand(time(NULL));

    for(int i=0; i<N; i++) {
        A[i] = rand()%100;
    }

    shellSort(A);

    return 0;
}