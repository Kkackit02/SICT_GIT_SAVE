#include <stdio.h>


/*
 * 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-03-18
 * 프로그램 설명 : 과제 4_2입니다.
 */


int main(void)
{
	int input_0 = 0;  // 입력값 0
	int input_1 = 0;  // 입력값 1

	int output_0 = 0; //일의자리와의 곱 결과
	int output_1 = 0; //십의자리와의 곱 결과
	int output_2 = 0; //백의자리와의 곱 결과

	int output_3 = 0; //최종값


	scanf("%d %d", &input_0, &input_1); //입력값 대입


	// 계산
	
	output_0 = (((input_1 % 100)%10) * input_0);  // 입력값(0)과 입력값(1)의 일의자리 계산
	output_1 = (((input_1 % 100)/10) * input_0);  // 입력값(0)과 입력값(1)의 십의자리 계산
	output_2 = ((input_1 / 100) * input_0);	      // 입력값(0)과 입력값(1)의 백의자리 계산
	
	output_3 = input_0 * input_1; //결과 계산 (output_0 + output_1 + output_2)

	printf("%d\n", output_0); //결과값 출력
	printf("%d\n", output_1);
	printf("%d\n", output_2);
        printf("%d\n", output_3);    	

	return 0; //0 반환

}



