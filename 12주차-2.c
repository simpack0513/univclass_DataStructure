//삽입정렬
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 10

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

void insertionSort(int A[]) {
    printf("Before Sort : ");
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
    printf("<<<<<<<<<<<<<<<<<< Insertion Sorting... >>>>>>>>>>>>>>>>>>>\n");

    for(int i=1; i<N; i++) {
        int key = A[i];
        int j = i-1;
        while (j >=0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printPass(A, i);
        
    }
    
}


int main() {

    int A[N];
    srand(time(NULL));

    for(int i=0; i<N; i++) {
        A[i] = rand()%100;
    }

    insertionSort(A);

    return 0;
}