// 순차 탐색
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

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand() % 100;

	print(A);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);

    idx = seqSearch(A, key, 0, N);
    if(idx==-1) printf("No Key.\n");
    else printf("%d is in A[%d]\n", key, idx);

    return 0;
}
