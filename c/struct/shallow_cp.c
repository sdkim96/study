#include <stdio.h>

typedef struct {
    char* lastname;
    char* firstname;
} name_t;

int main(void)
{
    char first_n[] = "John";
    char last_n[] = "Doe";

    name_t name;
    name_t clone;

    name.lastname = first_n;
    name.firstname = last_n;

    clone = name;
    name.lastname[0] = 'N';
    
    printf("Name: %s %s\n", name.firstname, name.lastname);
    printf("Clone: %s %s\n", clone.firstname, clone.lastname);
    
    return 0;
}