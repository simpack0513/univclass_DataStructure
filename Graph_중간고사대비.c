#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define N 10

typedef struct IncidentEdge
{
    char aName;
    struct IncidentEdge *next;
}IncidentEdge;


typedef struct Vertex
{
    int isVisit;
    char vName;
    IncidentEdge *ihead;
    struct Vertex *next;
}Vertex;

typedef struct GraphType
{
    Vertex *vHead;
}GraphType;

void initGraph(GraphType *G) {
    G->vHead = NULL;
}

void makeVertex(GraphType *G, char vName) {
    Vertex *v = (Vertex*) malloc(sizeof(Vertex));
    v->isVisit = FALSE;
    v->ihead = NULL;
    v->vName = vName;
    v->next = NULL;
    
    if(G->vHead == NULL) {
        G->vHead = v;
    }
    else {
        Vertex *p = G->vHead;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = v;
    }
}

void makeIncidentEdge(Vertex *v, char aName) {
    IncidentEdge *edge = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    edge->aName = aName;
    edge->next = NULL;

    IncidentEdge *p = v->ihead;
    if(p==NULL) v->ihead = edge;
    else {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = edge;
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

void insertEdge(GraphType *G, char v1, char v2) {
    Vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2);
    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);

}

typedef struct StackType
{
    int top;
    Vertex *elem[N];
}StackType;

void initStack(StackType *S) {
    S->top = -1;
}

void push(StackType *S, Vertex *v) {
    S->top++;
    S->elem[S->top] = v;
}

Vertex* pop(StackType *S) {
    Vertex *v = S->elem[S->top--];
    return v;
}

void printGraph(GraphType *G) {
    Vertex *Vp;
    IncidentEdge *Ep;
    for(Vp = G->vHead; Vp != NULL; Vp= Vp->next) {
        printf("[%c] : ", Vp->vName);
        for(Ep = Vp->ihead; Ep != NULL; Ep = Ep->next) {
            printf("(%c) ", Ep->aName);
        }
        printf("\n");
    }
    printf("\n\n");
}

void dfs(GraphType *G, char vName) {
    StackType S;
    initStack(&S);
    Vertex *Vp = findVertex(G, vName);
    IncidentEdge *Ep;
    
    push(&S, Vp);
    while (S.top != -1)
    {
        if(Vp->isVisit == FALSE) {
            printf("(%c) => ", Vp->vName);
            Vp->isVisit = TRUE;
        }
        for(Ep = Vp->ihead; Ep != NULL; Ep = Ep->next) {
            Vp = findVertex(G, Ep->aName);
            if(Vp->isVisit == FALSE) {
                push(&S, Vp);
                break;
            }
        }
        if(Ep == NULL) pop(&S);

    }

    
}

int main() {
    GraphType G;
    initGraph(&G);

    makeVertex(&G, 'a'); makeVertex(&G, 'b');
    makeVertex(&G, 'c'); makeVertex(&G, 'd'); makeVertex(&G, 'e');
    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c'); insertEdge(&G, 'a', 'd');
    insertEdge(&G, 'b', 'd'); insertEdge(&G, 'b', 'e'); insertEdge(&G, 'd', 'e');

    printGraph(&G);
    dfs(&G, 'b');
    return 0;
}


