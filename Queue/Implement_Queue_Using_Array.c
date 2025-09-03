#include <stdio.h>
#include <stdlib.h>

struct Queue_t
{
    int size;
    int front;
    int rear;
    int *Q;
};

typedef struct Queue_t Queue;

void create(Queue *q, int size)
{
    q->size = size;

    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }

    printf("\n");
}

int main()
{
    Queue q;

    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    Display(q);

    int d = 0;
    d = dequeue(&q);
    printf("%d \n", d);

    Display(q);
    
    return 0;
}
