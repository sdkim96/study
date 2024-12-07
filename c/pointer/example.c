#include <stdio.h>

int main(void)
{

    int num1 = 15;
    int num2 = 30;
    int num3 = 45;

    int* p1 = &num1;
    int* p2 = &num2;
    int* p3 = &num3;

    p1 = p2; /* p1 = &n2 , p2 = &n2, p3= &n3 */
    p2 = p3; /* p1 = &n2, p2 = &n3, p3=&n3 */

    *p3 *= 2; /*30, 90, 90*/
    *p1 += *p3; /*120, 90, 90*/
    *p2 *= 2; /*90*/

    printf("%d %d %d\n", num1, num2, num3);

    return 0;

}