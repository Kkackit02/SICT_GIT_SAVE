#include <stdio.h>

/*
 * 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-03-18
 * 프로그램 설명 : 과제 4-1입니다.
*/


int main(void)
{	
	//변수 선언 및 초기화
	int A = 0;
	int B = 0;
	int C = 0;
	
	int sum_0 = 0;
	int sum_1 = 0;
	int sum_2 = 0;
	int sum_3 = 0;

	// 입력받기
	scanf("%d %d %d", &A,&B,&C);

	//계산
	sum_0 = (A+B)%C;
	sum_1 = ((A%C)+(B%C))%C;
			
	sum_2 = (A*B)%C;                                                                                         
	sum_3 = ((A%C)*(B%C))%C;

	printf("(A+B)%%C는 ((A%%C) + (B%%C))%%C와 %d 입니다.\n" // 추가 과제 조건 0/1 출력
		,(sum_0 == sum_1));	
	
	printf("(A*B)%%C는 ((A%%C) x (B%%C))%%C와 %d 입니다.\n" // 추가 과제 조건 0/1 출력
		,(sum_2 == sum_3)); 

	return 0;	// 0 반환
	
}

