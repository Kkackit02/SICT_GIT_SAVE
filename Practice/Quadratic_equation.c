#include<stdio.h>
#include<math.h>

int main(void)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double result1 = 0;
    double result2 = 0;

    printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오 :");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == 0)
    {
        result1 = -c / b;
	printf("근은 %lf 입니다.\n", result1);
    }

    else if ((b*b) - (4 * a * c) < 0)
    {
        printf("실근은 존재하지 않습니다.\n");
    }

    else
    {
	result1 = (((-b + sqrt(((b*b) - (4 * a * c)))) / (2 * a)));
	result2 = (((-b + sqrt(((b*b) + (4 * a * c)))) / (2 * a)));

	printf("방정식의 근은 %lf 또는 %lf 입니다.\n" , result1, result2);	
    }
    
    return 0;
}
