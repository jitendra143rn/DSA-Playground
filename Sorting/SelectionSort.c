#include <stdio.h>
#include <string.h>

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

void DisplayArr(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}
void SelectionSort(int A[], int size)
{

    int i, j, k;

    for (i = 0; i < size -1; i++)
    {
        for (j = k = i; j < size ; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[] = {5,4,2,3,1};

    int size = sizeof(A) / sizeof(A[0]);

    printf("\nBefore Selection Sort Array: ");
    DisplayArr(A, size);

    printf("\nAfter Selection Sort Array: ");

    SelectionSort(A, size);
    DisplayArr(A, size);

    return 0;
}
