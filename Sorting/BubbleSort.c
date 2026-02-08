#include<stdio.h>

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;

}
int BubbleSort(int A[], int size )
{
    int flag = 0 ; // Checking for List/Array is already sorted  or not.

    int i, j; 

    for(i = 0; i < size -1; i++)
    {
        flag = 0; 
        for(j = 0; j < size -1 -i; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1; 

            }
        }
        if(flag == 0)
        {
            //printf("\nList is already sorted.\n");
            break;
        }
    }
    return 0; 
}

void DisplayArr(int A[], int size)
{
    for(int i = 0; i < size ; i++)
    {
        printf("%d ", A[i]);
    }
}
int main()
{
    int A[] = {7, 9, 10, 5, 4, 6};
    int size = sizeof(A) / sizeof(int);
    printf("Array Size:%d\n", size);

    printf("Before Bubble Sort Array: ");

    DisplayArr(A, size);


    BubbleSort(A, size);
    printf("After Bubble Sort Array: ");

    DisplayArr(A, size);


    return 0; 
}
