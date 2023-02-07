//이중 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode
{
    element data;
    struct DListNode *prev;
    struct DListNode *next;

}DListNode;

typedef struct 
{
    DListNode *head;
    DListNode *tail;

}DListType;

void init(DListType *DL) {
    DL->head = NULL;
    DL->tail = NULL;
}

void insertFirst(DListType *DL, element e) {
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    DListNode *p = DL->head;

    node->data = e;
    node->prev = NULL;
    node->next = DL->head;
    DL->head = node;

    if(p!=NULL) {
        p->prev = node;
    }
}

void insert(DListType *DL, int pos, element e) {
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    DListNode *p = DL->head;
    node->data = e;

    if(pos==1) insertFirst(DL, e);
    else {
        for(int i=1; i<pos; i++) {
            p = p->next;
        }
        node->prev = p->prev;
        node->next = p;
        node->prev->next = node;
        p->prev = node;
    }
    
}

element deleteFirst(DListType *DL) {
    DListNode *p = DL->head;
    element e = p->data;
    
    if(p->next == NULL) {
        DL->head = NULL;
    }
    else {
        p->next->prev = NULL;
        DL->head = p->next;
    }
    free(p);
    return e;
}

void print(DListType *DL) {
    DListNode *p = DL->head;
    while (p!=NULL) 
    {
        printf("[%d] <=> ", p->data);
        p = p->next;
    }
    printf("\b\b\b\b   \n\n");
    
}



int main() {
    DListType DL;
    init(&DL);

    insertFirst(&DL, 10);  insertFirst(&DL, 20); insertFirst(&DL, 30); 
    print(&DL);

    insert(&DL, 1, 40);  insert(&DL, 2, 50);  insert(&DL, 4, 60);
    print(&DL);

    printf("[%d] is deleted\n", deleteFirst(&DL));
    print(&DL);

    return 0;
}