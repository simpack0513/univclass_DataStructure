// 노드 헤더로 만든 이중 연결 리스트

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode
{
    element data;
    struct DListNode *prev;
    struct DListNode *next;
}DListNode;

void init(DListNode *H, DListNode *T) {
    H->next = T;
    H->prev = NULL;
    T->next = NULL;
    T->prev = H;
}

void insert(DListNode *H, int pos, element e) {
    DListNode *p = H;
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    node->data = e;
    for(int i=0; i<pos-1; i++) {
        p = p->next;
    }
    node->next = p->next;
    node->prev = p;
    p->next->prev = node;
    p->next = node;

}

void print(DListNode *H, DListNode *T) {
    DListNode *p = H->next;
    while (p!=T)
    {
       printf("[%d] <=> ", p->data);
       p = p->next;
    }
    printf("\b\b\b\b    \n\n");
    
    
}

element delete(DListNode *H, int pos) {
    element e;
    DListNode *p = H;
    for(int i=0; i<pos; i++) {
        p = p->next;
    }
    e = p->data;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return e;
}


int main() {
    DListNode *H = (DListNode *)malloc(sizeof(DListNode));
    DListNode *T = (DListNode *)malloc(sizeof(DListNode));

    init(H, T);

    insert(H, 1, 10); insert(H, 2, 30); insert(H, 1, 20); insert(H, 4, 40);
    print(H, T);

    printf("[%d] is deleted. \n", delete(H, 2)); printf("[%d] is deleted. \n", delete(H, 3));
    print(H, T);



    return 0;
}
