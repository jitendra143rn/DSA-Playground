#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    // create a variable of structure
    struct Node *root = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap

    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}
int main()
{
    printf("Creating Tree Using Linked List....\n");
    struct Node *root = createNode(1); // root

    struct Node *leftchild = createNode(2);  // left root
    struct Node *rightchild = createNode(3); // right root

    // Linking --- nodes

    root->left = leftchild;   // (2)
    root->right = rightchild; // (3)
    return 0;
}
