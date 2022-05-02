#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int loop_fork() // 실행  시 셀프 디도스 ATTACK
{
   while(1)
   {
       fork(); 
       
   }
}

int main(void)
{
    loop_fork();
    return 0;
}
