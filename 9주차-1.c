//이진 트리 - 마무리(다양한 함수 만들기)
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
    element key;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* makeNode(element key) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertNode(TreeNode *root, element key) {
    if(root==NULL) {
        return makeNode(key);
    }
    if(key<root->key) {
        root->left = insertNode(root->left, key);
    }
    else if(key>root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

void preOrder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int getNodeCount(TreeNode *root) {
    int count = 0;
    if(root!=NULL) {
        count = 1 + getNodeCount(root->left) + getNodeCount(root->right);
    }
    return count;
}

int isExternal(TreeNode *root) {
    if(root->left == NULL && root->right == NULL)
        return 1;
    else return 0;
}

int getLeafCount(TreeNode *root) {
    int count = 0;
    if(root!=NULL) {
        if(isExternal(root))
            return 1;
        else count = getLeafCount(root->left) + getLeafCount(root->right);
    }
    return count;
}

int getSingleChildNode(TreeNode *root) {
    int count = 0;
    if(root!=NULL) {
        if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
            return count = 1+ getSingleChildNode(root->left) + getSingleChildNode(root->right);
        else count = getSingleChildNode(root->left) + getSingleChildNode(root->right);
    }
    return count;
}

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int getHeight(TreeNode *root) {
    int height = 0;
    if(root!=NULL) {
        height = 1 + max(getHeight(root->left), getHeight(root->right));
    }
    return height;
}

int getBalance(TreeNode *root) {
    if(root==NULL) return 0;
    else return getHeight(root->left) - getHeight(root->right);
}

void incSort(TreeNode *root, int *A) {
    static int i = 0;
    if(root) {
        incSort(root->left, A);
        A[i++] = root->key;
        incSort(root->right, A);
    }
}



int main() {
    TreeNode *root = NULL;
    root = insertNode(root,35); root = insertNode(root,68);
    root = insertNode(root,99); root = insertNode(root,18);
    root = insertNode(root,7); root = insertNode(root,3);
    root = insertNode(root,12); root = insertNode(root,26);
    root = insertNode(root,22); root = insertNode(root,30);

    preOrder(root); printf("\n\n");
    printf("Node count : %d\n", getNodeCount(root));
    printf("Leaf Node count : %d\n", getLeafCount(root));
    printf("SingleChild Node count : %d\n", getSingleChildNode(root));
    printf("Tree Height : %d\n", getHeight(root));
    printf("Balance Factor : %d\n", getBalance(root));

    int n = getNodeCount(root);
    int *A = (int *)malloc(sizeof(int)*n);
    incSort(root,A);
    for(int i=0; i<n; i++) {
        printf("[%d] ", A[i]);
    }
    printf("\n\n");

    return 0;
}