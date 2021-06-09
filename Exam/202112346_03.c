#include <stdio.h> //헤더파일 포함

/*
 * 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-03-12
 * 프로그램 설명 : 과제 3 입니다.
 */


int main(void) //메인 함수 시작
{
	
	char name_j = 'J';      // 이름에 사용할 변수들 선언 및 값 저장
	char name_u = 'u';
	char name_n = 'n';
	char name_g = 'g';  
	char name_e = 'e';
	char name_o = 'o';
	char name_y = 'y';

 
	int class_number = 202112346; //학번 변수 선언 및 값 저장
	char gender = 'M'; //성별 변수 선언 및 값 저장
	
	printf("이름 : %c%c%c%c %c%c%c%c%c%c%c%c%c%c\n", 
			name_j, name_u, name_n, name_g, 
			name_g, name_e, name_u, name_n, 
			name_n, name_y, name_e, name_o, name_n, name_g); // 이름 출력

	printf("학번 : %d \n", class_number); // 학번 출력
	printf("성별 : %c \n", gender); // 성별 출력

	return 0; //외부로 0 반환
}	//함수 종료
