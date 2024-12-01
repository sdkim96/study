#include <stdio.h>
 
int get_sum(int a, int b)
{
    return a + b;
}
 
int get_difference(int a, int b)
{
    return a - b;
}
 
int main(void)
{
    int a = 3;
    int b = 10;
    int sum = get_sum(a, b);
    printf("sum: %d\n", sum);
    
    int difference = get_difference(a, b);
    printf("difference: %d", difference);
 
    return 0;
}