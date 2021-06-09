#include<stdio.h>

int main(void)
{
    //int matrix[2];
    int len = 0;
    int temp = 0;
    scanf("%d", &len);


    int result = 0;
    while(1)
    {
        char *quiz;
        int add = 1;
        
        scanf("%s", quiz);
        while(1)
        {
            if(*quiz == 'O')
            {   
                result += add;
                add++;
                *quiz++;
            }
            else if(*quiz == 'X')
            {
                add = 1;
                *quiz++;
            }

            else if(*quiz == '\0')
            {
                printf("%d\n", result);
                result = 0;
                add = 1;
                temp++;
                break;
            }
            
        }

        if(temp == len)
        {
            break;
        }
    }
}