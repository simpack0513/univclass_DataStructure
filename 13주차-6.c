#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

typedef struct AVLNode
{  
    int key;
    struct AVLNode *left, *right;
}AVLNode;

AVLNode* createNode(int key) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

int getHeight(AVLNode *node) {
    int height = 0; 
    if(node != NULL) height = 1+ max(getHeight(node->left), getHeight(node->right));
    else return height;
}

int getBalance(AVLNode *node) {
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateRight(AVLNode *p) {
    AVLNode *c = p->left;
    p->left = c->right;
    c->right = p;
    return c;
    
}

AVLNode* rotateLeft(AVLNode *p) {
    AVLNode *c = p->right;
    p->right = c->left;
    c->left = p;
    return c;
}

AVLNode* insert(AVLNode *node, int key) {
    if(node == NULL) return createNode(key);
    if(node->key < key) {
        node->right = insert(node->right, key);
    }
    else if(node->key > key) {
       node->left = insert(node->left, key);
    }
    else return node;

    int balance = getBalance(node);
    //LL
    if(balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    //LR
    if(balance > 1 && key > node->left->key) {
        node->left->left = node->left->right;
        return rotateRight(node);
    }
    //RR
    if(balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    //RL
    if(balance < -1 && key < node->right->key) {
        node->right->right = node->right->left;
        return rotateLeft(node);
    }


    return node;
}

void preOrder(AVLNode *node) {
    if(node != NULL){
        printf("[%d] ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main() {
    AVLNode *root = NULL;

    root = insert(root, 25);
    root = insert(root, 20);
    root = insert(root, 15);
    preOrder(root); printf("\n");

    root = insert(root, 30);
    root = insert(root, 35);
    preOrder(root); printf("\n");

    root = insert(root, 22);
    preOrder(root); printf("\n");


    return 0;
}
