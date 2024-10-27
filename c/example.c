#include <stdio.h>

int main() {

    char *s = "hello";

    for (int i=0; i<5; i++) {
        printf("%c", s[i]);
    }

    char *arr = (char *)malloc(6 * sizeof(char));
    free(arr);
}
