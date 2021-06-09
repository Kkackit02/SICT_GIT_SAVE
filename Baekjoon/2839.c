#include<stdio.h>

int main(void)
{
	int sugar = 0;

	scanf("%d", &sugar);

	int other_check = 0; // 가능 불가능 검사

	int result = -1;
	int Max_3 = 0;
	int Max_5 = 0;

	Max_3 = sugar/3;
	Max_5 = sugar/5;

	
	for (int i = 0; i < Max_3 + 1; i++) //3Kg
	{
		for (int j = 0; j < Max_5 + 1; j++) //5Kg
		{
			if((3 * i + 5 * j) == sugar)
			{
				if(other_check == 0)
				{
					other_check = 1;
					result = i+j;
				}
					
				(result > i + j) ? (result = i + j) : 0;
			}
		}
	}

	printf("%d", result);
		
}
