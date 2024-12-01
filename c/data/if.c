/*
bool 표현식이 없기 때문에
if () 조건은 비트로 판단해야함.

*/

#include <stdio.h>

enum dessert{
    DESSERT_CAKE,
    DESSERT_PIE,
    DESSERT_COOKIE,
};

int main(void)
{   
    /* 
        1. 작은따옴표와 큰따옴표의 차이

        작은따옴표(’):

            •	C에서 문자 리터럴을 나타냅니다.
            •	단일 문자만 사용 가능합니다.
            •	예: 'a', '1', '\n'

        큰따옴표(”):

            •	C에서 문자열 리터럴을 나타냅니다.
            •	0개 이상의 문자(문자열)를 포함할 수 있습니다.
            •	예: "a", "hello", "" (빈 문자열)
    */
    int type;
    printf("type your favorite dessert: \n");
    scanf("%d", &type);

    if (type < (int)DESSERT_CAKE || type > (int)DESSERT_COOKIE) {
        printf("Invalid input\n");
        return 1;
    }

    enum dessert my_dessert = (enum dessert)type;

    switch (my_dessert) 
    {
        case DESSERT_CAKE:
            printf("I like cake\n");
            break;
        case DESSERT_PIE:
            printf("I like pie\n");
            /* break; */
            /*
            위 경우엔 break가 없어서 아래 case도 실행됨 : fall-through
            */
        case DESSERT_COOKIE:
            printf("I like cookie\n");
            break;
    }

    return 0;
};