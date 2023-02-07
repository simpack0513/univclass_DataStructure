#include <stdlib.h>
#include <stdio.h>

#define N 8

int partion(int a[], int left, int right) {
    int pivot = a[left];
    int low = left+1;
    int high = right;
    while (right<left)
    {
        while (a[low] < pivot)
            low++;
        while (a[high] > pivot)
            high--;
        if(low<high) {
            int temp;
            temp = a[high];
            a[high] = a[low];
            a[low] = temp;
            low++;
            high--;
        }
    }
    int temp = a[high];
    a[high] = pivot;
    a[left] = temp;
    return high;
}

void quickSort(int a[], int left, int right) {
    if(right>left) {
        int pivotIndex = partion(a, left, right);
        quickSort(a, left, pivotIndex-1);
        quickSort(a, pivotIndex+1, right);
    }
}


void printArray(int A[]) {
    for(int i=0; i<N; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n");
}


int main() {
    int array[N] = {7,2,5,20,1,3,70,9};
    int result[N];

    quickSort(array, 0, N-1);
    printArray(array);
    

}