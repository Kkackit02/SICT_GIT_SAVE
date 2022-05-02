#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fork8()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Running Child, PID = %d\n", getpid());
        while(1)
        {
            //infinity loop
        }
    }
    else if(pid < 0)
    {
        perror("Error!");
        return -1;
    }
    else
    {
        printf("Terminating Parent, PID = %d\n", getpid());
        exit(0);
    }
}

int main(void)
{
    fork8();
    return 0;
}
