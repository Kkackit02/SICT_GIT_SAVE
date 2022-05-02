#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 10

void fork10()
{

    pid_t pid[N];
    
    int i, child_status;

    for (i =0; i< N; i++)
    {
        if((pid[i] = fork()) == 0)
        exit(100 + i); // child
    }
    
    //wait vs waitpid ->
    for (i = 0; i < N; i++)
    {
        pid_t wpid = waitpid(pid[i] , &child_status , 0);
        
        //원하는 자식을 순서대로 reaping 할 수 있음.

        if(WIFEXITED(child_status))
        {
            printf("Child %d terminated with exit status %d : pgid : %d \n" 
            , wpid, WEXITSTATUS(child_status) , getpgrp());
        }
        else
        {
            printf("Child %d terminate abnormally\n" , wpid);
        }
    }
    
}


int main(void)
{
    
    fork10();
    
    return 0;
}