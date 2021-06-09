#include <stdio.h>

int main(void)
{

	int n1, n2 = 0;

	int five_T = 0;
	int one_T = 0;
	int five_H = 0;
	int one_H = 0;


	printf("물건 값, 낸 돈을 입력하세요");
	while(1)
	{
		scanf("%d %d", &n1, &n2);	
	
		if(n1 <= n2)
		{
			break;
		}

		else 
		{
			printf("돈이 부족합니다! 다시 입력하십시오");
		}
	}

	
	int Change = n2 - n1;

	five_T = Change/5000;
	Change = Change%5000;
	one_T = Change/1000;
	Change = Change%1000;
	five_H = Change/500;
	Change = Change%500;
	one_H = Change/100;
	Change = Change%100;

	printf("5천원은 %d장\n" , five_T);
	printf("1천원은 %d장\n" , one_T);
	printf("5백원은 %d개\n" , five_H);
	printf("백원은 %d개\n" , one_H);


	return 0;
}

