#include<stdio.h>

void get_sum_diff(int x, int y, int*p_sum, int *p_diff);


int main(void)
{
    int x = 0;
    int y = 0;

    printf("두 정수를 입력하시오.\n");
    scanf("%d %d", &x, &y);

    int sum = 0;
    int diff = 0;

    int *p_sum = &sum;
    int *p_diff = &diff;

    get_sum_diff(x,y, p_sum, p_diff);

    printf("원소들의 합 = %d\n", sum);
    printf("원소들의 차 = %d\n", diff);
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff)
{
    (*p_sum) = x+y;
    (*p_diff) = x-y;
}