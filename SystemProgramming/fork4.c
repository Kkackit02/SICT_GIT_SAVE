#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fork4()
{
    printf("L0 %d \n" , getpid());
    if(fork() != 0) // 자식은 바로 종료
    {
        printf("L1 %d \n" , getpid());
        if(fork() != 0) // 자식은 바로 종료
        {
            printf("L2 %d \n" , getpid());
            fork(); 
        }
    }
    printf("Bye %d \n" , getpid());
}

int main(void)
{
    fork4();
    return 0;
}
