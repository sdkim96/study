#include <stdio.h>

void print_address(int* p);

int main(void)
{
    int x = 10;
    print_address(&x);
    return 0;
}

void print_address(int* p)
{
    printf("%p\n", (void*)p);
    printf("%d\n", *p); /* dereference, indirection */

    *p = 15;

    printf("%d\n", *p);
}
