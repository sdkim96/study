#include <stdio.h>

void print_address()
{
    const int x = 10;
    printf("%p\n", (void*)&x); /* address operator */
}


int main(void)
{
    const size_t n = 5;
    size_t i;
    char string[n] = "hello";

    for (i=n-1; 0<=i; --i) {
        printf("%c\n", string[i]);
        printf("%p\n", (void*)&string[i]);

        if (i ==0) break; /* avoid underflow when size_t */
    }

    return 0;
}