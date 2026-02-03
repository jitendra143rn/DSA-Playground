#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int size;

} MaxHeap;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Steps:
	1.	Insert element at end of array
	2.	Compare with parent
	3.	If larger → swap
	4.	Repeat until heap property satisfied

*/
void Insert(MaxHeap *h, int val)
{
    int i = h->size;
    h->arr[i] = val;
    h->size++;

    while(i !=0 && h->arr[(i-1)/2] < h->arr[i])
    {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i -1)/2;
    }

}
int main(void)
{
    MaxHeap h;
    h.size = 0; 

    Insert(&h, 50);
    Insert(&h, 30);
    Insert(&h, 40);
    Insert(&h, 60);

    for(int i = 0; i < h.size; i++)
    {
        printf("%d ", h.arr[i]);
    }

    return 0; 

}
