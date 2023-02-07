#include <stdlib.h>
#include <stdio.h>

#define N 5

void insertSort(int A[]) {
    int key;
    int i,j;
    for(i=1; i<N; i++) {
        key = A[i];
        for(j=i-1; j>=0; j--) {
            if(A[j] > key) {
                A[j+1] = A[j];
            }
            else break;
        }
        A[j+1] = key;
    }
}

void printArray(int A[]) {
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
}


int main() {
    int array[N] = {7,2,5,20,1};

    insertSort(array);
    printArray(array);
    

}