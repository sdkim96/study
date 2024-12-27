#include <stdio.h>


int get_length_of_string(const char* str);
int get_ascii_number_of_string(const char* str);
int compare_string(const char* str1, const char* str2);

int main(void)
{

    char* str1 = "stt";
    char* str2 = "-string";
    char* str3 = "안녕하세요?";

    int length;
    int sum;

    length = get_length_of_string(str3);
    sum = get_ascii_number_of_string(str2);
    printf("%d\n", length);
    printf("%d\n", sum);

    int is_same;
    is_same = compare_string(str1, str2);
    printf("%d\n", is_same);
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