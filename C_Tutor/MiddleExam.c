#include <stdio.h>

int s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
int print_seats() {
	printf("0 1 2 3 4\n");
	printf("----------\n");
	printf("%d %d %d %d %d \n", s0, s1, s2, s3, s4);
	return 1;
}
int reserve(int seat) {
	if (seat == 0) {
		if (s0 == 0) {
			s0 = 1;
		}
		else { printf("선택된 자리는 이미 예약되어있습니다0\n."); }
	}
	else if (seat == 1) {
		if (s1 == 0) {
			s1 = 1;
		}
		else { printf("선택된 자리는 이미 예약되어있습니다.\n"); }
	}
	else if (seat == 2) {
		if (s2 == 0) {
			s2 = 1;
		}
		else { printf("선택된 자리는 이미 예약되어있습니다.\n"); }
	}
	else if (seat == 3) {
		if (s3 == 0) {
			s3 = 1;
		}
		else { printf("선택된 자리는 이미 예약되어있습니다.\n"); }
	}
	else if (seat == 4) {
		if (s4 == 0) {
			s4 = 1;
		}
		else { printf("선택된 자리는 이미 예약되어있습니다.\n"); }
	}
	else {
		printf("잘못된 입력값입니다.\n");
		return -1;
	}
	return 1;
}

int cancel(int seat) {
	if (seat == 0) {
		if (s0 == 1) {
			s0 = 0;
		}
		else { printf("선택된 자리는 예약되어있지 않습니다.\n"); }
	}
	if (seat == 1) {
		if (s1 == 1) {
			s1 = 0;
		}
		else { printf("선택된 자리는 예약되어있지 않습니다.\n"); }
	}
	if (seat == 2) {
		if (s2 == 1) {
			s2 = 0;
		}
		else { printf("선택된 자리는 예약되어있지 않습니다.\n"); }
	}
	if (seat == 3) {
		if (s3 == 1) {
			s3 = 0;
		}
		else { printf("선택된 자리는 예약되어있지 않습니다.\n"); }
	}
	if (seat == 4) {
		if (s4 == 1) {
			s4 = 0;
		}
		else { printf("선택된 자리는 예약되어있지 않습니다.\n."); }
	}
	else {
		printf("잘못된 입력값입니다.\n");
		return -1;
	}
	return 1;
}

int main(void)
{
	int select, s;
	int result;
	do
	{
		printf("1--좌석확인하기\n");
		printf("2--예약하기\n");
		printf("3--예약취소하기\n");
		printf("4--종료하기\n");
		printf("메뉴를 선택하시오: \n");
		scanf("%d", &select);

		if (select == 1)
			print_seats();
		else if (select == 2)
		{
			printf("예약을 원하는 자리를 선택해주세요: ");
			scanf("%d", &s);
			reserve(s);
			printf("선택하신 자리가 예약되었습니다.\n");
			print_seats();
		}
		else if (select == 3)
		{
			printf("취소하실 자리를 선택해주세요: ");
			scanf("%d", &s);
			cancel(s);
			printf("선택하신 자리가 취소되었습니다.\n");
			print_seats();
		}
	} while (select != 4);
	printf("선택된 메뉴 = 종료하기\n\n");
	printf("이용해주셔서 감사합니다.\n");
	
	return 0;
}