#include <stdio.h>

/*
Followed by C89, the order of function parameters is not specified.
Therefore, the order of ++num, ++num is not guaranteed.
This is undefined behavior

**You should not depend on the order of function calls in one line**
*/
float divide(int a, int b);

int main(void)
{
    int num = 3;
    float result;
    /*
    It depends on the compiler, but it is not guaranteed to be executed
    multiple unsequenced modifications to 'num' [-Wunsequenced]gcc
    */
    result = divide(++num, ++num);
    printf("result: %f\n", result);

    return 0;

}

float divide(int a, int b)
{
    return a / b;
}
