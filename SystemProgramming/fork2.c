#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fork2()
{
    printf("L0 %d \n" , getpid());
    fork();
    printf("L1 %d \n" , getpid());
    fork();
    printf("L2 %d \n" , getpid());
    
}
int main(void)
{
    fork2();
    return 0;
}
