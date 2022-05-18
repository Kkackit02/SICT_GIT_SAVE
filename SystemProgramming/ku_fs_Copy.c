#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include "sample.h"
#include <time.h>

void sendqueue(int location[], int pid, int indexcnt)
{
    key_t ipckey;
    int mqdes, i;
    size_t buf_len;
    struct {
        long id;
        int value[indexcnt];
        //int indexcnt; //한 child 당 읽을 문자열 개수를 배열 크기로 설정
    } mymsg;

    buf_len = sizeof(mymsg.value);

    ipckey = ftok("./", 1946);
    mqdes = msgget(ipckey, IPC_CREAT|0600);
    if(mqdes < 0){
        perror("msgget()");
        //exit(0);
    }
    //mymsg.indexcnt = indexcnt;
    mymsg.id = pid;
    for(int i = 0 ;i <indexcnt; i++){
        mymsg.value[i] = location[i];
        
    }
    if(msgsnd(mqdes, &mymsg, buf_len, 0 ) == -1)
    {
        perror("msgsnd()");
        //exit(0);
    }
    else
    {
        printf("%d send success\n " , getpid());
    }
}

int recievequeue()
{
    printf("recieved");
    key_t ipckey;
    int mqdes, i;
    size_t buf_len;
    struct {
        long id;
        int value[6];
        int indexnum; //한 child 당 읽을 문자열 개수를 배열 크기로 설정
    } mymsg;

    buf_len = sizeof(mymsg.value);

    ipckey = ftok("./", 1946);
    mqdes = msgget(ipckey, IPC_CREAT|0600);
    if(mqdes < 0){
        perror("msgget()");
        //exit(0);
    }
    
    if(msgrcv(mqdes, &mymsg, buf_len, 0,0) ==-1)
    {
        perror("msgrcv()");
        //exit(0);
        return 0;
    }
    else{
        printf("received message");
        for(int i = 0 ;i <mymsg.indexnum; i++)
        {
            printf("msg value:%d\n", mymsg.value[i]);
        }
        printf("received message(id: %ld)\n", mymsg.id);
        return 1;
    }
}
void search(char str[], char pattern[], int process_num)
{   
    int indexcnt = 0;
    printf("배열 받음\n");
	int i = 0, i2 = 0, pattern_index = 0;
    int location[MAXS];

	printf(" 일치점 : ");
	while (i < strlen(str) - strlen(pattern) + 1)
	{
		while (str[i2] == pattern[pattern_index] && pattern_index < strlen(pattern))
		{
			i2++; pattern_index++;
		}
		if (pattern_index > strlen(pattern) - 1)
        {
			printf("index: %d, i2: %d\n", i, i2);
            location[indexcnt]= i;
            indexcnt++;
        }
		pattern_index = 0;
		i2 = ++i;
	}
    /*for(int j = 0;j <indexcnt;j++)
    {
        printf("location[%d]: %d\n", j, location[j]);
    }*/
    sendqueue(location, getpid(), indexcnt);
}
void fork1(int cnt, int process_num, char pattern[])
{
    pid_t pid = fork();

    if(pid != 0){
        cnt++;
        printf("cnt: %d\n", cnt);
        if(cnt < process_num){
            fork1(cnt, process_num,pattern);
        }
    }
    else { //child process
        sleep(1);
        //search가 돌아갈 자리
        //arr separate
        /*double sublen = (double)MAXS/process_num;

        int res = ((int)sublen+1)*process_num - MAXS;
        //res * (int)sublen + process_num-res*((int)sublen+1) =MAXS
        //separate
        char subarr[(int)sublen+1];
        for(int i = 0; i< subarr)
        */
        printf("get===Pid: %d\n", getpid());
        search(input, pattern,process_num);
    }

}

int isint(double num) //정수 판별하는 함수
{
    if((num - (int)num) == 0) //정수인 경우
    {
        return 0;
    }
    else
        return 1;
}
/*void separate(int process_num)
{
        int res = ((int)sublen+1)*process_num - MAXS;

        return res; //res번 만큼 문자열(int)sublen 개 
        //process_num - res 만큼 문자열(int)sublen+1개
        /*
        for(int i = 0; i < a; i ++)
        {
            return (int)sublen
        }
        for(int i = a; i <process_num;i++)
        {
            //(int)sublen+1만큼 문자열 가져가기. 
        }
}*/
int main(int argc, char* argv[])
{
    //입력된 pattern 
   // int patternlen = strlen(argv[1]);
    //char pattern[patternlen];
    //strcpy(pattern, argv[1]);
    char pattern[] = "ABE";
    //printf("pattern: %s\n", pattern); //pattern 입력 확인
    
    int process_num = atoi(argv[2]);
    process_num = 3;
    int cnt = 0;
    fork1(cnt, process_num, pattern);

    int rcvquenum = 0; //받은 큐 개수
    while(1)
    {
        printf("while");
        //que 감시
        if(recievequeue() == 1) //get 성공하면 1 리턴
        {
            rcvquenum++;
        }
        //들어오면 바로 출력하기
        //들어온 큐 개수 비교
        if(rcvquenum == process_num)
            break;
    }
}