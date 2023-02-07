#include <stdio.h>

int count=0;

int rFib(int n) {
    count++;
    if (n==0) return 0;
    else if (n==1) return 1;
    else return rFib(n-1) + rFib(n-2);
}

int main(void) {
    int n;
    scanf("%d", &n);

    rFib(n);
    printf("%d", count);



}