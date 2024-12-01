#include <stdio.h>

/*
 
    연산자 우선순위
    
 
 
 
 
*/
int get_sum(int a, int b)
{   
    printf("get_sum function called\n");
    return a + b;
}
 
int get_difference(int a, int b)
{
    printf("get_difference function called\n");
    return a - b;
}

int get_product(int a, int b)
{
    printf("get_product function called\n");
    return a * b;
}
 
int main(void)
{
    int a = 3;
    int b = 10;

    int result;

    /*
        아래 함수는 함수의 호출 순서는 앞부터 순서대로 호출됨 (연산자 우선순위와 무관함)
    */
    result = get_difference(a, b) + get_sum(a, b) * get_product(a, b);

    printf("result: %d\n", result);
 
    return 0;
}