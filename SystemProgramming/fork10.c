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
    
    
    for (i = 0; i < N; i++)
    {
        pid_t wpid = wait(&child_status);
        printf("%d\n" , child_status);
        if(WIFEXITED(child_status))
        {
            printf("Child %d terminated with exit status %d\n" 
            , wpid, WEXITSTATUS(child_status));
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