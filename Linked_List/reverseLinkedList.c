#include <stdio.h>
#include <stdlib.h>

// Define structure for a Node
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;  // Global head pointer for the linked list

// Function to create Linked List using an array
void create(int A[], int size)
{
    int i = 0;
    struct Node *temp, *last;

    // Create the first node and assign it to head
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    // Create remaining nodes and link them
    for (i = 1; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
        temp->data = A[i];      // Assign data
        temp->next = NULL;      // Set next to NULL
        last->next = temp;      // Link previous node to current
        last = temp;            // Move last pointer forward
    }
}

// Function to reverse the Linked List using 3 sliding pointers
void reverseLinkedList(struct Node *p)
{
    struct Node *r, *q;

    // Initialize helper pointers
    r = NULL;  // Points to previous node
    q = NULL;  // Points to current node

    // Traverse through the list and reverse the links
    while (p != NULL)
    {
        r = q;        // Move r to q
        q = p;        // Move q to current node
        p = p->next;  // Move p to next node
        q->next = r;  // Reverse the link
    }

    // After loop, q points to the new head
    head = q;
}

// Function to display the linked list
void Display(struct Node *p)
{
    printf("Linked List: ");
    while (p != NULL)
    {
        printf("%d ", p->data);  // Print data
        p = p->next;             // Move to next node
    }
}

int main()
{
    // Initialize array
    int A[] = {10, 20, 30, 40, 50, 60, 70};

    // Create linked list from array
    create(A, 7);

    // Display original linked list
    Display(head);
    // Output: Linked List: 10 20 30 40 50 60 70

    // Reverse the linked list
    reverseLinkedList(head);

    // Display reversed linked list
    Display(head);
    // Output: Linked List: 70 60 50 40 30 20 10

    return 0;
}
