#include <stdio.h>
#include <string.h>

#define LENGTH 1024

int main(void)
{
    char string[LENGTH];
    FILE* stream;

    // 파일 열기 (쓰기 모드)
    stream = fopen("test2.txt", "w+"); // "w+" 모드는 읽기와 쓰기 모두 가능
    if (stream == NULL) {
        perror("파일 열기 오류");
        return 1;
    }

    while (1) {
        // 입력받기
        printf("문자열 입력 (종료하려면 'exit' 입력): ");
        if (fgets(string, LENGTH, stdin) == NULL) {
            break; // 입력 오류 또는 EOF
        }

        // 입력 종료 조건
        if (strncmp(string, "exit", 4) == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 파일에 쓰기
        fputs(string, stream);
        fflush(stream); // 즉시 파일에 반영

        // 파일 읽기
        rewind(stream); // 파일 포인터를 맨 앞으로 이동
        printf("\n[파일 내용]\n");
        while (fgets(string, LENGTH, stream)) {
            printf("%s", string);
        }
        printf("\n");

        // 다시 파일 끝으로 이동하여 다음 입력을 준비
        fseek(stream, 0, SEEK_END);
    }

    fclose(stream); // 파일 닫기
    return 0;
}