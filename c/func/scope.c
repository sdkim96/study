#include <stdio.h>

int g_x = 10;

void increase_number(int x);

int main(void) 
{
    /*
    result:
        g_x: 10
        y: 5
        g_x: 11
    */
    int y=5;
    printf("g_x: %d\n", g_x);

    increase_number(y);
    printf("y: %d\n", y);
    printf("g_x: %d\n", g_x);

}

void increase_number(int x)
{
    x++;
    g_x++;
}
