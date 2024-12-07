#include <stdio.h>

void export_min_max(
    const int arr[],
    const size_t size,
    int* max,
    int* min
) 
{   
    size_t i;
    *max = arr[0];
    *min = arr[0];

    for (i=0; i<size; ++i) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

int main(void)
{   
    const size_t size = 5;
    const int arr[size] = {1, 2, 3, 4, 5};
    int max, min;

    export_min_max(arr, size, &max, &min);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
