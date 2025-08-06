#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *second=NULL, *third=NULL;

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

// Create second Linked List 
void create1(int A[], int size)
{
    int i = 0;
    struct Node *temp, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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
void Display(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {

        printf("%d ", head->data);
        head = head->next;
    }
}
void Merge (struct Node *p, struct Node *q)
{
    struct Node *last = NULL;

    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else 
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if(p->data < q->data )
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else 
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
    last->next= p;
    else 
    {
        last->next = q;

    }

}
int main()
{
    int A[] = {10,10,20,20,20,30,40,50};
    create(A, 8);
    int B[] = {1,2,3,4,5};
    create1(B, 5);
    Display(head);
    Display(second);

    Merge(head, second);

    Display(third);
  
}


// Ouput 
/*
First Linked List data. 
Linked List: 10 10 20 20 20 30 40 50 
Second Linked List data. 
Linked List: 1 2 3 4 5 
Third Linked List data aftre merge 
Linked List: 1 2 3 4 5 10 10 20 20 20 30 40 50 
*/
