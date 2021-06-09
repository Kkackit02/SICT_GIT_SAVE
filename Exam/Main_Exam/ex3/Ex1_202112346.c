/*
 *이름 : 정근녕
 *학번 : 202112346
 *프로그램 작성일 : 2021-05-17
 *프로그램 설명 : 시험3 문제 1입니다.
 */
#include<stdio.h>

void readInput(int testcase, int student, double matrix[testcase][student]);
void cal(int testcase, int student, double matrix[testcase][student]);

int main(void)
{
    int testcase = 0;
    int student = 0;

    double result = 0.0;

    printf("테스트 케이스와 최대 학생 수를 입력하시오: ");
    scanf("%d %d", &testcase, &student);

    
    double matrix[testcase][student];

	for (int j = 0; j < testcase; j++)
	{
	    for (int k = 0; k < student; k++)
	    {
		    (*(*(matrix + j) + k)) = 0;
	    }
	}
    

    readInput(testcase, student, matrix);

    cal(testcase, student, matrix);

}

void readInput(int testcase, int student, double matrix[testcase][student])
{
    int input_sub = 0;
    int temp = 0;
    double result = 0;
    double add = 0;

    double final = 0.0;

    for (int x = 0; x < testcase; x++)
    {
        final =0;
        add = 0;
	    printf("%d번 테스트 케이스를 입력하시오.: ", x+1);
        scanf("%d", &input_sub); //과목 수

        for (int i = 0; i < input_sub; i++) // 값 집어넣기 및 테스트 케이스 평균 계산
        {
            scanf("%d", &temp);
            (*(*(matrix + x) + i)) = temp; 
            add += temp;
        }	
        result = add / input_sub;

        for (int i = 0; i < input_sub; i++)
        {
            if((*(*(matrix + x) + i)) > result)
            {
                final++;
            }
        }
        //printf("%f", final / input_sub);
        final /= input_sub; // 비율 구하기
        *(*(matrix) + x) = final;
        //matrix[x][1] = final/input_sub;
        //printf("%f", final);
    }




}

void cal(int testcase, int student, double matrix[testcase][student])
{
    double result = 0;
    double people = 0;

    printf("\n결과 : \n");
    
    for (int i = 0; i < testcase; i++)
    {
        double print_data = *(*(matrix) + i);
        //double print_data = matrix[i][1];
        printf("%d번 테스트 케이스 결과: %.3f%% \n", (i+1), print_data *100);
    }

}