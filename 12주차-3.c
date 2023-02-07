//버블정렬
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

void bubbleSort(int A[]) {
    printf("Before Sort : ");
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
    printf("<<<<<<<<<<<<<<<<<< Bubble Sorting... >>>>>>>>>>>>>>>>>>>\n");

    for(int i=1; i<N; i++) {
        int flag = FALSE, temp;
        for(int j=1; j<=N-i; j++) {
            if(A[j-1] > A[j]) {
                SWAP(A[j-1], A[j], temp);
                flag = TRUE;
            } 
        }
        if(flag == FALSE) break;
        printPass(A, i);
    }
    
}


int main() {

    int A[N];
    srand(time(NULL));

    for(int i=0; i<N; i++) {
        A[i] = rand()%100;
    }

    bubbleSort(A);

    return 0;
}