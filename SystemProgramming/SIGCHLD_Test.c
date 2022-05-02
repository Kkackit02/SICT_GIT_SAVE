#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include<errno.h>

pid_t job[10];

struct LinkedList 
{
    struct LinkedList* head;
    pid_t pid;
};



void addjob(pid_t pid)
{
    for(int i = 0; i< 10; i++)
    {
        
    }
}

void handler(int sig)
{
    int olderrno = errno;
    pid_t pid;

    while((pid = waitpid(-1 , NULL , 0)) > 0)
    {
        deletejob(pid);
    }
    if(errno != ECHILD)
    {
        sio_error("waitpid error");
        
    }
    errno = olderrno;
}

int main(int argc , char **argv)
{
    pid_t pid;
    signal(SIGCHLD, handler);
    initjobs();

    while(1)
    {
        if(((pid = fork()) == 0))
        {
            execve("/bin/date" , argv , NULL);
        }
    }
    addjob(pid);
    return 0;

}