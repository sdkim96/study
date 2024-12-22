#include <stdio.h>
#define SIZE (3)

void print_array(const int* array[], const size_t size, const size_t length[]);



int main(void)
{
    int nums1[3] = {1,2,3};
    int nums2[3] = {4,5,6};
    int nums3[2] = {4,5};

    int* numarrays[SIZE];
    
    numarrays[0] = nums1;
    numarrays[1] = nums2;
    numarrays[2] = nums3;

    size_t length[SIZE] = {3,3,2};

    print_array(numarrays, SIZE, length);

    return 0;
}

void print_array(const int* array[], const size_t size, const size_t length[]) {

    size_t i;
    size_t j;
    for (i=0; i<size; ++i) {
        
        for (j=0; j<length[i]; ++j) {
            printf("%d\n", array[i][j]);
        }
        
    }


};