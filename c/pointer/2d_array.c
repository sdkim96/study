#include <stdio.h>

int main(void)
{

    const size_t row = 2;
    const size_t column = 3;
    size_t i;
    size_t j;

    const int* flatted[row]; 

    int matrix[row][column] = {
        {3,4,6},
        {9,-3,-7}
    };

    for(i=0; i<row; ++i) {
        for (j=0; j<column; ++j) {
            printf("%p ", (void*)matrix[i]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    flatted[0] = matrix[0];
    flatted[1] = matrix[1];

    printf("%p\n", (void*)flatted[0]);
    printf("%p\n", (void*)flatted[1]);
    printf("%td\n", flatted[1] - flatted[0]); /* this is 3 */
    printf("%td\n", &flatted[1] - &flatted[0]); /* this is 1 */

    return 0;


}