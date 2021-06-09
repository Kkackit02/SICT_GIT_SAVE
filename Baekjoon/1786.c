#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#define Range 1000000

#include<stdio.h>
#include<string.h>


int take_Pi (char P[Range], int Pi[Range], int len_p); // 접두 접미가 겹치는 길이 구하기

int compare (char T[Range], char P[Range], int Pi[Range], int Result_List[100000],  int len_p, int len_T); // 비교 후 결과 값 출력

int main(void)
{
    char T[Range]; // n 은 1이상 100만 이하
    char P[Range]; // m 은 1이상 100만 이하
    int Pi[Range]; // 접두 접미 pi
    int Result_List[100000];


    char prefix[Range];
    char suffix[Range];

    int len_T = 0;
    int len_P = 0;

    scanf("%[^\n]s", T);
    getchar();
    scanf("%[^\n]s", P);

    //printf("\n%s \n%s\n", T, P);

    len_T = strlen(T);
    len_P = strlen(P);
    //printf("%d , %d \n", len_T,len_P);

    take_Pi(P, Pi, len_P);
    compare(T,P,Pi,Result_List,len_P,len_T);
    

}


int take_Pi(char P[Range], int Pi[Range], int len_P) // 접두 접미가 겹치는 길이 구하기
{
    int count = 0;
    int i = 0;
    int j = 0;
    Pi[0] = 0;

    for (int i = 1; i < len_P; i++)
    {
        while(1)
        {   
            if(j == 0 && P[i] != P[j])
            {
                count = 0;
                Pi[i] = count;
                break;
                
            }
            else if(P[i] == P[j])
            {
                Pi[i] = ++count; 
                j++;
                break;
            }
            else
            {
                count = Pi[j-1];
                j = Pi[j-1];
            }
        }
    }
    
    /*
    for (int i =0; i < len_P; i++)
    {
        printf("Pi[%d] = %d \n", i, Pi[i]);
    }
    */
}
//ABC ABCDAB ABCDABCDABDE
//ABCDABD

int compare (char T[Range], char P[Range], int Pi[Range], int Result_List[100000], int len_P, int len_T) // 비교 후 결과 값 출력
{
    int i = 0;
    int count = 0;
    
    int result_count = 0;
    int result_index = 0;
    while(1)
    {
        //printf("%d \n", time++);
        for (int j = 0; j < len_P; j++)
        {

            if(T[i + j] == P[j])
            {
                count++;
                //printf("%c %c\n", T[index + i], P[i]);
            }
            else
            {
                //printf("불합 %c %c\n", T[index + i], P[i]);
                i += Pi[count];
                //printf("%d , Pi : %d\n", count, Pi[count]);
                count--;
                break;
            }
            if(count == len_P)
            {
                result_count++;
                Result_List[result_index] = i + 1;
                result_index++;
                //printf("위치 %d\n", index + 1);
            }
        }

        count = 0;
        i++;

        if(i > Range)
        {
            break;
        }
        if(i >= len_T)
        {
            break;
        }
    }

    printf("%d\n", result_count);
    for(int j = 0; j < result_index; j++)
    {
        printf("%d ", Result_List[j]);
    }
    printf("\n");
}
