/* 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2020-03-29
 * 프로그램 설명 : 과제 05-2입니다.
 */
#include <stdio.h>

int main(void)
{

    int input = 0; // 입력값을 위한 변수
    
    int input_end = 0; // 조건 1을 위한 수 끝 범위 변수

    int input_length = 0; // 수의 길이
    
    int input_units = 0; // 일의자리를 넣기 위한 변수
    
    int temp_data  = 0; // 조건 3,4 계산용 변수 (input 대입)
    
    int length_check = 0; // 수의 길이 판단용 변수

    int mod_check = 1; // 수 분할용 변수
    
    int result = 0; // 조건을 만족하는 수
    
    int break_check = 0; // 이중 중첩 탈출용 변수   
    

    printf("숫자를 입력하십시오. "); 
    
    scanf("%d", &input);

    
    input_end = input + 21; // 범위 설정
    

    for (input; input < input_end; input++)  //조건1을 만족하기 위한 반복문
    {      
	    break_check = 0;
	    input_length = 0;
	    length_check = input; 
	    // 수의 길이 판단
	    while(length_check != 0)
	    {
	        
		input_length += 1; 
	        length_check /= 10;
	    }
    	    
    	    
    	    if(input % 2 == 0) // 조건2
	    {
	        // 그냥 넘기기  
	    }

	    else // 조건 2에 맞지 않으면 다음 수로 넘어가기
	    {
		    continue;
	    }
	    
	    input_units = input % 10; // 일의 자리수 구하기  
	    temp_data = input; // 계산용 수 초기화
	    

	    for (input_length; input_length != 1; input_length--)  // 자릿수 계산 (높은 자릿수에서 낮은 자릿수 순서로 이동)
	    {
	        
		mod_check = 1;
		for (int i = 1; i < input_length; i++) // 가장 높은 자리의 숫자를 구하기 위한 10의 제곱수 계산
		{
		    mod_check *= 10; // 백의 자리수면 100, 십의 자리수면 10 ... 
		}
		
		 
		if((temp_data / mod_check) > 3 && (temp_data / mod_check) < input_units) // 조건 3과 조건 4 검사
		{   
		    temp_data = temp_data % mod_check; // 조건 3과 조건 4를 통과했다면 가장 높은 자릿수를 삭제
		    

		    continue; // 바깥 for문으로 이동 
		}

		else
		{
		    break_check = 1; // 조건 3, 4 중 하나라도 틀렸다면 다음 수로 넘어가야하기에 이중 반복문 탈출을 위한 변수
		    break; 
		}
	    }

	    if(break_check == 1) // 이중 반복문 탈출
	    {
		break_check = 0; // 초기화
		continue;
	    }

	    if(input > 10)
	    {

	    
	    result += 1; // 조건을 모두 통과했다면 결과 변수에 1 추가
	    }	    
    }
        
    printf("조건을 만족하는 수의 갯수는 %d개 입니다.\n", result); // 결과 출력
    return 0;
}
