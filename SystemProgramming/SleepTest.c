#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void sig_Handler()
{
    printf("signal handler started \n");
    sleep(10);
}

int main(void)
{
    signal(SIGALRM,sig_Handler);

    printf("signal handler for SIGALRM registered ... \n");

    kill(getpid() , SIGALRM);

    printf("DONE\n");

    return 0;

}