/* 극장 예약 시스템
   21-04-16
*/

#include <stdio.h>

int main()
{
    int number = 0; 
    int seats[10] = {0};
    char yesno = '0';
    int i;

    while(1)
    {

	yesno = '0';
        printf("좌석을 예약하시겠습니까?(y or n)\n");
        scanf("%c", &yesno);
        
	
	if(yesno == 'y')
        {	
            printf("------------------------\n");
            printf("1 2 3 4 5 6 7 8 9 10\n");
            printf("------------------------\n");
   
            for(i=0;i<10;i++)
            {
                printf("%d ", seats[i]);
            }
	    printf("\n");

            printf("몇번째 좌석 예약?\n");

            scanf("%d", &number);

	    if(seats[number-1] == 0)
	    {
	        seats[number-1] = 1;
	    
	        printf("예약되었습니다.\n");
		
		//continue;
	    }

	    else if(seats[number-1] == 1)
	    {
	       printf("이미 예약됨. 다른 좌석 선택하세요.\n");
	       //continue;
	    }
	}
	   
	else if(yesno == 'n')
	{
	    break;
	}


    }

    return 0;
}







