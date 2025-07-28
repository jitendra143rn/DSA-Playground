#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Create Linked List Using Array
void create(int A[], int size)
{
    int i = 0;
    struct Node *temp, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    // Using loop
    for (i = 1; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

// Insert a Node at Give postion
void insertLinkedListAtPos(struct Node **first, int position, int data)
{
    struct Node *newNode, *p, *q;
    int k = 1;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode)
    {
        printf("Memory Error!\n");
        return;
    }
    newNode->data = data;
    p = *first;
    if (position == 1)
    {
        newNode->next = p;
        *first = newNode;
    }
    else
    {
        while ((k < position) && (p != NULL))
        {
            k++;
            q = p;
            p = p->next;
        }

        q->next = newNode;
        newNode->next = p;
    }
}

void Display(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {

        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int A[] = {4, 7, 9, 40};
    create(A, 4);

    // Display Linked List Before Insertion Operation..
    Display(head);
    // Linked List: 4 7 9 40

    insertLinkedListAtPos(&head, 3, 18);

    Display(head);
    // Linked List: 4 7 9 18 40

    insertLinkedListAtPos(&head, 1, 50);

    Display(head);
    // Linked List: 50 4 7 18 9 40

    return 0;
}
