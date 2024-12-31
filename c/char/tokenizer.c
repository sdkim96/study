#include <stdio.h>

char* strtok(char* str, const char* delims);

int main(void)
{
    char str[] = "hello, my name is, sungdong.";
    const char delims[] = ",.";

    char* token;
    token = strtok(str, delims);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delims);
    }

    return 0;
}

char* strtok(char* str, const char* delims)
{
    static char* last = NULL;
    if (str == NULL)
    {
        str = last;
    }



}