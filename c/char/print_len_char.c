#include <stdio.h>
#include <string.h>

int get_length_of_string(const char* str);
int get_ascii_number_of_string(const char* str);
int compare_string(const char* str1, const char* str2);
int string_case_insensitive_compare(const char* str1, const char* str2);
char to_lower(const char str);
void copy_string(const char* from, char* to);
void concat_string(const char* src, char* dest);

int main(void)
{
    const char* str_world = "world";
    char str_hello[12] = "hello";

    concat_string(str_world, str_hello);
    
    // char a = '$';
    // char b = to_lower(a);
    // printf("%c\n", b);

    // char* str1 = "String";
    // char* str2 = "string";
    // int compare;
    
    // char* from = "hello";
    // char to[6];

    // copy_string(from, to);
    // size_t i;
    
    
    // for (i=0; to[i] != '\0'; ++i)
    // {
    //     printf("%c\n", to[i]);
    // }

    // compare = string_case_insensitive_compare(str1, str2);
    
    // char* str3 = "안녕하세요?";

    // int length;
    // int sum;

    // length = get_length_of_string(str3);
    // sum = get_ascii_number_of_string(str2);
    // printf("%d\n", length);
    // printf("%d\n", sum);

    // int is_same;
    // is_same = compare_string(str1, str2);
    // printf("%d\n", is_same);
    return 0;
}

int get_length_of_string(const char* str)
{   
    int length = 0;
    while(*str != '\0')
    {
        str++;
        length++; 
    }

    return length;
}

int get_ascii_number_of_string(const char* str)
{

    int sum = 0;
    while(*str != '\0')
    {
        int character_number = (int)*str;
        sum += character_number;

        str++; 
    }

    return sum;
}

int compare_string(const char* str1, const char* str2)
{   
    while (*str1 != '\0' && *str1 == *str2)
    {     
        printf("%d\n", *str1 - *str2);
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char to_lower(const char str) {
    char a_char = 'A';
    char a_lower_char = 'a';
    char z_char = 'Z';

    int diff = (int)a_lower_char - (int)a_char;

    if (str >= a_char && str <= z_char) {
        return (char)(str + diff);
    }

    return str;
}

int string_case_insensitive_compare(const char* str1, const char* str2)
{
    while (*str1 != '\0' && to_lower(*str1) == to_lower(*str2))
    {
        ++str1;
        ++str2;
    }

    return to_lower(*str1) - to_lower(*str2);
}

void copy_string(const char* from, char* to)
{
    while(*from != '\0')
    {
        *to = *from;
        ++from;
        ++to;
    }

    if (*to != '\0')
    {
        *to = '\0';
    }
}

void concat_string(const char* src, char* dest)
{   
    while (*dest != '\0')
    {
        printf("%c\n", *dest);
        ++dest;
    }

    while (*src != '\0')
    {
        *dest = *src;
        printf("%c\n", *dest);
        ++src;
    }

}