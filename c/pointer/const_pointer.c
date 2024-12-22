#include <stdio.h>
#define VECTOR_LENGTH (3)

int add(const int* a, const int* b);
void add_vec(const float* vec1, const float* vec2, float* result);

int main(void)
{
    const int x = 3;
    const int y = 5;

    add(&x, &y);

    return 0;
}

void add_vec(const float* vec1, const float* vec2, float* result)
{
    size_t i;
    for (i=0; i<VECTOR_LENGTH; ++i ) {
        result[i] = vec1[i] + vec2[i];
    }
}

int add(const int* a, const int* b)
{
    printf("%p\n", (void*)a); // a의 주소 출력
    printf("%p\n", (void*)b); // b의 주소 출력

    printf("%d\n", *a); // a가 가리키는 값 출력
    printf("%d\n", *b); // b가 가리키는 값 출력

    printf("Trying to change const pointer...\n");

    // *a = 5; /* ERROR: const 포인터로 값 변경 불가 */
    // b = a; /* ERROR: const 포인터로 주소 변경 불가 */

    const float arr1[VECTOR_LENGTH] = {0.5f, 0.2f, 0.1f};
    const float arr2[VECTOR_LENGTH] = {0.1f, 0.4f, -0.8f};
    float arr3[VECTOR_LENGTH];

    add_vec(arr1, arr2, arr3);
    
    size_t size;
    for (size=0; size<VECTOR_LENGTH; ++size) {

        printf("%f\n", arr3[size]);
    }



    return 0; 
}