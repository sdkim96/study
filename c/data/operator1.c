/*
    sizeof 는 함수가 아니라 연산자임.
    컴파일 도중에 판단됨
    참고로 unsigned int인 size_t

    size_t는 typedef임.
    이거 자체는 데이터 형이 아닌데, 이건 다른 데이터 형의 별칭임
    즉, 컴파일러에 따라 다름. unsigned int일 수도 있고 unsigned long일 수도 있음

    size_t의 용도는 어떤 것의 크기임 ,색인이라고 할 수 있음.
*/

#include <stdio.h>


int main(void) 
{
    char ch = 'a';
    int i = 10;
    char char_arr[40];
    int index_of_student;

    size_t size_of_ch = sizeof(ch);
    size_t size_of_i = sizeof(i);
    size_t size_of_char_arr = sizeof(char_arr);

    printf("size of ch: %zu\n", size_of_ch);
    printf("size of i: %zu\n", size_of_i);
    printf("size of char_arr: %zu\n", size_of_char_arr);

    for (size_t j=0; j<size_of_char_arr; j++) {
        char_arr[j] = (char)j;
    }

    for (size_t j=0; j<size_of_char_arr; j++) {
        printf("char_arr[%zu]: %d\n", j, char_arr[j]);
    }
}