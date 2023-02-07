//보간 탐색
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 15
#define N2 5

void print1(int A[])
{
    for(int i = 0; i < N1; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void insertionSort(int A[]) {
    for(int i=1; i<=N1-1; i++) {
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

int seqSearch(int A[], int key, int start, int end) {
    for(int i=start; i<end; i++) {
        if(key == A[i]) return i;
    }
    return -1;
}

int interpolationSearch(int A[], int key) {
    int low = 0, high = N1-1;

    while (A[low] <= key && key <= A[high])
    {
        int pos = ((float)(key-A[low])/(float)(A[high]-A[low]) * (high-low) + low);
        printf("%d\n", pos);
        if(key == A[pos]) return pos;
        else if(key < A[pos]) high = pos-1;
        else low = pos+1;
    }
    return -1;
    
}

int main()
{
    int A[N1];

    srand(time(NULL));
    for(int i = 0; i < N1; i++)
        A[i] = rand() % 100;

    insertionSort(A);
	print1(A);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);

    idx = interpolationSearch(A, key);
    if(idx==-1) printf("No Key.\n");
    else printf("%d is in A[%d]\n", key, idx);

    return 0;
}
