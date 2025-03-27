#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int playerX = 1;
int playerY = 1;

#define MAP_WIDTH 114
#define MAP_HEIGHT 30
char map[MAP_HEIGHT][MAP_WIDTH + 1] = {     //�� ���� ����
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

// �� �׸���
void drawMap() {
    system("cls");  // ȭ�� �ʱ�ȭ
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("��");  // �÷��̾� ǥ��
            }
            else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

// �÷��̾� �̵�
void movePlayer(char input) {
    int nextX = playerX;
    int nextY = playerY;

    switch (input) {
    case 'w': nextY--; break; // ���� �̵�
    case 's': nextY++; break; // �Ʒ��� �̵�
    case 'a': nextX--; break; // �������� �̵�
    case 'd': nextX++; break; // ���������� �̵�
    }

    // ���� ��踦 ����� �ʵ���
    if (nextX >= 0 && nextX < MAP_WIDTH && nextY >= 0 && nextY < MAP_HEIGHT) {
        map[playerY][playerX] = '*'; // ������ �ڸ��� ��ĥ
        playerX = nextX;
        playerY = nextY;
    }
}

// �� �ʱ�ȭ
void initializeMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = ' '; // ��ĭ���� �ʱ�ȭ
        }
        map[y][MAP_WIDTH] = '\0'; // ���ڿ� �� ǥ��
    }
}

// �÷��̾� �̵� (�����)
void movePlayerToErase(char input) {
    int nextX = playerX;
    int nextY = playerY;

    switch (input) {
    case 'w': nextY--; break; // ���� �̵�
    case 's': nextY++; break; // �Ʒ��� �̵�
    case 'a': nextX--; break; // �������� �̵�
    case 'd': nextX++; break; // ���������� �̵�
    }

    // ���� ��踦 ����� �ʵ��� ��
    if (nextX >= 0 && nextX < MAP_WIDTH && nextY >= 0 && nextY < MAP_HEIGHT) {
        map[playerY][playerX] = ' '; // ������ �ڸ��� ��ĭ���� �����
        playerX = nextX;
        playerY = nextY;
    }
}


// ������ �׸���
void vertline_draw() {
    //7����� ���� ������ ���
    int i, j;
    for (i = 1; i <= 30; i++) { // 1����� 30����� �ݺ�
        for (j = 1; j <= 114; j++) { // 1������ 114������ �ݺ�
            if (j % 7 == 0) { // 7����϶�
                map[i][j]='|';
            }
            else {
                 
            }
        }
        printf("\n"); // ���� ������ �̵�
    }
}
void horline_draw() {
    // 7����� �࿡ ���μ� ���
    for (int i = 0; i < 30; i++) { // 0���� 30���� �ݺ� (10��)
        for (int j = 1; j <= 114; j++) { // 1������ 114������ �ݺ�
            if (i % 7 == 0) { // 7����϶�
                map[i][j] = '*';
            }
            else {
                 
            }
        }
        printf("\n");
    }
}
void dialine_draw() {   //�밢�� ���
    int i, j;
    for (i = 0; i < 30; i++) { // 30����� �ݺ�
        for (j = 0; j < i; j++) {   //��-1���� ���̱�
            
        }
        map[i][j] = '*';    //���� x��� ���� x-1�� �ڸ��� ���
    }
}
void qualine_draw() {   //�簢�� �������� ���
    for (int i = 5; i < 25; i++) {
        for (int j = 10; j < 104; j++) {
            // �ܰ����� ����
            if (i == 5 || i == 25 - 1 || j == 10 || j == 104 - 1) {
                map[i][j] = '*';
            }
            else {
                 
            }
        }
        printf("\n"); // ���� ������ �̵�
    }
}


// �׸��� ���
void draw() {
    char input;
    while (1) {
        drawMap();
        input = _getch(); // ����� �Է��� �޾� ������ ó��
        movePlayer(input);

        if (input == 'q') break; // 'q' Ű �Է� �� ����
    }
}

// ����� ���
void erase() {
    char input;
    while (1) {
        drawMap();
        input = _getch(); // ����� �Է��� �޾� ������ ó��
        movePlayerToErase(input);

        if (input == 'q') break; // 'q' Ű �Է� �� ����
    }
}


// �޴�
int main() {
    int choice;

    initializeMap();  // �� �ʱ�ȭ
    

    while (1) {
        printf("\n�޴��� �����ϼ���:\n");
        printf("1. �׸���(q������ ����)\n");
        printf("2. �����(q������ ����)\n");
        printf("3. �� ȭ��\n");
        printf("4. ����\n");
        printf("5. ������ ���\n");
        printf("6. ������ ���\n");
        printf("7. �밢�� ���\n");
        printf("8. �簢�� ���\n");
        printf("����: ");
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
            printf("���α׷��� �����մϴ�.\n");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}


