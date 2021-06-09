#include <stdio.h>


int main(void)
{
	int input_year = 0;
	int output = 0;

	scanf("%d", &input_year);


	output = (input_year % 4 == 0) && (input_year % 100 != 0) || (input_year % 400 == 0);


	printf("%d 는 윤년이 %d 입니다.", input_year, output);


	return 0;


}
