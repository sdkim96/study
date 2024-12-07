## Pointer

A pointer is a variable that saves `pointer type` value.

A value that is type of `pointer` can be like : `0x16fdfe54c`.

## Type specified before a pointer

포인터 앞에 명시되어있는 타입은, 그 특정 메모리 주소에 있는 값에 대한 해석 방식이다.
```c
int a = 5;
int* p = &a;

printf("%d\n", *p)
```
일때,
포인터 변수 앞에 있는 `int`는 a 변수의 메모리 주소의 비트패턴을 int로 해석하라는 것이다.

예를 들어서, 위 코드블럭의 해석은 다음과 같다.

1. 메모리 주소 (xxxx) 에 5를 저장해라.
2. 메모리 주소 (yyyy) 에 xxxx를 저장해라.
3. 메모리 주소 (yyyy) 에 저장되어있는 xxxx값에 가서 int 형식(4바이트) 만큼 읽어 int로 해석해라

따라서 하드웨어에게 몇 바이트를 읽어올지를 미리 알려줘야 하기 때문에, 포인터 변수를 선언할때 전방에 명시되어있는 타입은 `해석`의 문제다.
 
## parameter with parameter

만약 특정 함수에 파라미터에 특정 포인터 타입을 받는 것으로 명시되어있다면, 이는 실제로 함수를 사용하는 곳에서 &로 값의 참조를 넘겨 주고,
함수의 내부 scope 에서 그 값을 사용하고 싶다면, 역참조 (*) 를 통해 값을 가져온다.
혹은 ->

## Difference between declare of pointer and dereference

`int* a` and `*a` are have big difference.

## Cautions at returns of functions

Do not return stack variables. -> danger of `dangling pointer`.
```c
int* add(const int a, const int b)
{
    int result;
    result = a+b;
    return &result;
}

int main(void)
{   
    int a = 1;
    int b = 2;
    int* pointing_local_var;

    pointing_local_var = add(a, b);
}

```
These below cases are ok.
1. static variables
2. data located at heap memory

## Null Pointer
A pointer points nothing.

- Defining macro
`#define NULL = ((*void)0)`

- Coding standard
1. When a function need parameter that can be `NULL` type pointer, name that parameter explicit.

`int get_score(const char* const student_name_or_null)`

2. When a function returns pointer value that can be `NULL`, name the signiture of function explicit.

`const char* get_name_or_null(const int id)`

3. In function scope, initialize pointer value as `NULL`
   
`int* ptr = NULL`

4. When we have to check pointer value points valid value.

For example, This exception occurs very common in python.

`NoneType value a ...`

This can be done in C like this.
```c
void do_something(const int* ptr)
{
    
    ptr = NULL;

    if (ptr != NULL) {
        *ptr = 30;
        printf("%d\n", *ptr);
    }
}
```