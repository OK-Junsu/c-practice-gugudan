#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void clearInputBuffer();
int getValidInput();
void printVisualizationBar(int count);
void printMultiplicationTable(int dan);

int main() {
    system("chcp 65001");
    system("cls");

    while (1) {
        int dan = getValidInput();
        
        if (dan == -1) {
            continue;
        }
        
        if (dan == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        
        printMultiplicationTable(dan);
    }

    return 0;
}

void clearInputBuffer() {
    while (_kbhit()) {
        _getch();
    }
}

int getValidInput() {
    char input;
    int dan;
    
    clearInputBuffer();
    
    printf("\n[ 구구단 시각화 모드 ]\n");
    printf("출력할 단을 입력하세요 (1~9, 종료는 0): ");
    
    input = _getche();
    printf("\n");
    
    if (input < '0' || input > '9') {
        printf("⚠️ 숫자만 입력 가능합니다. 다시 입력해주세요.\n");
        return -1;
    }
    
    dan = input - '0';
    
    if (dan != 0 && (dan < 1 || dan > 9)) {
        printf("⚠️ 1에서 9 사이의 숫자만 가능합니다.\n");
        return -1;
    }
    
    return dan;
}

void printVisualizationBar(int count) {
    printf("| ");
    fflush(stdout);
    
    for (int i = 0; i < count / 2; i++) {
        printf("■");
        fflush(stdout);
        Sleep(30);
    }
    printf("\n");
}

void printMultiplicationTable(int dan) {
    int sum = 0;
    
    printf("\n▶ %d단 출력을 시작합니다!\n", dan);
    Sleep(500);
    printf("--------------------------------------------\n");
    Sleep(200);
    
    for (int i = 1; i <= 9; i++) {
        int result = dan * i;
        sum += result;
        
        printf("\033[1;33m%d x %d = %2d\033[0m  ", dan, i, result);
        fflush(stdout);
        Sleep(100);
        
        printVisualizationBar(result);
        Sleep(200);
    }
    
    printf("--------------------------------------------\n");
    Sleep(300);
    printf("✅ %d단의 결과값 총합: \033[1;32m%d\033[0m\n", dan, sum);
    printf("--------------------------------------------\n");
}
