#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 10

void fork12()
{
   pid_t pid[N];
   int i = 0 , child_status;

   for(i = 0; i< N; i++)
   {
       if((pid[i] = fork()) == 0)
       {
           while(1)
           {
               
           }
       }
   }

   for(i = 0; i < N; i++)
   {
       printf("Killing process %d\n", pid[i]);
       kill(pid[i], SIGINT);
   }

   //parent reaps terminated children
   for(i = 0; i< N; i++)
   {
       pid_t wpid = wait(&child_status);
       printf("%d\n" , WIFEXITED(child_status));
       if(WIFEXITED(child_status))
       {
           printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
           // exit() 이나 return으로 종료된 경우
       }
       else
       {
           printf("Child %d terminated abnormally\n" , wpid);
           // 그 외 시그널 같은 것으로 종료된 경우
       }
   }
}

int main(void)
{
    fork12();
    return 0;
}