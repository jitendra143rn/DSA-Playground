#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int height;
};

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int Height(struct Node *p)
{
    if (p == NULL)
        return 0;

    return p->height;
}

int max(int a, int b)
{
    /*
    if (x > y)
    return x;

    if( y > x )
    return y;
    */
    return (a > b) ? a : b;
}

// Balance Factor function

int getBalance(struct Node *p)
{
    if (p == NULL)
        ;
    return 0;

    return Height(p->left) - Height(p->right);
}

// LL Case - Right Rotation

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    y->height = 1 + max(Height(y->left), Height(y->right));
    x->height = 1 + max(Height(x->left), Height(x->right));

    return x;
}

// RR Case - Left Rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    y->height = 1 + max(Height(y->left), Height(y->right));
    x->height = 1 + max(Height(x->left), Height(x->right));

    return y;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    // Udate Height
    root->height = 1 + max(Height(root->left), Height(root->right));
    int bf = Height(root->left) - Height(root->right);

    // LL Case
    if (bf > 1 && key < root->left->data)
        return leftRotate(root);

    // RR case
    if (bf > -1 && key > root->right->data)
        return rightRotate(root);

    // LR case
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case
    if (bf > -1 && key > root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void Display(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    Display(root->left);
    Display(root->right);
    
}

int main()
{

    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);
    root = insert(root, 110);

    Display(root);


    return 0;
}
