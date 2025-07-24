#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using pointers
void swap(int *a, int *b)
{
    int temp = *a; // Store the value at address 'a' into temp
    *a = *b;       // Replace value at 'a' with value at 'b'
    *b = temp;     // Replace value at 'b' with temp (original value of 'a')
}

// Function to reverse an array using an auxiliary array (method 1)
void Reverse(int *arr, int size)
{
    int *B; // Pointer for temporary array
    int i, j;

    // Allocate memory dynamically for the auxiliary array
    B = (int *)malloc(size * sizeof(int));

    // Copy elements from 'arr' to 'B' in reverse order
    for(i = size - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr[i];

    // Copy reversed elements back to original array
    for(i = 0; i < size; i++)
        arr[i] = B[i];

    // Free the dynamically allocated memory (best practice)
    free(B);
}

// Function to reverse an array in-place using two-pointer approach (method 2)
void Reverse2(int *arr, int size)
{
    int i, j;
    // Initialize two pointers: i at start, j at end of array
    for(i = 0, j = size - 1; i < j; i++, j--)
    {
        // Swap elements at i and j
        swap(&arr[i], &arr[j]);
    }
}

// Main function to demonstrate reverse logic
int main()
{
    int arr[] = {2, 5, 6, 8, 10}; // Declare and initialize array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    printf("Before Reverse array is: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call one of the reverse functions
    // Reverse(arr, n);   // Method 1: Using extra array
    Reverse2(arr, n);     // Method 2: In-place swap

    printf("\nReversed array is: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
