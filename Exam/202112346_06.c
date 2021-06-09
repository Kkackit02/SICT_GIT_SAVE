/* 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-04-13
 * 프로그램 설명 : 과제 6입니다.
 */
#include<stdio.h>

// 함수를 미리 선언
void userInput(); // 입력 함수
void calc(int hour, int min); // 계산 함수

int main(void)
{
    userInput(); // 입력 함수 실행(내부에 계산 함수 포함)
}


void userInput() // 입력 함수
{
    int hour = 0; //시 변수
    int min = 0; //분 변수

    while(1) //무한 루프
    {
        printf("\n몇시, 몇분에 일어나기를 원하십니까? "); 
	scanf("%d %d", &hour, &min); //시간 및 분 입력 받기

	if(hour >= 0 && hour <= 23) // 시 범위 검사
	{  
	    if(min < 0 || min > 59) // 분 범위 검사
	    {
		printf("분을 잘못 입력하셨습니다. 분은 0 ~ 59 사이에 있어야 합니다.\n");
	    }

	    calc(hour, min); // 계산 함수
	    break; // 검사를 위한 무한 루프 탈출

	}

	else // 시간 범위가 아닐때
	{
	    printf("시를 잘못 입력하셨습니다. 시는 0 ~ 24 사이에 있어야 합니다.\n");

	    if(min < 0 || min > 59) // 시간 범위가 아니면서 분 범위가 아닐때 
	    {
	        printf("분을 잘못 입력하셨습니다. 분은 0 ~ 59 사이에 있어야 합니다.\n");     
	    }
	}

    }
}


void calc(int hour, int min) //계산 함수
{
    min -= 45; // 45분을 분에서 감소
    if(min < 0) // min이 0보다 작아지면
    {
        hour -= 1; // 시간에서 1 감소
	min = min + 60; // 음수가 된 분을 양수로 연산
	
	if(hour < 0)
	{
	    hour = 23; // 만약 시간이 0보다 작아진다면 23으로 변경
	}
    }

    printf("%d %d\n", hour, min); // 결과 값 출력
}
