#include<stdio.h>



int main(void)
{
	double c = 0, f = 0;

	printf("섭씨 온도로 변환할 화씨 온도를 적어주세요.");
	scanf("%lf", &f);

	c = (5.0/9.0) * (f-32);
	
	printf("결과 값은 %f 입니다. \n", c);

	return 0;
}

