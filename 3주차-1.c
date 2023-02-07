#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct 
{
    int degree;
    int codf[N];
}Poly;

void print(Poly p) {
    int i, j;
    printf("\n");
    for(i=0, j=p.degree; i<p.degree; i++, j--) {
        printf("%2dx^%d ", p.codf[i], j);
    }
    printf("%2d\n", p.codf[p.degree]);
}


Poly add(Poly a, Poly b) {
    Poly C;
    int Apos=0, Bpos=0, Cpos=0;
    int degA=a.degree;
    int degB=b.degree;
    int degC, gap;
    if(a.degree>b.degree) {
        degC=a.degree; 
        gap=a.degree-b.degree;}
    else {
        degC=b.degree;
        gap=b.degree-a.degree; }

    C.degree=degC;


    for(int i=0; i<gap; i++) {
        if(a.degree>b.degree) {
        C.codf[Cpos] = a.codf[Apos];
       Cpos++; Apos++;
        }
        else {
            C.codf[Cpos] = b.codf[Apos];
            Cpos++; Bpos++;
        }
    }

    for(int i=0; i <= degC-gap; i++) {
        C.codf[Cpos] = a.codf[Apos] + b.codf[Bpos];
        Cpos++; Bpos++; Apos++;
    } 

    return C;
}


int main() {
    Poly a,b,c;
    scanf("%d %d", &a.degree, &b.degree);
    fflush(stdin);

    for(int i=0; i<=a.degree; i++) {
        scanf("%d ", &a.codf[i]);
    }

    for(int i=0; i<=b.degree; i++) {
        scanf("%d ", &b.codf[i]);
    }
    
    fflush(stdin);
    print(a);
    print(b);
    c = add(a,b);
    print(c);


    return 0;
}
