#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void do_it()
{
    fork();
    fork();
    printf("hello\n");
    return;
}

int main(void)
{
    do_it();
    printf("hello\n");
    exit(0);
}