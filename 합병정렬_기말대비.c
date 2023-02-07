#include <stdlib.h>
#include <stdio.h>

#define N 8

void merge(int a[], int s[], int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    int count = left;
    while (i<=mid && j<=right)
    {
       if(a[i] < a[j]) s[count++] = a[i++];
       else s[count++] = a[j++];
    }
    if(i>mid) {
        while (j<=right)
        {
            s[count++] = a[j++];
        } 
    }
    else {
        while (i<=mid)
        {
            s[count++] = a[i++];
        }
    }
    for(int i=left; i<=right; i++ ) {
        a[i] = s[i];
    }
    
}

void mergeSort(int a[], int s[], int left, int right) {
    int mid = (left+right)/2;
    if(left < right) {
        mergeSort(a,s,left,mid);
        mergeSort(a,s,mid+1,right);
        merge(a,s,left,mid,right);
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


    mergeSort(array, result, 0, N-1);
    printArray(result);
    

}