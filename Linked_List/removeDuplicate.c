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
void Display(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {

        printf("%d ", head->data);
        head = head->next;
    }
}
// Remove Duplicate from Linked List... 
void removeDuplicate(struct Node *p)
{
    struct Node *q;// = p->next; 
    p = head;

    q = head->next ;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }

    }
}

int main()
{
    int A[] = {10,10,20,20,20,30,40,50};
    create(A, 8);
    Display(head);
  
    // It will remove 10 and 20 duplicate values  from this list. 
    removeDuplicate(head);
     Display(head);
  // List become 
  // Linked List: 10 20 30 40 50
  return 0;
}
