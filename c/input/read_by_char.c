#include <stdio.h>
#define TRUE (1)

int main(void)
{
    int c;

    
    /* -> EOF 플래그를 stdin에서 주면 while이 멈춤 */

    /* 각각의 시스템마다의 EOF
        - 윈도우: ctrl z
        - 유닉스(맥): ctrl d
    
    */

    while (TRUE)
    {
        c = getchar();
        
        if (c == EOF) 
        {
            break;
        }
        else
        {
            putchar(c);    
        }
        
    }

    return 0;
}