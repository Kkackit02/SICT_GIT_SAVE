#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void fork9()
{
    int child_status;

    pid_t pid = fork();

    if(pid == 0)
    {
        printf("HC : hello from Child : %d \n", getpid());
    }
    else
    {
        printf("HP : hello from parent : %d \n", getpid());
        wait(&child_status);
        printf("CT : child has terminated\n");
    }
    printf("Bye: %d \n", getpid());
    exit(0);
}


int main(void)
{
    fork9();
    return 0;
}