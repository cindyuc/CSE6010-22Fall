#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

struct node* newNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void printInorder(struct node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

struct node* maximum(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* minimum(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minimum(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

struct node* successor(struct node* root, int data) {
    struct node* current = search(root, data);
    if (current == NULL) {
        return NULL;
    }
    if (current->right != NULL) {
        return minimum(current->right);
    }
    return NULL;
}

struct node* predecessor(struct node* root, int data) {
    struct node* current = search(root, data);
    if (current == NULL) {
        return NULL;
    }
    if (current->left != NULL) {
        return maximum(current->left);
    }
    return NULL;
}