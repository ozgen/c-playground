//
// Created by moezgen on 12/20/24.
//

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *createNode(int data) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the binary tree
struct TreeNode *insert(struct TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int search(struct TreeNode *root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (key == root->data) {
        return 1;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void freeTree(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    int key = 40;
    if (search(root, key)) {
        printf("Key %d found in the binary tree.\n", key);
    } else {
        printf("Key %d not found in the binary tree.\n", key);
    }

    freeTree(root);

    return 0;
}
