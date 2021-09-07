#include<stdio.h>
void InputData(int i, int result_Matrix[]);
int main(void)
{
    int T = 0; //테스트 케이스 시행 횟수
    
    
    scanf("%d", &T);
    int result[T];
    for (int i = 0; i < T; i++)
    {
        InputData(i, result);
    }

    for (int i = 0; i < T; i++)
    {
        printf("%d\n",result[i]);
    }
}


void InputData(int i, int result_Matrix[])
{
    int H = 0; //세로
    int W = 0; //가로
    int N = 0; //몇 번째 손님
    
    int temp = 0;
    scanf("%d", &H);
    scanf("%d", &W);
    scanf("%d", &N);
    
    int Room =  (N / H) + 1; 
    int Floor = N % H;

    if(Floor == 0)
    {
        Floor = H;
        Room--;
    } 

    
    temp = (Floor * 100 + Room);

    result_Matrix[i] = temp;
}