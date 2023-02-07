//단순 연결 리스트 - 2개의 리스트로 분할하기
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
    ListNode *head;
}ListType;

void init(ListType *L) {
    L->head = NULL;
}

void insertFirst(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->link = L->head;
    L->head = node;
}

int deleteFirst(ListType *L) {
    ListNode *removed;
    removed = L->head;
    element e = removed->data;

    L->head = removed->link;
    free(removed);
    return e;
}

void insertLast(ListType *L, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->link = NULL;

    ListNode *p = L->head;
    while (p->link!=NULL) 
    {
        p=p->link;
    }
    p->link = node;

    
}

int delete(ListType *L, int pos) {
    if(pos==1) {
        return deleteFirst(L);
    }
    else {
        element e;
        ListNode *prev;
        ListNode *p = L->head;
        for(int i=1; i<pos; i++) {
            prev = p;
            p=p->link;
        }
        prev->link = p->link;
        e = p->data;
        free(p);
        return e;
    }
    
}

void insert(ListType *L, int pos, element e) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;

    if(pos==1) {
        insertFirst(L, e);
    }
    else {
        ListNode *p = L->head;
        for(int i=1; i<pos-1; i++) {
            p=p->link;
        }

        node->link = p->link;
        p->link = node;
    }
}

void print(ListType *L) {
    ListNode *p = L->head;
    for(; p!=NULL; ) {
        printf("[%d] => ", p->data);
        p=p->link;
    }
    printf("NULL");
    printf("\n\n");
}

void partiton(ListType *L, ListType *L1, ListType *L2, int pos) {
    ListNode *p = L->head;
    L1->head = L->head;
    for(int i=1; i<pos; i++) {
            p=p->link;
    }
    L2->head = p->link;
    p->link = NULL;
}

void concat(ListType *L1, ListType *L2) {
    ListNode *p = L1->head;
    ListNode *q = L2->head;
    if(p == NULL) L1->head = q;
    else {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = L2->head;
    }
}



int main() {
    ListType L;
    init(&L);

    insertFirst(&L, 10); insertFirst(&L, 20);
    print(&L);

    insertLast(&L, 30); insertLast(&L, 40);
    print(&L);

    insert(&L, 1, 50); insert(&L, 3, 60);
    print(&L);

    ListType L1, L2;
    init(&L1); init(&L2);
    int pos;

    printf("Enter partition pos : ");
    scanf("%d", &pos);

    partiton(&L, &L1, &L2, pos);
    print(&L1); print(&L2);

    concat(&L1, &L2);
    print(&L1);

    return 0;

}

