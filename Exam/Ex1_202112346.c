/*
 *이름 : 정근녕
 *학번 : 202112346
 *프로그램 작성일 : 2021-04-21
 *프로그램 설명 : 중간고사 문제 1입니다.
 * 
 */

#include<stdio.h>

void readInput(int testcase, int student, int matrix[2][testcase][student]);
void cal(int testcase, int student, int matrix[2][testcase][student]);

int main(void)
{
    int testcase = 0;
    int student = 0;

    printf("테스트 케이스와 최대 학생 수를 입력하시오: ");
    scanf("%d %d", &testcase, &student);

    int matrix[2][testcase][student];

    for (int i = 0; i < 2; i++) //초기화
    {
	for (int j = 0; j < testcase; j++)
	{
	    for (int k = 0; k < student; k++)
	    {
		matrix[i][j][k] = 0;
	    }
	}
    }

    readInput(testcase, student, matrix);

    cal(testcase, student, matrix);

}

void readInput(int testcase, int student, int matrix[2][testcase][student])
{
    int input_sub = 0;
    int temp = 0;
    int result = 0;


    for (int x = 0; x < testcase; x++)
    {
	printf("%d번 테스트 케이스를 입력하시오.: ", x+1);
	scanf("%d", &input_sub);
	

	for (int i = 0; i < input_sub; i++) // 값 집어넣기
	{
	    scanf("%d", &temp);
	    //printf("%d temp \n", temp);
	    matrix[0][x][i] = temp;
	    matrix[1][x][0] = input_sub; 
	}	
    } 



}

void cal(int testcase, int student, int matrix[2][testcase][student])
{
    double result = 0;
    double people = 0;
    double print_data = 0;
    printf("\n결과 : \n");
    for (int i = 0; i < testcase; i++)
    {
	result = 0;
	people = 0;
	for (int j = 0; j < student; j++)
	{
	    result += matrix[0][i][j];
	    // 값 계산
	}

	result = result / matrix[1][i][0];

	for (int k = 0; k < student; k++)
	{
	    if(matrix[0][i][k] > result)
	    {
	        people ++; // 넘는 인원 구하기
		
	    }
	}
	
	
	print_data = (people / matrix[1][i][0]) * 100; //비율 구하기

	printf("%d번 테스트 케이스 결과: %.3f%% \n", (i+1), print_data);
    }


}

