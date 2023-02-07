// 인접 그래프 - 연결 리스트 방식
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define FALSE 0
#define TRUE 1

// 인접 그래프 부분

typedef struct IncidentEdge{
    char aName;
    struct IncidentEdge *next;
}IncidentEdge;

typedef struct Vertex{
    char vName;
    int isVisit;
    IncidentEdge *iHead;
    struct Vertex *next;
}Vertex;

typedef struct {
    Vertex *vHead;
}GraphType;

void init(GraphType *G) {
    G->vHead = NULL;
}

void makeVertex(GraphType *G, char vName) {
    Vertex *V = (Vertex*)malloc(sizeof(Vertex));
    V->vName = vName;
    V->iHead = NULL;
    V->next = NULL;
    V->isVisit = FALSE;

    Vertex *p = G->vHead;

    if(G->vHead == NULL) {
        G->vHead = V;
    }
    else {
       while (p->next != NULL)
       {
            p = p->next;
       }
       p->next = V;
    }
}

void makeIncidentEdge(Vertex *V, char aName) {
    IncidentEdge *p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->next = NULL;

    IncidentEdge *q =V->iHead;

    if(V->iHead == NULL)
        V->iHead = p;
    else {
        while (q->next != NULL)
        {
           q = q->next;
        }
        q->next = p;
    }
}

Vertex* findVertex(GraphType *G, char vName) {
    Vertex *p = G->vHead;
    while (p->vName != vName)
    {
        p = p->next;
    }
    return p;
}

void insertEdge(GraphType *G, char v1, char v2){
    Vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2);

    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);
}

void rDfs(GraphType *G, char vName) {
    Vertex *v = findVertex(G, vName);
    IncidentEdge *p;

    if(v->isVisit == FALSE) {
        v->isVisit = TRUE;
        printf("[%c] ", v->vName);
    }
    for(p=v->iHead; p!= NULL; p=p->next) {
        v = findVertex(G, p->aName);
        if(v->isVisit == FALSE) {
            rDfs(G, v->vName);
        }
    }
}

void print(GraphType *G) {
    Vertex *p = G->vHead;
    IncidentEdge *q;

    for(; p != NULL; p=p->next) {
        printf("[%c] : ", p->vName);
        for(q=p->iHead; q!=NULL; q=q->next) {
            printf("[%c] ", q->aName);
        }
        printf("\n");
    }
    printf("\n");
}

// 스택부분
typedef struct
{
    Vertex *data[SIZE];
    int top;
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

int isEmptyStack(StackType* S)
{
    return S->top == -1;
}

int isFullStack(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, Vertex *v)
{
    if(isFullStack(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = v;
    }
}

Vertex* pop(StackType* S)
{
    if(isEmptyStack(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    
    Vertex *c = S->data[S->top];
    S->top--;
    return c;
}

//큐 부분
typedef struct
{
    int front;
    int rear;
    Vertex *data[SIZE];
}QueueType;

void init_queue(QueueType *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(QueueType *q) {
    return (q->front==q->rear);
}

int isFullQueue(QueueType *q) {
    return q->rear == SIZE-1;
}

void enqueue(QueueType *q, Vertex *v) {
    if(isFullQueue(q)) printf("FULL\n");
    else {
        q->rear++;
        q->data[q->rear] = v;
    }
}

Vertex* dequeue(QueueType *q) {
    if(isEmptyQueue(q)) return 0;
    else {
        q->front++;
        return q->data[q->front];
    }
}

void lDfs(GraphType *G, char *vName) {
}

void bfs(GraphType *G, char vName) {
    Vertex *v = findVertex(G, vName);
    IncidentEdge *p;

    QueueType Q;
    init_queue(&Q);

    v->isVisit = TRUE;
    printf("(%c) ", v->vName);
    enqueue(&Q, v);

    while (!isEmptyQueue(&Q))
    {
        v = dequeue(&Q);
        for(p=v->iHead; p!=NULL; p=p->next) {
            v=findVertex(G, p->aName);
            if(!v->isVisit) {
                v->isVisit = TRUE;
                printf("(%c) ", v->vName);
                enqueue(&Q, v);
            }
            
        }
    }
    
}

int main()
{
    //그래프 초기화
    GraphType G;
    init(&G);
    
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c'); makeVertex(&G, 'd'); makeVertex(&G, 'e');
        
    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c'); insertEdge(&G, 'a', 'e'); insertEdge(&G, 'b', 'c'); 
    insertEdge(&G, 'c', 'd'); insertEdge(&G, 'c', 'e'); insertEdge(&G, 'd', 'e');

    print(&G);

    bfs(&G, 'd');

    

    return 0;
}