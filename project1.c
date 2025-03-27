#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ȭ���� �ʱ�ȭ�ϴ� �Լ�
int command(const char* cmd) {
    if (strcmp(cmd, "cls") == 0) {
        system("cls"); // Windows���� ȭ���� ����
        return 1; // ��ɾ� ���� ����
    }
    return 0; // ���Ḧ ���� ��ȯ��
}

int main() {
    int rows, cols; // ��� ��
    char character; // ����ڷκ��� �Է¹��� ����
    char screen[20][71]; // ȭ���� ������ �迭
    char cmd[10];

    // ȭ�� �ʱ�ȭ: �������� ����
    for (int i = 0; i < 20; i++) {
        memset(screen[i], '_', 70); // ��� ��ġ�� ���ٷ� �ʱ�ȭ
        screen[i][70] = '\0'; // ���ڿ� ����
    }

    while (1) {
        // ��� ��� ���
        printf("**1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("************************************************************************\n");

        // ȭ�� ���
        for (int i = 1; i <= 20; i++) {
            printf("%02d", i);
            printf("%s\n", screen[i - 1]);
        }

        // ����ڷκ��� ��� �� �Է� �ޱ�
        printf("���� ���� �Է��ϼ��� (1-20): ");
        scanf_s("%d", &rows);
        printf("���� ���� �Է��ϼ��� (1-70): ");
        scanf_s("%d", &cols);
        printf("����� ���ڸ� �Է��ϼ���: ");
        scanf_s(" %c", &character); 

        // �Էµ� ��ġ�� ���� ���� 
        if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
            screen[rows - 1][cols - 1] = character; 
        }
        while (1) {
            // ȭ�� ���
            printf("\n");
            printf("**1234567890123456789012345678901234567890123456789012345678901234567890\n");
            printf("************************************************************************\n");
            for (int i = 1; i <= 20; i++) {
                printf("%02d", i);
                printf("%s\n", screen[i - 1]);
            }
            // ����ڷκ��� ��� �� �Է� �ޱ�
            printf("���� ���� �Է��ϼ��� (1-20): ");
            scanf_s("%d", &rows);
            printf("���� ���� �Է��ϼ��� (1-70): ");
            scanf_s("%d", &cols);

            printf("����� ���ڸ� �Է��ϼ���: (-������ ����)");
            scanf_s(" %c", &character); // 
            if (character == '-') break; // '-' Ű �Է� �� ����
            // �Էµ� ��ġ�� ���� ���� 
            if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
                screen[rows - 1][cols - 1] = character; // 
            }

            // ȭ�� ���
            printf("\n");
            printf("**12345678901234567890123456789012345678901234567890123456789012345678901234567890\n");
            printf("**********************************************************************************\n");
            for (int i = 1; i <= 20; i++) {
                printf("%02d", i);
                printf("%s\n", screen[i - 1]);
            }

            // �Էµ� ��ġ�� ���� ���� (�ε��� ����)
            if (rows >= 1 && rows <= 20 && cols >= 1 && cols <= 70) {
                screen[rows - 1][cols - 1] = character; // 0 ��� �ε��� ����

            }
        }



        printf("��ɾ �Է��ϼ��� (��: cls): ");
        scanf_s("%9s", cmd, (unsigned)_countof(cmd)); // ��ɾ� �Է�

        // ��ɾ� ����
        if (command(cmd)) {
            for (int i = 0; i < 20; i++) {
                memset(screen[i], '_', 70); // ��� ��ġ�� ���ٷ� �ʱ�ȭ
            }
        }
        else {
            printf("���α׷� ����.\n");
            break;
        }
    }
    return 0;
}