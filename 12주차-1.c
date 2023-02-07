//선택정렬
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

void selectionSort(int A[]) {
    printf("Before Sort : ");
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
    printf("<<<<<<<<<<<<<<<<<< Selection Sorting... >>>>>>>>>>>>>>>>>>>\n");

    for(int i=0; i<N-1; i++) {
        int min = i;
        for(int j=i+1; j<N; j++) {
            if(A[min] > A[j]) min = j;
        }
        if(i != min) swap(A, i, min);
        printPass(A, i+1);
    }
    
}


int main() {

    int A[N];
    srand(time(NULL));

    for(int i=0; i<N; i++) {
        A[i] = rand()%100;
    }

    selectionSort(A);





    return 0;
}