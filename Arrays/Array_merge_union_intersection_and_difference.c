#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("Elements are:");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d  ", arr.A[i]);
    }
    printf("\n\n");
}
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length  && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];

        }
        else if( arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        
    }
    for(; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];

    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length =k;
    arr3->size = 20;
    return arr3;
}
struct Array* intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length  && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;

        }
        else if( arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        
    }
    
    arr3->length =k;
    arr3->size = 20;
    return arr3;
}
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length  && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];

        }
        else if( arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else{
            i++;
            j++;
        }
        
    }
    for(; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];
    arr3->length =k;
    arr3->size = 20;
    return arr3;
}
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr1->length  && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];

        }
        else 
        {
            arr3->A[k++] = arr2->A[j++];
        }
        
    }
    for(; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];

    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;
    return arr3;
}
int main()
{
    struct Array arr = {{2, 4, 6, 8, 10}, 20, 5};
    // int n, i;
    // printf("Enter the size of the array:");
    // scanf("%%d", &arr.size);
    // arr.A = (int *)malloc(arr.size*sizeof(int));
    // arr.length = 0;
    // printf("Ente the number:");
    // scanf("%d", &n);
    // printf("Enter all Elements\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr.A[i]);
    // }
    // arr.length = n;

    /* Merging arrays */

    struct Array arr1 = {{2,6,8,9,14},10,5};
    struct Array arr2 = {{1,6,4,9,10},10,5};
    printf("Array 1:\n");
    Display(arr1);
    printf("Array 2:\n");
    Display(arr2);
    struct Array *arr3;
    //arr3 = Merge(&arr1, &arr2);
    //arr3 = Union(&arr1, &arr2);
    //printf("Union Array 3:\n");
    //arr3 = intersection(&arr1, &arr2);
    //printf("Intersection Array 3:\n");
    arr3 = Difference(&arr1, &arr2);
    printf("Difference Array 3:\n");
    
    Display(*arr3);
    return 0;
}
