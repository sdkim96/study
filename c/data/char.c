#include <limits.h>
#include <stdio.h>

int main(void) 
{
    char char_size=CHAR_BIT;
    printf("char size: %d\n", char_size);

    /* 오버플로우 내보기
    
    129 가 왜 -127 로 출력되는가?
    10000001(2) 는 singed이기 때문에 맨 앞의 1이 부호비트로 인식되서 - 가 되고
    2의 보수 방식으로 처리하기때문에
    최상위 비트를 제외한 나머지부분이
    1111110(2) 이 되고
    이는 127이니
    -127 이 출력된다.
    
     */
    char char2 = 129;
    printf("char2: %d\n", char2); /* 출력 -127 */
    

    unsigned char char3 = 259;
    printf("char3: %d\n", char3); /* 출력 3 */

    return 0;
}