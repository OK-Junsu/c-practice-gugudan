#define _CRT_SECURE_NO_WARNINGS // scanf 에러 방지
#include <stdio.h>

int main() {
	// 콘솔 출력 인코딩을 UTF-8로 변경하는 명령어 실행
	system("chcp 65001");
	system("cls"); // 인코딩 변경 메시지를 지우기 위해 화면 초기화

	int dan;
	int i;

	// 프로그램을 계속 반복하기 위한 무한 루프
	while (1) {
		printf("정수를 입력하세요 (1~9, 종료하려면 0 입력): ");
		scanf("%d", &dan);

		// 종료 조건 (사용자가 0을 입력하면 프로그램 종료)
		if (dan == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}

		// 1부터 9 사이의 숫자인지 확인
		if (dan < 1 || dan > 9) {
			printf("1에서 9 사이의 정수를 입력해 주세요.\n\n");
			continue; // 다시 입력 단계로 돌아감
		}

		// 구구단 출력 루프
		printf("--- %d단 ---\n", dan);
		for (i = 1; i <= 9; i++) {
			printf("%d x %d = %d\n", dan, i, dan * i);
		}
		printf("------------\n\n");
	}

	return 0;
}
