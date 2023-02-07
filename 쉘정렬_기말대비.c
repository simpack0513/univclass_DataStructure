#include <stdlib.h>
#include <stdio.h>

#define N 10

void shellSort(int a[]) {
    int i,j,gap, key;
    for(gap = 5; gap>=1; gap -=2) {
        for(i=gap; i<N; i++) {
            key = a[i];
            j = i - gap;
            while (a[j]>key && j>=0)
            {
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
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
    int a[N] = {5,2,7,10,6,30,1,8,13,18};

    shellSort(a);    
    printArray(a);

    return 0;
}