#include<stdio.h>
#include<stdlib.h>
typedef  struct ListNode
{
    int data;
    struct ListNode *next;
}ListNode;

void DisplayLinkedList(ListNode *head)
{
    printf("Linked List: ");
    while(head !=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//
