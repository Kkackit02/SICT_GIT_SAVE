/* 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-04-21
 * 프로그램 설명 : 중간고사 문제 2입니다.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int inputNum(int Forward_N, int Back_N);
char restart();
char cal(int random);

int main(void)
{
        srand(time(NULL));
	
	while(1)
	{
	   

	    int random = rand() % 100;

	    char Re = ' ';
	    printf("수를 맞추어 보세요.\n");
	    printf("0 - 99\n");
	    Re = cal(random);
	   
	    if(Re == 'y')
	    {
		
	    }
	    else if(Re == 'n')
	    {
		break;
	    }

	}

	
}

int inputNum(int Forward_N, int Back_N)
{
    int input = 0;

    while(1)
    {

        scanf("%d", &input);

	if(input > Back_N || input < Forward_N)
	{
	    printf("잘못 입력했습니다. 값을 다시 입력하시오. \n");
	}
	else
	{
	    return input;
	
	}
    }
    

}

char cal(int random)
{
    int Forward_N = 0;
    int Back_N = 99;
    int data = 0;

    int count = 1;
    while(1)
    {

	data = inputNum(Forward_N, Back_N);
	printf("%d>> %d\n",count, data);
	count++;
        if(random > data)
        {
	    Forward_N = data;
	    printf("더 높게\n");
        }
        else if (random < data)
        {
	
	    Back_N = data;	    
	    printf("더 낮게\n");
        }
        else if ( random == data)
        {
	    printf("맞았습니다.\n");
	    break;
        }
	
	printf("%d-%d\n", Forward_N, Back_N);
    }
    
    int Re = restart();
    return Re;

    
}

char restart()
{
    char input = ' ';
    printf("다시하겠습니까?(y/n)>> ");
    

    while(1)
    {
	scanf("%c", &input);
        if(input == 'y' || input == 'Y')
        {
	    return 'y';
	    break;
        }

	else if (input == 'n' || input == 'N')
        {
	    return 'n';
	    break;
        }
    
        else
        {
    	    printf("잘못 입력했습니다. 값을 다시 입력하시오. \n");
	    continue;
        }
    }
}
