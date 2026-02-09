#include<stdio.h>


void InsertionSort(int A[], int size)
{

    for(int i = 1; i < size -1; i++)
    {
        int j = i - 1;
        int x = A[i] ; // This will insert at correct position. 

        while(j >= 0 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x ; 
    }
}

void DisplayArr(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}
int main()
{   

    printf("Insertion Sort ---> \n\n");
    int A[] = {7,8,9,5,3,2,1};
    int size = sizeof(A) / sizeof(A[0]) ;

    printf("Array Size : %d \n", size);
    printf("\nBefore Insertio Sort Array: ");
    DisplayArr(A, size);

    InsertionSort(A, size);

    printf("\nAfter Insertion Sort Array: ");
    DisplayArr(A, size);

    return 0; 

}
