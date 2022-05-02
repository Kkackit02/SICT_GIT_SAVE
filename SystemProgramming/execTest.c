#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    if (fork() == 0)
    {
        //execl("fork0" , "cp", "foo", "bar", NULL);
        execl("fork0" , "cp", "foo", "bar", NULL);
    }

    wait(NULL);
    printf("copy completed\n");
    exit(0);
}