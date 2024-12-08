#include <stdio.h>

int main(void)
{
    /* 이 2개의 경우에선 데이터가 스택 메모리 섹션에 저장됨. 즉 데이터 값이 변경되도 괜찮음*/
    char str[] = "hello";
    char str2[] = {'h', 'e', 'l', 'l', 'o', '\0'};


    /* 하지만 이 경우엔 데이터 섹션에 저장됨. 수정할 경우에는 undefined result 임 -> Read-Only */
    char* str3 = "hello";
    size_t i;
    
    for (i=0; i<sizeof(str); ++i) printf("%c", str[i]);
    i=0;



    return 0;
}