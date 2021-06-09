#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp_car(int car[]);
void get_rand(int car[]);

int main(void)
{
    double car_one_dist = 0;
    double car_two_dist = 0;
    double distance = 6;
    
    srand((unsigned)time(NULL));
    
    int car[10] = {0};

    for(int i= 0; i < distance; i++)
    {
	get_rand(car);
	/*
	car_one_dist += rand() % 100; //0부터 99까지 받기
	car_two_dist += rand() % 100;
	for (int j = 0; j < 10; j++)
	{
		car[j] += rand() % 100;
		//disp_car(j+1, car[j]);
	}
        disp_car(1, car_one_dist);
	disp_car(2, car_two_dist);
	*/

	disp_car(car);
	printf("------------------------------\n");
	//getch();
    }

    return 0;

}

void get_rand(int car[])
{

	for (int j = 0; j < 10; j++)
	{
		car[j] += rand() % 100;
	}

}

void disp_car(int car[])
{

    for (int j = 0; j < 10; j++)
    {

	int car_number = j + 1;

	int distance = car[j];

        printf("CAR #%d : ", car_number);

        for (int i = 0; i < distance/10; i++)
        {
	    printf("*");
        }

        printf("\n");
    }
}
