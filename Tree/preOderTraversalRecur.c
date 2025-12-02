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
    // create a varialbe of structure
    struct Node *root = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in heap

    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}


// Pre Oder Tree traversal ---- Using Recursive function 

void  preOderTraversal(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOderTraversal(root->left);
        preOderTraversal(root->right);
    }
}


int main()
{
    printf("Creating Tree Using Linked List....\n");

    // Create a root Node - also create a left child and right child

    /*

                         (1) -> root
                    //        \\
                   //           \\
                  (2)            (3)
                //   \\         //  \\
               //      \\      //    \\
              (7)      (14)   (5)    (10)



    */

    struct Node *root = createNode(1); // root

    struct Node *leftchild = createNode(2);  // left root
    struct Node *rightchild = createNode(3); // right root

    struct Node *rightrootchild1 = createNode(5);
    struct Node *rightrootchild2 = createNode(10);

    struct Node *leftrootchild1 = createNode(7);
    struct Node *leftrootchild2 = createNode(14);

    // Linking --- nodes

    root->left = leftchild;   // (2)
    root->right = rightchild; // (3)

    leftchild->left = leftrootchild1;  // (7)
    leftchild->right = leftrootchild2; // (14)

    rightchild->left = rightrootchild1;  // (5)
    rightchild->right = rightrootchild2; // (10)

    // Calling preOderTraversal  func

    preOderTraversal(root);

    

    return 0;
}
