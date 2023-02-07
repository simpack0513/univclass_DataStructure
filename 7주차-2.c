// 이진 트리 - 순회(재귀로)
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* makeNode(element e, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = left;
    node->right = right;
    return node;
}

void preOrder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("[%d] ", root->data);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->data);
    }
}


int main() {
    TreeNode *N7 = makeNode(25, NULL, NULL);
    TreeNode *N6 = makeNode(16, NULL, NULL);
    TreeNode *N4 = makeNode(1, NULL, NULL);
    TreeNode *N3 = makeNode(20, N6, N7);
    TreeNode *N2 = makeNode(4, N4, NULL);
    TreeNode *N1 = makeNode(15, N2, N3);

    printf("Pre : "); preOrder(N1); printf("\n\n");
    printf("In : "); inOrder(N1); printf("\n\n");
    printf("Post : "); postOrder(N1); printf("\n\n");

    return 0;
}