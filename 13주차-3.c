//이진 탐색
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void print(int A[])
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int seqSearch(int A[], int key, int start, int end) {
    for(int i=start; i<end; i++) {
        if(key == A[i]) return i;
    }
    return -1;
}

void insertionSort(int A[]) {
    for(int i=1; i<=N-1; i++) {
        int key = A[i];
        int j= i-1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int iBinarySearch(int A[], int key){
    int low = 0, high = N-1, middle;
    while (low <= high)
    {
        middle = (high+low)/2;
        if(A[middle]==key) return middle;
        else if(A[middle] < key) {
            low = middle+1;
        }
        else {
            high = middle-1;
        }
    }
    return -1;
}

int rBinarySearch(int A[], int key, int low, int high){
    int middle;
    if (low <= high)
    {
        middle = (high+low)/2;
        if(A[middle]==key) return middle;
        else if(A[middle] < key) {
            return rBinarySearch(A, key, middle+1, high);
        }
        else {
            return rBinarySearch(A, key, low, high-1);
        }
    }
    else return -1;
}

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand() % 100;

    insertionSort(A);
	print(A);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);

   // idx = iBinarySearch(A, key);
    idx = rBinarySearch(A, key, 0, N-1);
    if(idx==-1) printf("No Key.\n");
    else printf("%d is in A[%d]\n", key, idx);

    return 0;
}
