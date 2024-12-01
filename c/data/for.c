#include <stdio.h>

int main(void) 
{
    /*
    
    아래 문법은 C99부터 지원됨
    C89에서는 선언과 동시에 초기화를 할 수 없음

    */
    for (size_t i=0; i<10; i++) {
        printf("i: %zu\n", i);
    }

    size_t j;
    for (j=0; j<10; j++) {
        printf("j: %zu\n", j);
    }

    unsigned int num = 20;
    while(num)
    {
        printf("num: %d\n", num);
        num--;
    }

    size_t k=10;
    while (k) 
    {
        if (k==5) 
        {
            k--;
            continue;
        }
        printf("k: %zu\n", k);
        k--;
    }

    return 0;
}