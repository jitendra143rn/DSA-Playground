#include<stdio.h>
#include<stdlib.h>
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

// Delete Node at Given Position and return data 
int deleteNodeAtPos(struct Node *p, int pos)
{
    struct Node *q;
    int ret= -1;
    p = head;
    q = NULL;
    if( pos < 1)
    {
        printf("Position is invalid!\n");
        return ret; 
    }
    if(pos == 1)
    {
        ret = p->data;
        p = head;
        head = head->next;
        free(p);
        return ret;
    }
    else {
        for(int i = 0; i < pos -1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            ret = p->data;
            free(p);
        }
        else{
            printf("Desire Postion does not exits.\n");
            return -1;
        }
    }
    return ret;

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
void newLine(){
    printf("\n\n");
}

int main()
{
    int A[] = {4, 7, 10, 9, 40};
    create(A, 5);
    Display(head);
    // Delete Node given by Position
     deleteNodeAtPos(head, 4);
     Display(head);

    return 0; 
    
}

