//단순 연결 리스트 - 다항식 표현하기
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode
{
    int coef, expon;
    struct ListNode *link;
}ListNode;

typedef struct 
{
    ListNode *head, *tail;
}ListType;

void init(ListType *L) {
    L->head = NULL;
    L->tail = NULL;
}

void insertLast(ListType *L, int coef, int expon) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->coef = coef;
    node->expon = expon;
    node->link = NULL;

    if(L->tail == NULL) L->head = L->tail = node;
    else {
        L->tail->link = node;
        L->tail = node;
    }

    
}

void polyadd(ListType *L, ListType *L1, ListType *L2) {
    ListNode *p = L1->head;
    ListNode *q = L2->head;
    int sum;

    while (p != NULL && q != NULL)
    {
        if(p->expon==q->expon) {
            sum = q->coef + p->coef;
            if(sum) {
                insertLast(L, sum, p->expon);
            }
            p = p->link;
            q = q->link;
        }
        else if(p->expon > q->expon) {
            insertLast(L, p->coef, p->expon);
            p = p->link;
        }
        else {
            insertLast(L, q->coef, q->expon);
            q = q->link;
        }
    }
    for(; p!=NULL; p=p->link){
        insertLast(L, p->coef, p->expon);
    }
    for(; q!=NULL; q=q->link){
        insertLast(L, q->coef, q->expon);
    }
    
}

void print(ListType *L) {
    ListNode *p = L->head;
    printf("Polynomial : ");
    for(; p!=NULL; ) {
        printf("%dx^%d + ", p->coef, p->expon);
        p=p->link;
    }
    printf("\b\b    \n");
}


int main() {
    ListType poly, poly1, poly2;
    init(&poly); init(&poly1); init(&poly2);

    insertLast(&poly1, 3, 12); insertLast(&poly1, 2, 8); insertLast(&poly1, 1, 0);
    insertLast(&poly2, 8, 12); insertLast(&poly2, -3, 10); insertLast(&poly2, -2, 8); insertLast(&poly2, 10, 6);

    print(&poly1); print(&poly2);

    polyadd(&poly, &poly1, &poly2);
    print(&poly);

    return 0;

}

