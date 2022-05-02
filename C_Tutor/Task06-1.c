#include <stdio.h>

int main()
{
	int s0, s1, s2, s3, s4, select, seat, cancel;
	s0=0, s1=0, s2=0, s3=0, s4 = 0;

	do
	{
		printf("1---좌석확인하기\n");
		printf("2---예약하기\n"); 
		printf("3---예약취소하기\n");
		printf("4--- 종료하기\n"); 
		printf("메뉴를 선택하시요: ");
		scanf("%d", &select);
		if (select == 1)
		{
			printf("선택된 메뉴 = 좌석확인하기\n\n");
			printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
		else if (select == 2)
		{
			printf("선택된 메뉴 = 예약하기\n\n");
			printf("예약을 원하는 자리는? ");
			scanf("%d", &seat);

			int successFlag = 0; // 0이면 예약 완료, 1이면 이미 예약된 자리.  

			if (seat == 0)
			{
				if (s0 == 0)
				{
					s0 = 1;
					successFlag = 0;
				}
				else if (s0 == 1)
				{
					successFlag = 1;
				}
			}
			if (seat == 1)
			{
				if (s1 == 0)
				{
					s1 = 1;
					successFlag = 0;
				
				}
				else if (s1 == 1)
				{
					successFlag = 1;
				}
			}
			if (seat == 2)
			{
				if (s2 == 0)
				{
					s2 = 1;
					successFlag = 0;
				}
				else if (s2 == 1)
				{
					successFlag = 1;
				}
			}
			if (seat == 3)
			{
				if (s3 == 0)
				{
					s3 = 1;
					successFlag = 0;
					
				}
				else if (s3 == 1)
				{
					successFlag = 1;
				}
			}
			if (seat == 4)
			{
				if (s4 == 0)
				{
					s4 = 1;
					successFlag = 0;
					
				}
				else if (s4 == 1)
				{
					successFlag = 1;
				}
			}


			if(successFlag == 0)
			{
				printf("예약이 완료되었습니다.\n");
				printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
			}
			else
			{
				printf("이미 예약된 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
			}


		}
		else if (select == 3)
		{
			printf("선택된 메뉴 = 예약취소하기\n\n");
			printf("예약취소를 원하는 자리는? ");
			scanf("%d", &cancel);

			if (cancel == 0)
			{
				if (s0 == 1)
				{
					s0 = 0;
					printf("예약취소가 완료되었습니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
				else if (s0 == 0)
				{
					printf("예약되지 않은 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
			}
			if (cancel == 1)
			{
				if (s1 == 1)
				{
					s1 = 0;
					printf("예약취소가 완료되었습니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
				else if (s1 == 0)
				{
					printf("예약되지 않은 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
			}
			if (cancel == 2)
			{
				if (s2 == 1)
				{
					s2 = 0;
					printf("예약취소가 완료되었습니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
				else if (s2 == 0)
				{
					printf("예약되지 않은 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
			}
			if (cancel == 3)
			{
				if (s3 == 1)
				{
					s3 = 0;
					printf("예약취소가 완료되었습니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
				else if (s3 == 0)
				{
					printf("예약되지 않은 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
			}
			if (cancel == 4)
			{
				if (s4 == 1)
				{
					s4 = 0;
					printf("예약취소가 완료되었습니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
				else if (s4 == 0)
				{
					printf("예약되지 않은 자리입니다.\n");
					printf("0 1 2 3 4\n---------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
				}
			}
		}
	} while (select != 4);
	printf("선택된 메뉴 = 종료하기\n\n");
	printf("이용해 주셔서 감사합니다.\n");

}