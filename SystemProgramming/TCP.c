#include <stdio.h> //pritf
#include <sys/types.h> //socket
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPROTO_TCP
#include <stdlib.h> //exit()
#include <string.h> //memset
#include <arpa/inet.h> //inet_addr()

typedef struct msg {
	short	cnt;
	short	oper1;
	short	oper2;
	char	op;
	char	unuse;
}MSG;

typedef struct ans {
	int	sum;
}ANSWER;

int main()
{
	while(1){
		printf("Client send : \n");
		//fgets(data, sizeof(data), stdin);
		//data[strlen(data)-1] = '\0';

	/*
		message.cnt = 2;
		message.oper1= 23;
		message.oper2= 35;
		message.op = '+';
		message.unuse = 0;
	*/
		fflush(stdin);
		printf("message.cnt = ");
		//fgets 는 char형 밖에 못받음
		char buf[100];
		fflush(stdin);
		fgets(buf, sizeof(buf), stdin);
		fflush(stdin);
		//message.cnt = (short)atoi(buf);
		printf("message.oper1 = ");
		fgets(buf, sizeof(buf), stdin);
		fflush(stdin);
		//message.oper1 = (short)atoi(buf);
		printf("message.oper2 = ");
		fgets(buf, sizeof(buf), stdin);
		fflush(stdin);
		//message.oper2 = (short)atoi(buf);
		//char -> int -> short
		printf("message.op = ");
		fflush(stdin);
		fgets(buf, sizeof(buf), stdin);
		fflush(stdin);
		//printf("..%c", message.op);


        /*
		//n = send(sock_cli, data, strlen(data), 0);
		n = send(sock_cli, &message, sizeof(message), 0);
		if(n != sizeof(message)){
			perror("send error");
			exit(1);
		}
		//printf("send success\n");
			
		memset(&result, 0, sizeof(result));
		n = recv(sock_cli, &result, sizeof(result), 0);
		if (n == -1){
			perror("server recv error");
		}
        */
		printf("Client Recv : %d \n\n", 2);
	}


	printf("\nKunkook Univ. 202112497 Kim Jeongwoo\n");

	return 0;
}