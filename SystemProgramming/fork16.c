#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void fork16()
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
        if(fork() == 0)
        {
            printf("Child2 : pid = %d , gpid = %d \n" , getpid() , getpgrp());
            while(1)
            {

            }
        }
        else
        {
            exit(0);
        }
    }

}

int main(void)
{
    fork16();
    return 0;
}