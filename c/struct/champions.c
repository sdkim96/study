#include <stdio.h>
#include <string.h>
#define MAX_CHAMPIONS (2)

typedef struct {
    char* lastname;
    char* firstname;
} champion_t;

int main(void)
{
    champion_t champions[MAX_CHAMPIONS];
    FILE* file = fopen("champions.txt", "w");
    if (file == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    champions[0].lastname = "Doe";
    champions[0].firstname = "John";

    champions[1].lastname = "Doe";
    champions[1].firstname = "Jane";

    size_t i;
    for (i = 0; i < MAX_CHAMPIONS; i++)
    {
        printf("%s %s\n", champions[i].firstname, champions[i].lastname);

        // firstname과 lastname을 파일에 쓰고 줄바꿈 추가
        fwrite(champions[i].firstname, sizeof(char), strlen(champions[i].firstname), file);
        fwrite(" ", sizeof(char), 1, file); // 이름과 성 사이에 공백 추가
        fwrite(champions[i].lastname, sizeof(char), strlen(champions[i].lastname), file);
        fwrite("\n", sizeof(char), 1, file); // 줄바꿈 추가
    }

    fclose(file);

    return 0;
}