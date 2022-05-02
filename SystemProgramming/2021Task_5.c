#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    if(fork() == 0)
    {
        if(fork() == 0)
        {
            printf("3");
        }
         else
        {
            pid_t pid; int status;
            if((pid = wait(&status)) > 0)
            {
                printf("4");
            }
        }
    }
    else
    {
        printf("2"); 
        exit(0);
    }
   

   

    printf("0"); 
    return 0;
}