// 이진 트리 - 이진 탐색(재귀로)
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

TreeNode* minValueNode(TreeNode *root) {
    TreeNode *p = root;
    while (p->left!=NULL)
    {
        p = p->left;
    }
    return p;
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


TreeNode* deleteNode(TreeNode *root, element key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->key < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->key > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        if(root->left == NULL) {
            TreeNode *p = root->right;
            free(root);
            return p;
        }
        else if(root->right == NULL) {
            TreeNode *p = root->left;
            free(root);
            return p;
        }
        else {
            TreeNode *p = minValueNode(root->right);
            root->key = p->key;
            root->right = deleteNode(root->right, p->key);
        }
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


int main() {
    TreeNode *root = NULL;
    root = insertNode(root,35); root = insertNode(root,68);
    root = insertNode(root,99); root = insertNode(root,18);
    root = insertNode(root,7); root = insertNode(root,3);
    root = insertNode(root,12); root = insertNode(root,26);
    root = insertNode(root,22); root = insertNode(root,30);

    preOrder(root); printf("\n\n");
    deleteNode(root, 30); deleteNode(root, 26); deleteNode(root, 18);
    preOrder(root); printf("\n\n");

    return 0;
}