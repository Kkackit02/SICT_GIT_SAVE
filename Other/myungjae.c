#include <stdio.h>


int main(void)
{
	char op;
	char str[12];
	printf("문자 입력 : ");
	scanf_s("%c", &op);
	
	printf("문자열 입력 : ");  
	scanf_s("%c", &str);  

	printf("문자 출력 : %c", op);
	printf("문자열 출력 : |%12c\t\n|", str);

}
