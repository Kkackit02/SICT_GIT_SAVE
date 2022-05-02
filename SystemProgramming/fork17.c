#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void fork17()
{
    if(fork() == 0)
    {
        printf("Child1 : pid = %d , gpid = %d \n" , getpid() , getpgrp());
        while(1)
        {
            
        }

    }
    else
    {
       printf("Parent : pid = %d , gpid = %d \n" , getpid() , getpgrp());
       while(1)
       {

       }
    }

}

int main(void)
{
    fork17();
    return 0;
}