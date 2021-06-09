#include <stdio.h>

int main ()
{
    int a = 0, b = 0;
    int temp_a = 0, temp_b = 0;
    int max = 0 ,min = 0;
    int reminder = 0;
    int swap = 0;
    int rep_sub = 0, rep_div = 0;
    
    printf("두 개의 정수를 입력하시오 : ");
    scanf("%d%d", &a,&b);
    
    temp_a = a;
    temp_b = b;

    // 빼기방법
    while(temp_a && temp_a != temp_b){
        if(temp_b > temp_a) // a가 b보다 크게 스왑
        {
            swap = temp_a;
            temp_a = temp_b;
            temp_b = swap;
        }

        temp_a = temp_a - temp_b; // (==) a -= b;
        rep_sub = rep_sub + 1; // (==)  rep_sub++;
    }
    
    printf("빼기방법의 최대 공약수 : %d, 반복 : %d\n", temp_b, rep_sub);
    
    
    // 나머지 방법
    if (a<b){
        max = b;
        min = a;
    }
    else{
        max = a;
        min = b;
    }
    
    
    while (min != 0){
        reminder = max % min;
        max = min;
        min = reminder;
        rep_div = rep_div + 1;
    }
    printf("나머지 방법 최대 공약수 : %d, 반복 : %d\n", max, rep_div);
    
    
    
    return 0;
}