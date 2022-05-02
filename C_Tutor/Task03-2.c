#include<stdio.h>

// C프로그래밍 0444-06 Homework 3-2 풀이
// 정근녕
int main(void)
{
    double exchange_rate = 0;
    int won = 0;
    
    printf("환율을 입력하시오: ");
    scanf("%lf", &exchange_rate);

    printf("원화 금액을 입력하시오: ");
    scanf("%d", &won);

    double dollar = won/exchange_rate;

    printf("원화 %d원은 %f달러입니다.", won, dollar);
}