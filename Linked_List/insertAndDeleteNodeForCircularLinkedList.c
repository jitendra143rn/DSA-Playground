#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int Length(struct Node *p)
{
    int len = 0;

    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int Insert(struct Node *p, int pos, int data)
{
    struct Node *t;
    int i;
    if (pos < 0 || pos > (Length(p)))
    {
        printf("Position is not valid.\n");
        return -1;
    }
    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->next = head;
            while (p->next != head)
                p = p->next;

            p->next = t;
            head = t;
        }
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->data = data;
        t->next = p->next;
        p->next = t;
    }

    return 0;
}
int Delete(struct Node *p, int pos)
{
    struct Node *q;
    int x;
    int i;

    if (pos < 0 || pos > Length(p))
        return -1;

    if (pos == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
            p = p->next;
        q = p->next;
        x = q->data;
        p->next = q->next;
        free(q);
    }
    return x;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    printf("Length of list : %d \n", Length(head));

    // Insert Operation
    Insert(head, 1, 50);
    Display(head);

    // Delete operation
    Delete(head, 4);
    Display(head);

    return 0;
}
