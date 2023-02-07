// 인접 그래프 - 연결 리스트 방식
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define FALSE 0
#define TRUE 1

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



int main()
{
    //그래프 초기화
    GraphType G;
    init(&G);
    
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c'); makeVertex(&G, 'd'); makeVertex(&G, 'e');
        
    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c'); insertEdge(&G, 'a', 'e'); insertEdge(&G, 'b', 'c'); 
    insertEdge(&G, 'c', 'd'); insertEdge(&G, 'c', 'e'); insertEdge(&G, 'd', 'e');

    print(&G);

    rDfs(&G, 'd');
    
    

    return 0;
}
