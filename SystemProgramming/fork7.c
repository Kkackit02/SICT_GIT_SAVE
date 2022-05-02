#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fork7()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Terminating Child, PID = %d\n", getpid());
        exit(0);
    }
    else if(pid < 0)
    {
        perror("Error!");
        return -1;
    }
    else
    {
        printf("Running Parent, PID = %d\n" , getpid());
        while(1)
        {
            /* infinite loop */
        }
    }
}

int main(void)
{
    fork7();
    return 0;
}
