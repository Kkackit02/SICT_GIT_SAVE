#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd);


int main(void)
{
    int a = 0;
    int b = 0;

    printf("두개의 정수를 입력하시오 : ");
    scanf("%d %d", &a, &b);
    int lcm = 0;
    int gcd = 0;

    int *p_lcm = &lcm;
    int *p_gcd = &gcd;

    get_lcm_gcd(a,b, p_lcm, p_gcd);

    printf("최소공배수는 %d입니다.\n", *p_lcm);
    printf("최대공약수는 %d입니다.\n", *p_gcd);
}

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd)
{

    for(int i=1; i<=x; i++)    
    {
        if(x%i==0 && y%i==0)
        {
           *p_gcd = i;
        }
        
    }

    *p_lcm = (x*y) / *p_gcd;
}