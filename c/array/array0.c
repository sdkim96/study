#include <stdio.h>

void print_array(int arr[], size_t size)
{
    size_t i;
    /*

    This below `sizeof` is not the size of the array, but the size of the pointer.
    8 (pointer variable is 8 bytes in 64-bit system) 

    sizeof on array function parameter will return size of 'int *' instead of 'int[]' [-Wsizeof-array-argument]gcc
    format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]

    */
    printf("%d\n", sizeof(arr));
    for (i=0; i<size; i++)
    {
        printf("arr[%zu]: %d\n", i, arr[i]);
    }
}

int main(void)
{   
    const size_t i=4;
    size_t j;
    int arr[i] = {1,2,3,4};

    print_array(arr, 4);

    /* 
    The best practice to initalize int type array to 0 is to use below code.
    */
   int num_arr[5]={0,};

   for (j=0; j<4; j++) {
        printf("num_arr[%zu]: %d\n", j, num_arr[j]);
   }

    return 0;   
}