#include <stdio.h>

int compare_string(const char* string1, const char* string2);

int main(void)
{
    compare_string("ㅔㅐㅐ", "gogo");
}

int compare_string(const char* string1, const char* string2)
{
    // "gogo"
    // "gogogo"
    while (*string1 != '\0' || *string2 != '\0')
    {
        int same;
        same = *string2 - *string1;
        printf("same: %d\n", same);
        if (same != 0)
        {
            printf("Not the same\n");
            return 0;
        }
        string1++;
        string2++;
    }
}

