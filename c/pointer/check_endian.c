#include <stdio.h>

int main(void)
{
    const int NUM = 0x12345678;
    
    const char* endian_checker = (const char*)&NUM;
    unsigned long i =0;

    for (; i<sizeof(int); ++i) {
        printf("%p: %x\n", (void*)(endian_checker+i), *(endian_checker+i)); /* My mac os is little endian */
    }
    

    return 0;
}