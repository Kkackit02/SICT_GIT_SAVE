#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
	int start_money = 50;
	int cash = 0;
	int count = 0;
	int goal = 250;
	double win_percent = 0.5;
	double percent = 0;

	srand(time(NULL));


	printf("하루에 가져갈 돈의 액수는?");
	scanf("%d" , &start_money);

	printf("목표 금액은?");
	scanf("%d" , &goal);



	for (int i = 100; i != 0; i--)
	{
	    cash = start_money;
	
	    while(1)
	    {
		percent = (double)rand()/(double)RAND_MAX;
		//printf("percent = %f \n" , percent);
		if(percent >= win_percent)
		{
			cash ++;
		}
		else
		{
			cash --;
		}

		//printf("%d \n ", cash);

		if(cash == 0)
		{
			break;
		}

		if(cash == goal)
		{
			count++;
			break;
		}
	    }
	}

	printf("%d \n" , count);


}
