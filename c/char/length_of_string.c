#include <stdio.h>

size_t get_length_of_string(const char* string);
int main(void)
{
    size_t final_len;
    char string[] = "Hello, World!";
    final_len = get_length_of_string(string);

    printf("Length of string: %zu\n", final_len);
}


size_t get_length_of_string(const char* string)
{
    const char* start = string;
    while (*string++ != '\0')
    {
        ;
    }

    return string - start - 1;
}

size_t get_length_of_string2(const char* string2)
{
    int count = 0;
    while (string2[count] != '\0')
    {
        count++;
    }

    return count;
}