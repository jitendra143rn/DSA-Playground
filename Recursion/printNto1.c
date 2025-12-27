#include <stdio.h>

void printNTo1(int n)
{
    if(n <= 0) return ;
    
    printf("%d ", n);
    
    printNTo1(n-1);
  
}

int main()
{
    printNTo1(5);
    return 0;
}

/*
Time complexity  : O(n)
Space complexity : O(n)

*/
/*
Output: 5 4 3 2 1 
*/
