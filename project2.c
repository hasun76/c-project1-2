#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int playerX = 1;
int playerY = 1;

#define MAP_WIDTH 114
#define MAP_HEIGHT 30
char map[MAP_HEIGHT][MAP_WIDTH + 1] = {     //맵 범위 설정
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 ",
    "                                                                                                                 "
};

// 맵 그리기
void drawMap() {
    system("cls");  // 화면 초기화
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("★");  // 플레이어 표시
            }
            else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

// 플레이어 이동
void movePlayer(char input) {
    int nextX = playerX;
    int nextY = playerY;

    switch (input) {
    case 'w': nextY--; break; // 위로 이동
    case 's': nextY++; break; // 아래로 이동
    case 'a': nextX--; break; // 왼쪽으로 이동
    case 'd': nextX++; break; // 오른쪽으로 이동
    }

    // 맵의 경계를 벗어나지 않도록
    if (nextX >= 0 && nextX < MAP_WIDTH && nextY >= 0 && nextY < MAP_HEIGHT) {
        map[playerY][playerX] = '*'; // 지나간 자리에 색칠
        playerX = nextX;
        playerY = nextY;
    }
}

// 맵 초기화
void initializeMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = ' '; // 빈칸으로 초기화
        }
        map[y][MAP_WIDTH] = '\0'; // 문자열 끝 표시
    }
}

// 플레이어 이동 (지우기)
void movePlayerToErase(char input) {
    int nextX = playerX;
    int nextY = playerY;

    switch (input) {
    case 'w': nextY--; break; // 위로 이동
    case 's': nextY++; break; // 아래로 이동
    case 'a': nextX--; break; // 왼쪽으로 이동
    case 'd': nextX++; break; // 오른쪽으로 이동
    }

    // 맵의 경계를 벗어나지 않도록 함
    if (nextX >= 0 && nextX < MAP_WIDTH && nextY >= 0 && nextY < MAP_HEIGHT) {
        map[playerY][playerX] = ' '; // 지나간 자리를 빈칸으로 지우기
        playerX = nextX;
        playerY = nextY;
    }
}


// 세로줄 그리기
void vertline_draw() {
    //7배수인 열에 세로줄 출력
    int i, j;
    for (i = 1; i <= 30; i++) { // 1행부터 30행까지 반복
        for (j = 1; j <= 114; j++) { // 1열부터 114열까지 반복
            if (j % 7 == 0) { // 7배수일때
                map[i][j]='|';
            }
            else {
                 
            }
        }
        printf("\n"); // 다음 행으로 이동
    }
}
void horline_draw() {
    // 7배수인 행에 가로선 출력
    for (int i = 0; i < 30; i++) { // 0부터 30까지 반복 (10행)
        for (int j = 1; j <= 114; j++) { // 1열부터 114열까지 반복
            if (i % 7 == 0) { // 7배수일때
                map[i][j] = '*';
            }
            else {
                 
            }
        }
        printf("\n");
    }
}
void dialine_draw() {   //대각줄 출력
    int i, j;
    for (i = 0; i < 30; i++) { // 30행까지 반복
        for (j = 0; j < i; j++) {   //행-1까지 높이기
            
        }
        map[i][j] = '*';    //행이 x라면 열은 x-1인 자리에 출력
    }
}
void qualine_draw() {   //사각형 모형으로 출력
    for (int i = 5; i < 25; i++) {
        for (int j = 10; j < 104; j++) {
            // 외곽선의 조건
            if (i == 5 || i == 25 - 1 || j == 10 || j == 104 - 1) {
                map[i][j] = '*';
            }
            else {
                 
            }
        }
        printf("\n"); // 다음 행으로 이동
    }
}


// 그리기 기능
void draw() {
    char input;
    while (1) {
        drawMap();
        input = _getch(); // 사용자 입력을 받아 움직임 처리
        movePlayer(input);

        if (input == 'q') break; // 'q' 키 입력 시 종료
    }
}

// 지우기 기능
void erase() {
    char input;
    while (1) {
        drawMap();
        input = _getch(); // 사용자 입력을 받아 움직임 처리
        movePlayerToErase(input);

        if (input == 'q') break; // 'q' 키 입력 시 종료
    }
}


// 메뉴
int main() {
    int choice;

    initializeMap();  // 맵 초기화
    

    while (1) {
        printf("\n메뉴를 선택하세요:\n");
        printf("1. 그리기(q누르면 종료)\n");
        printf("2. 지우기(q누르면 종료)\n");
        printf("3. 새 화면\n");
        printf("4. 종료\n");
        printf("5. 세로줄 출력\n");
        printf("6. 수직선 출력\n");
        printf("7. 대각줄 출력\n");
        printf("8. 사각형 출력\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            draw();
            break;
        case 2:
            erase();
            break;
        case 3:
            initializeMap();
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return 0;
        case 5:
            
            vertline_draw();
            break;
        case 6:
           
            horline_draw();
            break;
        case 7:
            
            dialine_draw();
            break;
        case 8:
            
            qualine_draw();
            break;

        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}


