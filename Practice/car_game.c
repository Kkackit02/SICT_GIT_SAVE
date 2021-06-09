/* 자동차 게임 프로그래밍
   21-04-16
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void disp_car(int car_num,int dis);

int main()
{
    int car1, car2 = 0, 0;

    srand((unsigned)time(NULL));

    for(int i=0;i<6; i++)
    {
	car1, car2 = 0;
	//printf("%d\n", car1);
        car1 += (rand()%100);
        car2 += (rand()%100);

	disp_car(1,car1);
	disp_car(2,car2);
	printf("-------------------------\n");

	printf("%d 그리고 %d\n", car1, car2);
    }

    return 0;
}

void disp_car(int car_num, int dis)
{
    int i;
    printf("CAR #%d: ", car_num);

    for(i=0;i<dis/10; i++)
    {
        printf("*");
    }

    printf("\n");
}
