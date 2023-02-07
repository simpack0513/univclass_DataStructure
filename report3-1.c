// 원형 연결리스트 - 리포트 3-1 (deleteLast 추가)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

typedef struct 
{
    ListNode *tail; // head : tail->link
}ListType;

void init(ListType *L) {
    L->tail = NULL;
}

void insertFirst(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;

    if(L->tail==NULL) {
        L->tail = node;
        node->link = L->tail;
    }
    else {
        node->link = L->tail->link;
        L->tail->link = node;
    }
}

void insertLast(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;

    if(L->tail==NULL) {
        L->tail = node;
        node->link = node;
    }
    else {
        node->link = L->tail->link;
        L->tail->link = node;
        L->tail = node;
    }
}

element deleteLast(ListType *L) { //구현 하는 것 과제
    ListNode *p = L->tail;
    ListNode *q = p->link;
    element e = p->data;
    while (q->link!=p)
    {
        q = q->link;
    }
    q->link = p->link;
    L->tail = q;
    free(p);
    return e;
    
}

element deleteFirst(ListType *L) {
    ListNode *p = L->tail;
    ListNode *q = p->link;
    element e = q->data;

    if(p==q) {
        L->tail = NULL;
        free(p);
        return e;
    }
    else {
        p->link = q->link;
        free(q);
        return e;
    }
    

}

void print(ListType *L) {
    ListNode *p = L->tail->link;
    while (L->tail != p)
    {
        printf("[%d] => ", p->data);
        p = p->link;
    }
    printf("[%d] => ...", p->data);
    printf("\n\n"); 
    
}

int main() {
    ListType L;
    init(&L);

    insertFirst(&L, 10); insertFirst(&L, 20); insertFirst(&L, 30);
    insertLast(&L, 40); insertLast(&L, 50); insertLast(&L, 60);
    print(&L);

    deleteLast(&L); 
    print(&L);

    return 0;

}

