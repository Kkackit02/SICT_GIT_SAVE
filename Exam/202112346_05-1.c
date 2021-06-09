/*
 * 이름 : 정근녕                                                                                                        
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-03-25
 * 프로그램 설명 : 과제 5-1입니다.
 */  

#include<stdio.h>


int main(void)
{
    
    int input = 0; // 처음 입력값 변수
    	
    int result_count = 0; //조건 만족하는 수의 갯수를 담을 변수

    int first_check = 0; //조건 1 변수
    int second_check = 0; //조건 2 변수
    int three_check = 0; //조건 3 변수
    
    //처음 입력값 받기 (10~95까지 받음)
    printf("두 자리 숫자를 입력하시오 (10 ~ 95): ");
    scanf("%d", &input);

    first_check = ((input+1)%2); // 짝수이다. 짝수일때 1로 하기 위해서 input에 1을 더함

    second_check = ((input/10) + 6) / 10; // 십의 자릿 수 > 3
   
    three_check = (((input % 10) - (input/10) + 9) / 10); // 일의 자릿 수 > 십의 자릿 수
   
    result_count += (first_check + second_check + three_check + 7) / 10; // 3 조건이 모두 참이면 result_count 에 1 더하기, 그렇지 않으면 0더하기 
   
    input += 1; //다음 수로 넘어가기



    //이하 4번 반복

    first_check = ((input+1)%2);                                             
    second_check = ((input/10) + 6) / 10;                                       
    three_check = (((input % 10) - (input/10) + 9) / 10);         
    result_count += (first_check + second_check + three_check + 7) / 10;
    input += 1; 

    first_check = ((input+1)%2); 
    second_check = ((input/10) + 6) / 10;
    three_check = (((input % 10) - (input/10) + 9) / 10); 
    result_count += (first_check + second_check + three_check + 7) / 10;
    input += 1;
    
    first_check = ((input+1)%2);
    second_check = ((input/10) + 6) / 10;
    three_check = (((input % 10) - (input/10) + 9) / 10);
    result_count += (first_check + second_check + three_check + 7) / 10;
    input += 1;

    first_check = ((input+1)%2); 
    second_check = ((input/10) + 6) / 10; 
    three_check = (((input % 10) - (input/10) + 9) / 10); 
    result_count += (first_check + second_check + three_check + 7) / 10;
    //계산 결과 출력
    printf("조건을 만족하는 수의 갯수는 %d개 입니다.\n", result_count);
    
    return 0;

}
