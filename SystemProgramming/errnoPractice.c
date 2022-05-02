#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    pid_t rpid = fork();

    if(rpid < 0)
    {
        perror("Fork failed:");
        return -1;
    }
    else if (rpid == 0)
    {
        printf("Child\n");
    }
    else
    {
        printf("Parent\n");
    }

}