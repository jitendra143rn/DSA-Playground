#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int data)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack is full.\n");
    else
    {
        t->data = data;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1; // return null char if stack empty

    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Eval(char *postfix)
{

    int i =0, x1 =0, x2 =0, r = 0;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - 48);
        }
        else
        {

            x2 = pop();
            x1 = pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }

    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";

    printf("result is : %d\n", Eval(postfix));

    return 0;
}
