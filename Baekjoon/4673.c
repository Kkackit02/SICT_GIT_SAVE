#include<stdio.h>

int selfNumber(int a,int max_range , int matrix[max_range]);
int print(int max_range, int matrix[max_range]);
int main(void)
{
    int start_N = 1;
    int max_range = 10000;

    int matrix[10000] = {0,};

    for (int i = 0; i < max_range; i++)
    {
	matrix[i] = i; // matrix 함수에 1~ 10000까지 값을 차례대로 삽입
    }

    for (start_N; start_N < max_range; start_N++)
    {
	selfNumber(start_N, matrix, max_range); 
    }

    print(matrix, max_range);
}




int selfNumber(int origin_number, int max_range , int matrix[max_range])
{
    
    int digit[4] = {0,}; // 0, 1, 2, 3, 4
    
    int temp = origin_number;
    int count = 0; // 자릿수 구하기용 변수
    int result = origin_number;

    while (temp != 0)
    {
        digit[count] = temp % 10; //가장 낮은 자리의 숫자부터 digit[]에 넣기
	temp /= 10; //가장 낮은 자리 숫자 삭제
	count++;
    }
    
    for (int i = 0; i < count; i++)
    {
	result += digit[i]; // 생성자 구하기
    }



    if((result <= max_range)) // matrix 배열에 생성자 위치 값에 0 삽입
    {
	matrix[result] = 0;
	selfNumber(result, matrix); //반복
    }
    
}

int print(int max_range, int matrix[max_range])
{
    for (int i = 0; i < max_range; i++)
    {
	// matrix 배열의 값이 0이 아니라면 셀프 넘버이므로 출력
	if(matrix[i] != 0)
	{
	    printf("%d\n", matrix[i]);
	}
    }
}
