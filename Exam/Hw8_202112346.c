/*
이름 : 정근녕
학번 : 202112346
프로그램 작성일 : 2021-06-01
프로그램 설명 : 과제 8 입니다.
*/

#define Range 1000001 // 입력값 범위 상수 지정
#include<stdio.h>
#include<string.h>


int take_K (char P[Range], int K[Range], int len_p); // 접두 접미가 겹치는 길이 구하기

int compare (char T[Range], char P[Range], int K[Range], int Result_List[100000],  int len_p, int len_T); // 비교 후 결과 값 출력

int main(void)
{

    char T[Range]; // n 은 1이상 100만 이하
    char P[Range]; // m 은 1이상 100만 이하
    int K[Range]; // 접두 접미 K
    int Result_List[100000]; // 결과값 담는 배열


    int len_T = 0; // 문자열 T의 길이 변수
    int len_P = 0; // 문자열 P의 길이 변수

    scanf("%[^\n]s", T); // T 입력 받기
    getchar(); // 버퍼 비우기
    scanf("%[^\n]s", P); // P 입력받기

    //printf("\n%s \n%s\n", T, P);

    len_T = strlen(T); //문자열 T의 길이 구하기
    len_P = strlen(P); //문자열 P의 길이 구하기
    //printf("%d , %d \n", len_T,len_P);

    take_K(P, K, len_P); //전처리로 K 구하기
    
   
    

    compare(T,P,K,Result_List,len_P,len_T); // 문자열 비교하기
    /*
     for (int i = 0; i < len_P; i++)
    {
        printf("K[%d] = %d\n", i, K[i]);
    }
    */

}


int take_K(char P[Range], int K[Range], int len_P) // 접두 접미가 겹치는 길이 -> K 구하기
{
    int count = 0;
    int i = 0;
    int j = 0;
    K[0] = 0; // 미리 지정

    for (int i = 1; i < len_P; i++)
    {
        while(1)
        {   
            if(j == 0 && P[i] != P[j]) // 만약 첫번째 검사에서 틀리다면
            {
                count = 0; // count 초기화
                K[i] = count; // K[i] = 0
                break;
                
            }
            else if(P[i] == P[j]) // 만약 같다면
            {
                K[i] = ++count; //K[i] = count , count는 연속으로 같을때마다 1씩 증가
                j++; // 다음 비교로 이동
                break;
            }
            else// 만약 첫번째가 아닌데 비교가 틀린다면
            {
                count = K[j-1]; // count 값을 전 K 값으로 변경
                j = K[j-1]; // 비교 위치 점프
            }
        }
    }
    
}
//ABC ABCDAB ABCDABCDABDE
//ABCDABD

int compare (char T[Range], char P[Range], int K[Range], int Result_List[100000], int len_P, int len_T) // 비교 후 결과 값 출력
{
    int i = 0;
    int j = 0;
    int count = 0;
    
    int result_count = 0;
    int time = 0;
    
    while(i < len_T)
    {
        while(1) // j 가 0이 아니고 비교가 틀렸다면
        {
            if(T[i] != P[j] && j > 0)
            {
                //printf("%c vs %c 에서 걸렸습니다. j = %d\n", T[i], P[j], i);
                j = K[j-1]; // 비교 위치 점프
            }

            if(j <= 0 || T[i] == P[j])
            {
                break;
            }
            
        }
        //printf("%c vs %c 를 비교했습니다.", T[i], P[j]);

        if(T[i] == P[j]) // 만약 같다면
        {
            if(j == len_P - 1) // 근데 현재 비교 위치가 마지막 위치였다면
            {
                Result_List[result_count] = i - j + 1; // 마지막 검사위치 - 비교한 배열 + 1 = 같은 패턴이 등장한 지점
                result_count++; // 동일한 패턴이 나온 횟수 & 결과값 순서
                j = K[j]; // 동일한 패턴에서 또 겹치는 부분이 있으면 점프
            }
            else // 검사가 아직 안끝났으면
            {
                j++;
            }
        }
        i++;
        
        //printf("\n");
    }
    
    printf("%d\n", result_count);
    for(int j = 0; j < result_count; j++)
    {
        printf("%d ", Result_List[j]);
    }
    printf("\n");
}
