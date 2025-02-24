#include <stdio.h>
#include <string.h>
#define LENGTH (1024)


void write_file(char* string, FILE* stream);

int main(void)
{
    FILE* stream;
    char string[LENGTH];
    stream = fopen("test2.txt", "w");

    while (fgets(string, LENGTH, stdin) != NULL)
    {
        write_file(string, stream);
    }

    fclose(stream);    

    return 0;
}

void write_file(char* string, FILE* stream)
{
    fwrite(string, 1, strlen(string), stream);  
}