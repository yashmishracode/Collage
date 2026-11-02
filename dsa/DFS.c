
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create the tree using user input
struct Node* createTree(void) {
    int value;

    printf("Enter node value (-1 for no node): ");
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    if (value == -1) {
        return NULL;
    }

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;

    printf("Enter left child of %d:\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = createTree();

    return newNode;
}

// DFS: Preorder (Root, Left, Right)
void DFS(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    DFS(root->left);
    DFS(root->right);
}

// Free allocated memory
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    clock_t start = clock();
    printf("Create your binary tree:\n");

    struct Node* root = createTree();

    

    printf("\nDFS Traversal: ");
    DFS(root);
    printf("\n");

    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("CPU time: %.8f seconds\n", time_taken);

    freeTree(root);

    return 0;
}
