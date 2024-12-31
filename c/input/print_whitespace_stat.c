#include <stdio.h>
#include <ctype.h>
#define TRUE (1)

void print_whitespace_stat(void);

int main(void)
{
    print_whitespace_stat();
    return 0;
}

void print_whitespace_stat(void)
{
    int c;
    size_t num_whitespaces = 0u;

    while (TRUE)
    {
        c = getchar();

        if (c == EOF)
        {
            break;
        }
        
        if (isspace(c)) {
            ++num_whitespaces;
        }
        
        printf("current whitespaces: %d\n", num_whitespaces);
    }
}