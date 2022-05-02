#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int counter = 0;
void do_Something()
{

}

int main(void)
{
    pid_t child;
    child = fork();

    if(child>0)
    {
        while(1)
        {
            do_Something();
            counter++;
            printf("counter 1 : %d\n" , counter);
        }
    }

    else if(child == 0)
    {
        while(1)
        {
            do_Something();
            counter--;
            printf("counter 2 : %d\n" , counter);
        }
    }

    return 0;
}