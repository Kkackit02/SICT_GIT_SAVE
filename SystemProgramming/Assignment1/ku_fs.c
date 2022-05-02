#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include"ku_fs_input.h"


void Finding_Patten(char input_String[MAXS] , char subString[MAXS], int len_subString, int startIdx , int endIdx);


/*
 * 해야할 것 
 * 1. 프로세스별 할당량 제대로 나눠졌는지 확인 
 * 2. fork로 자식 프로세스 작동
 * 3. 부모에서 wait 받아주기
 * 4. 메시지 큐 전송(자식들이 부모에게)
 * 5. 메시지 큐 받기(부모가)
 * 6. 메시지 큐로 모든 결과 받아서 정렬하기
 * 7. 출력해보기
 */

int main(int argc, char **argv )
{
	char subString[MAXS] = "";
	char numberOfProcess_String[99] = "";
	int numberOfProcess = 0;
	int inputLen = 0;
	int subStringLen = 0;

	int resultArray[MAXS];

	if(argc >1)
	{
		strcpy(subString, argv[1]);
		strcpy(numberOfProcess_String , argv[2]);
	}

	numberOfProcess = atoi(numberOfProcess_String);

	inputLen = strlen(input);
	subStringLen = strlen(subString);
	
	printf("subString Len : %d\n" , subStringLen);
	printf("%s\n" , subString);
	printf("Process of Number is : %d\n", numberOfProcess); 
	printf("%s \n", input);

	int RemainingQuota = inputLen;
	int ProcessQuota = inputLen / numberOfProcess;
	int AppointedIndex = 0;



	if(RemainingQuota - ProcessQuota < 0)
	{
		//프로세스 하나 생성
		//ProcessQuota 만큼 할당해서 찾게 하기
		//Finding_Patten(input,subString, subStringLen , AppointedIndex, AppointedIndex+ProcessQuota);
		//AppointedIndex = AppointedIndex+processQuota;
	}
	else
	{
		//프로세스 하나 생성
		//RemaningQuota 만큼 할당해서 찾게 하기	
		//Finding_Patten(input,subString, subStringLen , AppointedIndex, AppointedIndex+ProcessQuota);
		//AppointedIndex = AppointedIndex+RemainingQuota;
	}


	//Finding_Patten(input, subString , subStringLen , 0, inputLen);	
	return 0;
}


void Finding_Patten(char input_String[MAXS] , char subString[MAXS], int len_subString, int startIdx , int endIdx)
{
	int sameCount = 0;
	int pattenIdx = -1; 
	if(startIdx >= (len_subString - 1))
	{
		startIdx = startIdx - (len_subString-1);
	}
	
	for(int i = startIdx; i < endIdx; i++)
	{
		if(input_String[i] == subString[sameCount]) //Compare input and elements of subString 
		{
			sameCount++; // if equal, change to next elements of substring
			if(pattenIdx == -1) //store starting idx of Patten , and maintain idx
			{
				pattenIdx = i;
			}
			
			if(sameCount >= len_subString)
			{
				printf("%d\n", pattenIdx);
				// 메시지 큐를 여기서 보내면 될 듯?
				pattenIdx = -1;
				sameCount = 0;
			}

		}
		else
		{
			pattenIdx = -1;
			sameCount = 0;
		}
	}
	
}



