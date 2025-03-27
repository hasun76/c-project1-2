#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 화면을 초기화하는 함수
int command(const char* cmd) {
    if (strcmp(cmd, "cls") == 0) {
        system("cls"); // Windows에서 화면을 지움
        return 1; // 명령어 성공 실행
    }
    return 0; // 종료를 위한 반환값
}

int main() {
    int rows, cols; // 행과 열
    char character; // 사용자로부터 입력받을 문자
    char screen[20][71]; // 화면을 저장할 배열
    char cmd[10];

    // 화면 초기화: 공백으로 설정
    for (int i = 0; i < 20; i++) {
        memset(screen[i], '_', 70); // 모든 위치를 밑줄로 초기화
        screen[i][70] = '\0'; // 문자열 종료
    }

    while (1) {
        // 상단 헤더 출력
        printf("**1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("************************************************************************\n");

        // 화면 출력
        for (int i = 1; i <= 20; i++) {
            printf("%02d", i);
            printf("%s\n", screen[i - 1]);
        }

        // 사용자로부터 행과 열 입력 받기
        printf("행의 수를 입력하세요 (1-20): ");
        scanf_s("%d", &rows);
        printf("열의 수를 입력하세요 (1-70): ");
        scanf_s("%d", &cols);
        printf("출력할 문자를 입력하세요: ");
        scanf_s(" %c", &character); 

        // 입력된 위치에 문자 저장 
        if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
            screen[rows - 1][cols - 1] = character; 
        }
        while (1) {
            // 화면 출력
            printf("\n");
            printf("**1234567890123456789012345678901234567890123456789012345678901234567890\n");
            printf("************************************************************************\n");
            for (int i = 1; i <= 20; i++) {
                printf("%02d", i);
                printf("%s\n", screen[i - 1]);
            }
            // 사용자로부터 행과 열 입력 받기
            printf("행의 수를 입력하세요 (1-20): ");
            scanf_s("%d", &rows);
            printf("열의 수를 입력하세요 (1-70): ");
            scanf_s("%d", &cols);

            printf("출력할 문자를 입력하세요: (-누르면 종료)");
            scanf_s(" %c", &character); // 
            if (character == '-') break; // '-' 키 입력 시 종료
            // 입력된 위치에 문자 저장 
            if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
                screen[rows - 1][cols - 1] = character; // 
            }

            // 화면 출력
            printf("\n");
            printf("**12345678901234567890123456789012345678901234567890123456789012345678901234567890\n");
            printf("**********************************************************************************\n");
            for (int i = 1; i <= 20; i++) {
                printf("%02d", i);
                printf("%s\n", screen[i - 1]);
            }

            // 입력된 위치에 문자 저장 (인덱스 조정)
            if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
                screen[rows - 1][cols - 1] = character; // 0 기반 인덱스 조정

            }
        }



        printf("명령어를 입력하세요 (예: cls): ");
        scanf_s("%9s", cmd, (unsigned)_countof(cmd)); // 명령어 입력

        // 명령어 실행
        if (command(cmd)) {
            for (int i = 0; i < 20; i++) {
                memset(screen[i], '_', 70); // 모든 위치를 밑줄로 초기화
            }
        }
        else {
            printf("프로그램 종료.\n");
            break;
        }
    }
    return 0;
}