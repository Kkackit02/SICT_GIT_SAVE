#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



void cleanup(void)
{
    printf("cleaning up %d \n", getpid());
}

int fork6()
{
    atexit(cleanup);
    fork();
    exit(0);
}


int main(void)
{
    fork6();
    return 0;
}
