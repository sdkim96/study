#include <stdio.h>

int main(void)
{
    int nums[6] = {1,2,3,4,5,6};

    int *ptr = NULL;
    ptr = nums;

    /* ptr = nums[0]; */ /* this is incompatible */
    ptr = &nums[0]; /* this is compatible */

    char* endian_checker = (char*)ptr;
    size_t i = 0;

    for (; i<4; ++i) {
        printf("%p\n", (void*)(endian_checker+i));
    }

    printf("%p\n", (void*)&endian_checker[2]);

    printf("%d\n", (int)sizeof(nums[2]));

    printf("%p\n", &nums[2]);
    printf("%p\n", &nums[1] + (int)sizeof(nums[2]));

    printf("%d\n", &nums[2] == &nums[1] + sizeof(nums[2]));

    int arr[4] = {1,2,3,4};
    int* head = &(arr[3]);
    int* tail = arr;

    long sub = head - tail;
    printf("%d\n", sub);

    
    return 0;
}
