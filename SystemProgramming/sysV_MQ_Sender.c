#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define N 10
#define MAX_ID 5





int main(void)
{
    key_t ipckey;
    int mqdes , i;
    size_t buf_len;

    struct
    {
        long id; // 필수 (양수만 가능)
        int value; // 데이터 타입 상관 없음.
    } mymsg;

    buf_len = sizeof(mymsg.value);

    ipckey = ftok("./" , 1946);

    mqdes = msgget(ipckey, IPC_CREAT | 0600);
    if(mqdes < 0)
    {
        perror("msgget()");
        exit(0);
    }

    for(int i = 0; i<= MAX_ID; i++)
    {
        mymsg.id = i+1;
        mymsg.value = i*3;
        printf("Sending a message (val: %d, id: %ld) \n" , mymsg.value , mymsg.id);

        if(msgsnd(mqdes,  &mymsg , buf_len , 0) == -1)
        {
            perror("msgsnd()");
            exit(0);
        }
    }

    return 0;
}