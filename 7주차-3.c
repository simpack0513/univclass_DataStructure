// 이진 트리 - 순회 (스택으로)
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

#define SIZE 10

typedef struct
{
    TreeNode *data[SIZE];
    int top;
}StackType;

void init(StackType* S)
{
    S->top = -1;
}


int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, TreeNode *e)
{
    if(isFull(S))
        printf("Overflow!!\n");
    else
    {
        S->data[++S->top] = e;
    }
}

TreeNode* pop(StackType *S) {
    TreeNode *e = NULL;
    if(S->top >= 0){
        e = S->data[S->top--];
    }

    return e;
}

void iterInOrder(TreeNode *root) {
    StackType S;\
    init(&S);

    while (1)
    {
        for(; root != NULL; root = root->left) {
            push(&S, root);
        }
        root = pop(&S);
        if(root==NULL) break;

        printf("[%d] ", root->data);
        root = root->right;
    }
    
}

TreeNode* makeNode(element e, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = left;
    node->right = right;
    return node;
}


int main() {
    TreeNode *N7 = makeNode(25, NULL, NULL);
    TreeNode *N6 = makeNode(16, NULL, NULL);
    TreeNode *N4 = makeNode(1, NULL, NULL);
    TreeNode *N3 = makeNode(20, N6, N7);
    TreeNode *N2 = makeNode(4, N4, NULL);
    TreeNode *N1 = makeNode(15, N2, N3);

    iterInOrder(N1); printf("\n\n");

    return 0;
}