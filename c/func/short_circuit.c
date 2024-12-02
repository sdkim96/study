#include <stdio.h>

int i = 0;
int j = 0;
int k = 0;

int a = 0;
int b = 0;
int c = 0;
 
int main(void)
{
    /*
    short circuit evaluation
    result:
    true!
    1 0 0
    */
    if (++i || ++j && ++k)
    {
        printf("true!\n");
    }
 
    printf("%d %d %d\n", i, j, k);

    if (a++ || b && c++)
    {
        printf("true!\n");
    }

    printf("%d %d %d\n", a, b, c);
 
    return 0;
}