#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char data)
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

char pop()
{
    struct Node *t;
    char x = '\0'; // return null char if stack empty

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

int isEmpty()
{
    return top == NULL;
}

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *exp)
{
    int i;
    char popped;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty())
                return 0; // closing without opening

            popped = pop();
            if (!isMatchingPair(popped, exp[i]))
                return 0; // mismatched brackets
        }
    }

    return isEmpty(); // if stack empty → balanced
}

int main()
{
    char *exp1 = "((a+b)*[c-{d/e}])";
    char *exp2 = "([a+b]*(c-d)}";

    printf("Exp1: %s → %s\n", exp1, isBalanced(exp1) ? "Balanced" : "Not Balanced");
    printf("Exp2: %s → %s\n", exp2, isBalanced(exp2) ? "Balanced" : "Not Balanced");

    return 0;
}
