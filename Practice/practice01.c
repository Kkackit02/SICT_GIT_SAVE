#include <stdio.h>

int main(void)
{
	
	//변수 선언
	int n1, n2 = 0;


	//입력
	printf("두 개의 정수를 입력하십시오.\n");
	scanf("%d %d", &n1, &n2);
	

	//연산 및 출력
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	printf("%d - %d = %d\n", n1, n2, n1 - n2);
	printf("%d * %d = %d\n", n1, n2, n1 * n2);
	printf("%d / %d = %d\n", n1, n2, n1 / n2);
	printf("%d %% %d = %d\n", n1, n2, n1 % n2);


	//0 반환
	return 0;
}

