#include <stdlib.h>
#include <stdio.h>

#define N 5

void bubbleSort(int a[]) {
    int i,j;
    for(i=N-1; i>1; i--) {
        for(j=0; j<i; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }

}

void printArray(int A[]) {
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

int main() {
    int a[N] = {5,2,7,10,6};

    bubbleSort(a);
    printArray(a);

    return 0;
}