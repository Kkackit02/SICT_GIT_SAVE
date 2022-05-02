#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void SIGCONT_Handler()
{
    kill(getgid(), SIGCONT);
}

int main(void)
{
    signal(SIGCONT,SIGCONT_Handler);

    printf("pidL %d\n" , getpid());

    pause();
    printf("pause() returned\n");
    
    printf("근녕이 파이팅!");

    return 0;

}