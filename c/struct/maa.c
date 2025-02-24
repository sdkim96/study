#include <stdio.h>

typedef struct {
    int a;
    int b;
} calculator_t;

int add(calculator_t* calc)
{
    return calc->a + calc->b;
}

int main(void)
{
    calculator_t calc;
    calc.a = 1;
    calc.b = 2;

    int result = add(&calc);
    printf("result: %d\n", result);

}
