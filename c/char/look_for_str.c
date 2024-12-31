#include <stdio.h>

int main(void)
{
    const char* str = "I want to go to school. Studying coding is so fun!";
    const char* lookup = "school";

    while (*str != '\0')
    {   
        size_t j;
        int same = 0;
        for (j=0; lookup[j] != '\0'; ++j)
        {
            int same_char = str[j] - lookup[j];
            printf("%d\n", same_char);
            same += same_char;
        }
        
        if (same == 0)
        {
            printf(" find same!!!!!!!!!! \n");
        }

        printf("------------------------------- \n");
        ++str;
    }

    return 0;
}