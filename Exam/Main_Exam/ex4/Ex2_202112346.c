/*
 *이름 : 정근녕
 *학번 : 202112346
 *프로그램 작성일 : 2021-06-16
 *프로그램 설명 : 기말고사 문제 2입니다.
 */


#include<stdio.h>
#include<stdlib.h>

void triabglePrint(int heignt, int** pascal); // 출력 함수
void pascalTriangle(int height); // 계산하고 저장하는 함수

int main(void)
{
    int line = 0;
    printf("몇 번째 행까지 계산할지 입력하십시오.\n");
    scanf("%d", &line);

    pascalTriangle(line);
}

void pascalTriangle(int heignt) // 계산하고 저장하는 함수
{
    int **pascal; // 배열 선언

    // 전체 파스칼 2차원 배열 공간 동적 할당
    pascal = (int**) malloc (sizeof(int*) * heignt); 
    for(int i=0; i < heignt; i++) 
    {
        pascal[i] = (int*) malloc( sizeof(int) * (i + 1) );
    }
    

    
    //------ 데이터 저장

    for(int i = 0; i < heignt; i++) // 전체에 1 저장
    {
        for (int j = 0; j < i+1; j++)
        {
            
            *(*(pascal+i) + j) = 1; //배열을 1로 초기화 , pascal[j][i] = 1; 와 같음
        }
    }

    
    for (int i = 2; i < heignt; i++) // 가장 자리 1은 냅두고 안쪽만 계산
    {
        for (int j = 1; j < i; j++)
        {
            *(*(pascal+i) + j) = *(*(pascal+i-1) + j-1) + *(*(pascal+i-1) + j); // 계산 후 값 저장 , pascal[j][i] = pascal[j-1][i-1] + pascal[j][i-1]; 와 같음
        }
    }
    
    triabglePrint(heignt, pascal);
    
}


void triabglePrint(int heignt, int** pascal)// 출력 함수
{
    for(int i = 0; i < heignt; i++) // 순회 및 출력
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", *(*(pascal+i) + j)); // 전체를 순회하며 값 저장 printf("%d ", pascal[j][i]); 와 같음
        }
        printf("\n");
    }
}
