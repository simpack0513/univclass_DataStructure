//이중 연결 리스트 - 리포트
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

void insertLast(DListType *DL, element e);
element deleteLast(DListType *DL);

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
    if(DL->tail == NULL) {
        DL->tail = node;
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
        if(p==NULL) {
            insertLast(DL, e);
        } 
        else {
            node->prev = p->prev;
            node->next = p;
            node->prev->next = node;
            p->prev = node;
        }
        
    }
    
}

void insertLast(DListType *DL, element e) {
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    DListNode *p = DL->tail;
    node->data = e;

    node->prev = p;
    node->next = NULL;
    if(p!=NULL) {
        p->next = node;
    }
    DL->tail = node;
    if(DL->head==NULL) {
        DL->head = node;
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

element deletePosition(DListType *DL, int pos) {
    DListNode *p = DL->head;
    if(pos==1) return deleteFirst(DL);
    else {
        for(int i=1; i<pos; i++) {
            p=p->next;
        }
        if(p==DL->tail) return deleteLast(DL);
        else {
            element e = p->data;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return e;
        }
    }
}

element deleteLast(DListType *DL) {
    DListNode *p = DL->tail;
    element e = p->data;
    if(DL->head == DL->tail) {
        DL->head = NULL;
        DL->tail = NULL;
        free(p);
        return e;
    }
    else {
        p->prev->next = NULL;
        DL->tail = p->prev;
        free(p);
        return e;
    }

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

void reversePrint(DListType *DL) {
    DListNode *p = DL->tail;
    printf("reversePrint : \n");
    while (p!=NULL)
    {
        printf("[%d] <=> ", p->data);
        p=p->prev;
    }
    printf("\b\b\b\b   \n\n");
    
}



int main() {
    DListType DL;
    init(&DL);

    insertLast(&DL, 10); insertLast(&DL, 20); insertLast(&DL, 30);
    insertFirst(&DL, 40); insertFirst(&DL, 50); insertFirst(&DL, 60);
    print(&DL);

    printf("[%d] is deleted\n", deletePosition(&DL, 3));
    print(&DL);

    printf("[%d] is deleted\n", deleteLast(&DL));
    print(&DL);
    reversePrint(&DL);

    return 0;
}