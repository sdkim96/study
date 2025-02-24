#include <stdio.h>
#define LENGTH (1024)

int main(void)
{
    /* open */
    FILE* stream;
    char list[LENGTH];

    stream = fopen("test.txt", "r");
    if (stream == NULL) {
        fprintf(stderr, "fopen failed\n");
        return 1;
    }

    for (int i = 0; i < LENGTH; i++) {
        list[i] = fgetc(stream);
        if (list[i] == EOF) {
            printf("%d\n", fgetc(stream));
            break;
        }
    }


    return 0;
}