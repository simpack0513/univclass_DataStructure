// 색인 순차 탐색
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 15
#define N2 5

typedef struct 
{
    int key;
    int index;
}IndexTable;


void print1(int A[])
{
    for(int i = 0; i < N1; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void print2(IndexTable IT[])
{
    printf("\nIndex Table\n");
    for(int i = 0; i < N1/N2; i++)
        printf("[%2d : %2d]\n", IT[i].key, IT[i].index);
    printf("\n");
}

void makeIndexTable(int A[], IndexTable IT[]) {
    for(int i=0, j=0; i<N1/N2; i++, j+=5) {
        IT[i].key = A[j];
        IT[i].index = j;
    }
    print2(IT);
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

int indexSearch(int A[], IndexTable IT[], int key) {
    int i, low, high;
    if(key < A[0] || key > A[N1-1]) return -1;
    else 
    for(i=0; i<N1/N2; i++) {
        if(IT[i].key <= key && key < IT[i+1].key) break;
    }
    if(i==N1/N2-1) {
        low = IT[i].index;
        high = N1;
    }
    else {
        low = IT[i].index;
        high = IT[i+1].index;
    }
    printf("low = %d, high = %d\n", low, high);
    return seqSearch(A, key, low, high);
}

int main()
{
    int A[N1];
    IndexTable IT[N1/N2];

    srand(time(NULL));
    for(int i = 0; i < N1; i++)
        A[i] = rand() % 100;

    insertionSort(A);
	print1(A); makeIndexTable(A, IT);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);

    idx = indexSearch(A, IT, key);
    if(idx==-1) printf("No Key.\n");
    else printf("%d is in A[%d]\n", key, idx);

    return 0;
}
