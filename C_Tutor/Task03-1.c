#include<stdio.h>

// C프로그래밍 0444-06 Homework 3-1 풀이
// 정근녕
int main(void)
{
    int x = 21;
    int y = 10;

    int sum = x+y;
    int subtraction = x-y;
    int multiplication = x*y;
    int division = x/y;
    int remainder = x%y;

    printf("두수의 합: %d\n", sum);
    printf("두수의 차: %d\n", subtraction);
    printf("두수의 곱: %d\n", multiplication);
    printf("두수의 몫: %d\n", division);
    printf("두수의 나머지: %d\n", remainder);
    
}