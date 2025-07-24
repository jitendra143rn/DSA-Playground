#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    *a = *b;
    *b = temp;
}
void Reverse(int *arr, int size)
{
    int *B;
    int i, j;
    B = (int *)malloc(size*sizeof(int));
    for(i = size-1, j= 0; i>=0; i--, j++)
    B[j] = arr[i];
    for(i = 0; i<size; i++)
    {
        arr[i] = B[i];
    }
}

void Reverse2(int *arr, int size)
{
    int i, j;
    for(i =0, j = size-1; i<j; i++, j--)
    {
        swap(&arr[i], &arr[j]);
    }
}
int main()
{
    int arr[] = {2, 5, 6, 8 , 10 };
    printf("Before Reverse array is:");
    for(int i = 0; i<5; i++)
        printf("%d ", arr[i]);
    // Reverse(&arr, 5);
    Reverse2(arr, 5);
    printf("\n");
    printf("Reversed array is: ");
    for(int i=0; i < 5 ; i++ )
    printf("%d ", arr[i]);


    return 0; 

    
}
